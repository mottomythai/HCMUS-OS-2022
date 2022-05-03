#include "../userprog/syscall.h"

int main()
{
    int srcFileID;
    int destFileID;
    int namesize;
    int fsize, index;
    char c, source[MAX_STR_LEN], dest[MAX_STR_LEN];

    PrintString("\n[COPY FILE]", 13);
    PrintString("\n> Source file:\n", 18);
    PrintString("Enter Source file\'s name size: ", 31);
    namesize = ReadNum();
    PrintString("Enter Source filename: ", 25);
    ReadString(source, namesize);
    ReadNum();

    PrintString("\n> Destination file:\n", 22);
    PrintString("Enter Destination file\'s name size: ", 36);
    namesize = ReadNum();
    PrintString("Enter Destination filename: ", 28);
    ReadString(dest, namesize);
    ReadNum();

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

            PrintString("\n=> Copied successfully!\n\n", 27);
            Close(destFileID);
        }
        else
        {
            PrintString("\n=> Cannot create destination file!", 36);
        }
    }
    else
    {
        PrintString("\n=> Cannot open file!", 22);
    }

    Halt();
}