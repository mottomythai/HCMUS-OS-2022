/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"
#include "syscall.h"

void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}


char *str2sys(int addr, int len = -1)
{
  char *str;
  bool stop = false;

  if (len == -1)
    do
    {
      len++;
      int chr;
      kernel->machine->ReadMem(addr + len, 1, &chr);
      stop = (chr == '\0');
    } while (!stop);

  str = new char[len];
  for (int i = 0; i < len; ++i)
  {
    int chr;
    kernel->machine->ReadMem(addr + i, 1, &chr);
    str[i] = chr;
  }

  return str;
}

void str2user(char *str, int addr, int len = -1)
{
  len = (len == -1) ? strlen(str) : len;
  for (int i = 0; i < len; ++i)
  {
    kernel->machine->WriteMem(addr + i, 1, str[i]);
  }
  kernel->machine->WriteMem(addr + len, 1, '\0');
}

void SysPrintString(char *buff, int len)
{
  DEBUG(dbgSys, "String len of '" << buff << "' is the length of " << len << "");
  for (int i = 0; i < len; i++)
  {
    kernel->synchConsoleOut->PutChar(buff[i]);
  }
}

char *SysReadString(int len)
{
  char *str = new char[len + 1];
  for (int i = 0; i < len; ++i)
  {
    str[i] = kernel->synchConsoleIn->GetChar();
  }
  str[len] = '\0';
  return str;
}
char SysReadChar() { return kernel->synchConsoleIn->GetChar(); }

void SysPrintChar(char character) {
    kernel->synchConsoleOut->PutChar(character);
}


#endif /* ! __USERPROG_KSYSCALL_H__ */
