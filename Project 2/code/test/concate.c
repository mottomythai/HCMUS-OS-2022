#include "../userprog/syscall.h"

int main()
{
    char *buff1, *buff2, *filename1, *filename2;
    int size1, size2, namesize;
    PrintString("Enter first file's name size: ", 31);
    namesize = ReadNum();
    PrintString("Enter first file name: ", 24);
    ReadString(filename1, namesize);
    PrintString("Enter data length within file: ", 32);
    size1 = ReadNum();
    PrintString("Enter second file's name size: ", 31);
    namesize = ReadNum();
    PrintString("Enter second file name: ", 26);
    ReadString(filename2, namesize);
    PrintString("Enter data length within file: ", 32);
    size2 = ReadNum();
    OpenFileId file1 = Open(filename1);
    OpenFileId file2 = Open(filename2);
    if (file1 == -1 || file2 == -1)
    {
        PrintString("Unable to open file(s)", 23);
        Halt();
    }
    
    Read(buff1, size1, file1);
    Read(buff2, size2, file2);
    PrintString(buff1, size1);
    PrintString(buff2, size2);
    Close(file1);
    Close(file2);

    Halt();
}