#include "../userprog/syscall.h"

#define MAX_STR_LEN 255
int main()
{
    char str[255];

    PrintString("Enter a string: ", 17);
    ReadString(str, 3);                     //TODO: Add ReadNum
    PrintString("String entered: ", 17);    //FIXME: String longer than expected, might be spaces after the \0
    PrintString(str, 3);

    Halt();
}