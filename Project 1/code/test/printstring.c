#include "../userprog/syscall.h"

#define MAX_STR_LEN 255
int main()
{
    char str[255];

    PrintString("Enter a string: ");
    ReadString(str, 3);                 //TODO: Add ReadNum
    PrintString("String entered: ");
    PrintString(str);

    Halt();
}