#include "../userprog/syscall.h"

int main()
{
  char a;

  PrintString("Enter a charecter: ", 20);
  a = ReadChar();
  PrintString("Entered charecter: ", 20);
  PrintChar(a);
  PrintChar('\n');

  Halt();
}