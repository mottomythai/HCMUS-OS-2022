#include "../userprog/syscall.h"

int main()
{
   	char fileName[256];
    int n;

    PrintString("Enter length of filename: ",26);
    n = ReadNum();
    PrintString("Enter file's name: ",50);
    ReadString(fileName, n);

    if (CreateFile(fileName) == 0) {
        PrintString("=> File ",8);
        PrintString(fileName,n);
        PrintString(" successfully created!\n",23);
    } 
	else
        PrintString(" can't be created!\n",23);

	Halt();
}

