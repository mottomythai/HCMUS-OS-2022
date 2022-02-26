#include "../userprog/syscall.h"

#define MAX_STR_LEN 255
int main()
{
    char str[MAX_STR_LEN];
    int n;
    
    PrintString("Enter string's size: ", 22);
    n = ReadNum();
    PrintString("Enter a string: ", 17);
    ReadString(str, n);
    PrintString("String entered: ", 17);
    PrintString(str, n);
    PrintChar('\n');

    Halt();
}