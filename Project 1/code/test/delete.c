#include "../userprog/syscall.h"

int main()
{
    int namesize;
    char source[MAX_STR_LEN];

    PrintString("\n[DELETE FILE]",15);
    PrintString("\n> Enter file's name: ",23);
    namesize = ReadNum();

    PrintString("\n> Enter file name: ",21);
    ReadString(source, namesize);

    if (Remove(source))
    {
        PrintString("=> Deleted successfully!", 25);
    }
    else
        PrintString("=> Deleted unsuccessfully!", 29);

    Halt();
}