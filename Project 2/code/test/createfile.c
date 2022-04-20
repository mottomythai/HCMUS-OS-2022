#include "../userprog/syscall.h"

int main()
{
   	char fileName[MAX_STR_LEN];
    int n;

    PrintString("Enter length of filename: ",26);
    n = ReadNum();
    PrintString("Enter filename: ",50);
    ReadString(fileName, n);

    if (CreateFile(fileName) == 0) {
        PrintString("=> File ",8);
        PrintString(fileName,n);
        PrintString(" successfully created!\n",23);
    } 
	else
        PrintString("Error creating file!\n",23);

	Halt();
}

