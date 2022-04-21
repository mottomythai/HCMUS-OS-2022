#include "../userprog/syscall.h"

int main()
{
    char buff1[MAX_STR_LEN], buff2[MAX_STR_LEN], filename1[MAX_STR_LEN], filename2[MAX_STR_LEN];
    int namesize;
    OpenFileId file1;
    OpenFileId file2;

    PrintString("Enter first file\'s name size: ", 31);
    namesize = ReadNum();
    PrintString("Enter first file name: ", 25);
    ReadString(filename1, namesize);
    ReadNum();

    PrintString("Enter second file\'s name size: ", 32);
    namesize = ReadNum();
    PrintString("Enter second file name: ", 25);
    ReadString(filename2, namesize);
    ReadNum();
    
    file1 = Open(filename1);
    file2 = Open(filename2);
    if (file1 == -1 || file2 == -1)
    {
        PrintString("Unable to open file(s)", 23);
        Halt();
    }
    
    Read(buff1, MAX_STR_LEN, file1);
    Read(buff2, MAX_STR_LEN, file2);
    PrintString(buff1, MAX_STR_LEN);
    PrintString(buff2, MAX_STR_LEN);
    PrintChar('\n');
    Close(file1);
    Close(file2);

    Halt();
}