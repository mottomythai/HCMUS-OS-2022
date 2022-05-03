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

void SysPrintString(const char *buff, int len)
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

char SysReadChar()
{
  return kernel->synchConsoleIn->GetChar();
}

void SysPrintChar(char character)
{
  kernel->synchConsoleOut->PutChar(character);
}

#define max_num_length 11
// include minus sign
// int32 range: -2,147,483,648 to 2,147,483,647
#define LF ((char)10)
#define CR ((char)13)
#define TAB ((char)9)
#define SPACE ((char)' ')

char num_buffer[max_num_length + 2];

char isBlank(char c)
{
  return c == LF || c == CR || c == TAB || c == SPACE;
}

bool compareNumVsString(int integer, const char *s)
{
  if (integer == 0)
    return strcmp(s, "0") == 0;

  int len = strlen(s);

  if (integer < 0 && s[0] != '-')
    return false;

  if (integer < 0)
    s++, --len, integer = -integer;

  while (integer > 0)
  {
    int digit = integer % 10;

    if (s[len - 1] - '0' != digit)
      return false;

    --len;
    integer /= 10;
  }

  return len == 0;
}

void SysPrintNum(int num)
{
  if (num == 0)
    return kernel->synchConsoleOut->PutChar('0'); // Input = 0 -> print 0

  if (num == INT32_MIN)
  { // If num is equal to INT32_MIN -> print -2147483648
    kernel->synchConsoleOut->PutChar('-');
    for (int i = 0; i < 10; ++i)
      kernel->synchConsoleOut->PutChar("2147483648"[i]);
    return;
  }

  if (num < 0)
  { // Solve when num is negative
    kernel->synchConsoleOut->PutChar('-');
    num = -num;
  }

  // Convert int num into num_buffer array
  int i = 0;
  while (num)
  {
    num_buffer[i++] = num % 10;
    num /= 10;
  }

  // Print out the saved characters in num_buffer array
  for (int j = i - 1; j >= 0; --j)
    kernel->synchConsoleOut->PutChar(num_buffer[j] + '0');
}

int SysReadNum()
{
  // Read input
  memset(num_buffer, 0, sizeof(num_buffer));
  char c = kernel->synchConsoleIn->GetChar();

  // Detected end of file
  if (c == EOF)
  {
    DEBUG(dbgSys, "(!) End of file");
    return INT32_MIN;
  }

  // Detected white-space
  if (isBlank(c))
  {
    DEBUG(dbgSys, "(!) White-space detected");
    return INT32_MIN;
  }

  int n = 0;

  while (!(isBlank(c) || c == EOF))
  {
    num_buffer[n++] = c;
    if (n > max_num_length)
    {
      DEBUG(dbgSys, "Number is too long");
      return INT32_MIN;
    }
    c = kernel->synchConsoleIn->GetChar();
  }

  int len = strlen(num_buffer);

  // Read nothing -> return 0
  if (len == 0)
    return 0;

  if (strcmp(num_buffer, "-2147483648") == 0)
    return INT32_MIN;

  bool neg = (num_buffer[0] == '-');
  int zeros = 0;
  bool is_leading = true;
  int num = 0;
  for (int i = neg; i < len; ++i)
  {
    char c = num_buffer[i];
    if (c == '0' && is_leading)
      ++zeros;
    else
      is_leading = false;
    if (c < '0' || c > '9')
    {
      DEBUG(dbgSys, "Number expected but " << num_buffer << " found");
      return 0;
    }
    num = num * 10 + (c - '0');
  }

  if (zeros > 1 || (zeros && (num || neg)))
  {
    DEBUG(dbgSys, "Number expected but " << num_buffer << " found");
    return 0;
  }

  if (neg)
    /* Reason we need to handle -2147483648 individually:
     * 2147483648 is larger than the range of int32 */
    num = -num;

  // If the number is small, return it
  if (len <= max_num_length - 2)
    return num;

  /* We need to make sure that number is equal to the number in the buffer.
   * It's impossible to tell whether the number is bigger
   * than INT32_MAX or smaller than INT32_MIN if it has the same length.
   *
   * For example: 4.000.000.000
   * In that case, that number will cause an overflow. However, C++ doesn't raise
   * integer overflow, so we need to make sure that the input
   * and the output is equal. */
  if (compareNumVsString(num, num_buffer))
    return num;
  else
    DEBUG(dbgSys, "Should be int32 number");

  return 0;
}

int SysRandomNum()
{
  srand(time(NULL));
  return rand();
}

int SysCreateFile(char* fileName)
{
  int is_created;
  int fileNameLength = strlen(fileName);

  // empty filename 
  if (fileNameLength == 0) {
    DEBUG(dbgSys, "\nFile name can't be empty");
    is_created = -1;
  } 
  
  // if can't read filename
  else if (fileName == NULL) {
    DEBUG(dbgSys, "\nNot enough memory in system");
    is_created = -1;
  } 
  
  //Create File by using fucntion Create of fileSystem
  else {
    if (!kernel->fileSystem->Create(fileName,0)) {
      // error creating file
      DEBUG(dbgSys, "\nError creating file");
      is_created = -1;
    } 
    else {
      // return 0 if succeed
      is_created = 0; 
    }
  }

  return is_created;
}

int SysOpen(char* fileName)
{
  int fileNameLength = strlen(fileName);

  if (fileNameLength == 0) {
    DEBUG(dbgSys, "\nFile name can't be empty");
    return -1;
  }

  else if (fileName == NULL) {
    DEBUG(dbgSys, "\nNot enough memory in system");
    return -1;
  }

  else {
    int openFileID = kernel->fileSystem->FindFreeSlot();

    if (openFileID == -1) {
      DEBUG(dbgSys, "\nThere are fullfill processes!");
      return -1;
    }

    else if ((kernel->fileSystem->openFile[openFileID] =
      kernel->fileSystem->Open(fileName)) != NULL) {
      kernel->fileSystem->openFileName[openFileID] = (fileName);
      DEBUG(dbgSys, "\nOpening file successfully");

      return openFileID;
    }

    else {
      DEBUG(dbgSys, "\nError opening file!");
      return -1;
    }
  }
}

int SysClose(int id) 
{ 
  return kernel->fileSystem->Close(id); 
}

int SysRead(char* buffer, int charCount, int fileId) 
{
  if (fileId == 0) {
    return kernel->synchConsoleIn->GetString(buffer, charCount);
  }
  return kernel->fileSystem->Read(buffer, charCount, fileId);
}

int SysWrite(char* buffer, int size, int fileid)
{
  if (fileid == 1)
  {
    return kernel->synchConsoleOut->PutString(buffer, size);
  }

  return kernel->fileSystem->Write(buffer, size, fileid);
}

int SysSeek(int position, int fileid)
{
  if (fileid <= 1)
  {
    DEBUG(dbgSys, "\nCannot seek in console!");
    return -1;
  }

  return kernel->fileSystem->Seek(position, fileid);
}

int SysRemove(char *name)
{
  return kernel->fileSystem->Remove(name);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
