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
#include "stdint.h"
#include <stdlib.h>

void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

/*
Input: - User space address (int)
- Limit of buffer (int)
Output:- Buffer (char*)
Purpose: Copy buffer from User memory space to System memory space
*/
char *User2System(int virtAddr, int limit)
{
  int i; // index
  int oneChar;
  char *kernelBuf = NULL;
  kernelBuf = new char[limit + 1]; // need for terminal string
  if (kernelBuf == NULL)
    return kernelBuf;
  memset(kernelBuf, 0, limit + 1);
  // printf("\n Filename u2s:");
  for (i = 0; i < limit; i++)
  {
    kernel->machine->ReadMem(virtAddr + i, 1, &oneChar);
    kernelBuf[i] = (char)oneChar;
    // printf("%c",kernelBuf[i]);
    if (oneChar == 0)
      break;
  }
  return kernelBuf;
}

/*
Input: - User space address (int)
- Limit of buffer (int)
- Buffer (char[])
Output:- Number of bytes copied (int)
Purpose: Copy buffer from System memory space to User memory space
*/
int System2User(int virtAddr, int len, char *buffer)
{
  if (len < 0)
    return -1;
  if (len == 0)
    return len;
  int i = 0;
  int oneChar = 0;
  do
  {
    oneChar = (int)buffer[i];
    kernel->machine->WriteMem(virtAddr + i, 1, oneChar);
    i++;
  } while (i < len && oneChar != 0);
  return i;
}

int *SysSort(int virAddr, int size)
{
  DEBUG(dbgSys, "Enter SysSort:")
  if (size <= 0)
    return NULL;
  int *arr = new int[size];
  for (int i = 0; i < size; i++)
  {
    DEBUG(dbgSys, i);
    int num = 0;
    kernel->machine->ReadMem(virAddr + i, 4, &num);
    DEBUG(dbgSys, "a[" << i << "] = " << num);
    arr[i] = num;
  }

  for (int i = 0; i < size; i++)
    for (int j = i; j + 1 < size; j++)
      if (arr[i] < arr[j])
      {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
  // TODO: Skip sorted

  return arr;
}

int IntArrSys2User(int virAddr, int len, int *arr)
{
  if (len < 0)
    return -1;
  if (len == 0)
    return len;
  int i = 0;
  int num = 0;
  do
  {
    num = arr[i];
    kernel->machine->WriteMem(virAddr + i, 4, num);
    i++;
  } while (i < len);
  return i;
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

void SysPrintChar(char character)
{
  kernel->synchConsoleOut->PutChar(character);
}

#define max_num_length 11
//include minus sign 
//int32 range: -2,147,483,648 to 2,147,483,647

char num_buffer[max_num_length+2];

void SysPrintNum(int num) {
    if (num == 0) return kernel->synchConsoleOut->PutChar('0');//neu = 0 thi in ra 0

    if (num == INT32_MIN) {//neu la so hang duoi thi in ra so hang duoi = 2147483648
        kernel->synchConsoleOut->PutChar('-');
        for (int i = 0; i < 10; ++i)
            kernel->synchConsoleOut->PutChar("2147483648"[i]);
        return;
    }

    if (num < 0) { // neu la so am
        kernel->synchConsoleOut->PutChar('-');
        num = -num;
    }
    //chuyen so nguyen ve chuoi va in ra
    int n = 0;
    while (num) {
        num_buffer[n++] = num % 10;
        num /= 10;
    }
    for (int i = n - 1; i >= 0; --i)
        kernel->synchConsoleOut->PutChar(num_buffer[i] + '0');
}

int SysRandomNum() {
  srand(time(NULL));
  return rand();
}


#endif /* ! __USERPROG_KSYSCALL_H__ */
