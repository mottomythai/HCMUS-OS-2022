#include "../userprog/syscall.h"

int main()
{
    char content[MAX_STR_LEN];
    char fileName[MAX_STR_LEN];
    int n;
    OpenFileId fileid;

    PrintString("Enter length of filename: ",26);
    n = ReadNum();
    PrintString("Enter filename: ",16);
    ReadString(fileName, n);

    fileid = Open(fileName);
    if (fileid == -1)
        PrintString("=> Error opening file!\n", 24);
    else 
    {
        Read(content, MAX_STR_LEN, fileid);

	    PrintString("=> File's content:\n",20);
        PrintString(content, MAX_STR_LEN);
	    PrintChar('\n');
        Close(fileid);
    }

    Halt();
}