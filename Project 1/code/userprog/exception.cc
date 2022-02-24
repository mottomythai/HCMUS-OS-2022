// exception.cc
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "synchconsole.h"
#include "syscall.h"
#include "ksyscall.h"
#include <stdlib.h>
//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2.
//
// If you are handling a system call, don't forget to increment the pc
// before returning. (Or else you'll loop making the same system call forever!)
//
//	"which" is the kind of exception.  The list of possible exceptions
//	is in machine.h.
//----------------------------------------------------------------------

/* Modify return point */
void increasePC()
{
	/* set previous programm counter (debugging only)*/
	kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));
	/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
	kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	/* set next programm counter for brach execution */
	kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg) + 4);
}

#define MAX_STR_LEN 255
void handleSC_ReadStr()
{
	int strAddress = kernel->machine->ReadRegister(4);
	int strLen = kernel->machine->ReadRegister(5);
	if (strLen >= MAX_STR_LEN)
	{
		// TODO: Rewrite this
		char errMsg[] = "String too long";
		SysPrintString(errMsg, strlen(errMsg));
		SysHalt();
		// END_TODO
	}

	char *str = SysReadString(strLen);

	System2User(strAddress, strlen(str), str);
	delete[] str;
	increasePC();
}

void handleSC_PrintStr()
{
	int strAddress = kernel->machine->ReadRegister(4);
	int strLimit = kernel->machine->ReadRegister(5);
	char *buff = User2System(strAddress, strLimit);

	DEBUG(dbgSys, "\n[DEBUG]: string '" << buff << "' has the length of " << strlen(buff) << "");
	SysPrintString(buff, strlen(buff));
	delete buff;
	increasePC();
}

void handle_SC_ReadChar()
{
	char result = SysReadChar();
	kernel->machine->WriteRegister(2, (int)result);
	increasePC();
}

void handle_SC_PrintChar()
{
	char character = (char)kernel->machine->ReadRegister(4);
	SysPrintChar(character);

	increasePC();
}

void handle_SC_Sort()
{
	DEBUG(dbgSys, "Enter Sorting:");
	int addr = kernel->machine->ReadRegister(4);
	int size = kernel->machine->ReadRegister(5);

	int *arr = SysSort(addr, size);

	DEBUG(dbgSys, "Sorting:");
	if(debug->IsEnabled(dbgSys))
	{
		for(int i = 0; i < size; ++i)
			DEBUG(dbgSys, arr[i])
	}
	IntArrSys2User(addr, size, arr);

	if(arr) delete[] arr;
	increasePC();
}

void handle_SC_PrintNum() {
    int character = kernel->machine->ReadRegister(4);
    SysPrintNum(character);
   	increasePC();
}

void handle_SC_RandomNum() {
    int result;
    result = SysRandomNum();
    kernel->machine->WriteRegister(2, result);
    increasePC();
}

void ExceptionHandler(ExceptionType which)
{
	int type = kernel->machine->ReadRegister(2);

	DEBUG(dbgSys, "Received Exception " << which << " type: " << type << "\n");

	switch (which)
	{
	case SyscallException:
		switch (type)
		{
		case SC_Halt:
			DEBUG(dbgSys, "Shutdown, initiated by user program.\n");

			SysHalt();

			ASSERTNOTREACHED();
			break;

		case SC_Add:
			DEBUG(dbgSys, "Add " << kernel->machine->ReadRegister(4) << " + " << kernel->machine->ReadRegister(5) << "\n");

			/* Process SysAdd Systemcall*/
			int result;
			result = SysAdd(/* int op1 */ (int)kernel->machine->ReadRegister(4),
							/* int op2 */ (int)kernel->machine->ReadRegister(5));

			DEBUG(dbgSys, "Add returning with " << result << "\n");
			/* Prepare Result */
			kernel->machine->WriteRegister(2, (int)result);

			increasePC();

			return;

			ASSERTNOTREACHED();

			break;

		case SC_ReadString:
			handleSC_ReadStr();
			return;
		case SC_PrintString:
			handleSC_PrintStr();
			return;
		case SC_ReadChar:
			handle_SC_ReadChar();
			return;
		case SC_PrintChar:
			handle_SC_PrintChar();
			return;
		case SC_PrintNum:
            handle_SC_PrintNum();
			return;
		case SC_RandomNum:
            handle_SC_RandomNum();
			return;
		case SC_Sort:
			handle_SC_Sort();
			return;
		default:
			cerr << "Unexpected system call " << type << "\n";
			break;
		}
		break;
	default:
		cerr << "Unexpected user mode exception " << (int)which << "\n";
		break;
	}
	ASSERTNOTREACHED();
}
