#include "../userprog/syscall.h"

int main()
{
    int a;

    PrintString("Enter a number: ", 17);
    a = ReadNum();
    PrintString("Entered number: ", 17);
    PrintNum(a);
    PrintChar('\n');
    
    Halt();
}