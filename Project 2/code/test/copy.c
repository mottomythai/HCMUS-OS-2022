#include "../userprog/syscall.h"
#define MAX_LENGTH 32

int main()
{
    int srcFileID;
    int destFileID;

    int fsize, index;
    char c, source[MAX_LENGTH], dest[MAX_LENGTH];

    PrintString("\n[COPY FILE]", 13);
    PrintString("\n> Source file: ", 17);
    ReadString(source, MAX_LENGTH);

    PrintString("\n> Destination file: ", 22);
    ReadString(dest, MAX_LENGTH);
    srcFileID = Open(source);

    if (srcFileID != 1)
    {
        destFileID = CreateFile(dest);
        Close(destFileID);

        destFileID = Open(dest);

        if (destFileID != -1)
        {
            fsize = Seek(-1, srcFileID);

            Seek(0, srcFileID);
            Seek(0, destFileID);

            for (index = 0; index < fsize; ++index)
            {
                Read(&c, 1, srcFileID);
                Write(&c, 1, destFileID);
            }

            PrintString("\nCopied successfully!\n\n", 24);
            Close(destFileID);
        }
        else
        {
            PrintString("\nCannot create destination file!", 33);
        }
    }
    else
    {
        PrintString("\nCannot open file!", 19);
    }

    return 0;
}