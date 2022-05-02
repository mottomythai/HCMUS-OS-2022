#include "../userprog/syscall.h"

int main()
{
    int A[100];
    int i, j, tmp, size;
    char order;

    PrintString("Enter the array\'s size: ", 25);
    size = ReadNum();

    if (size <= 0)
    {
        PrintString("Illegal value detected, stoping program\n", 41);
        Halt();
    }

    PrintString("Enter the array:\n", 18);
    for (i = 0; i < size; i++)
    {
        A[i] = ReadNum();
    }

    PrintString("Sort in an ascending or decending order?(A\\D) ", 47);
    order = ReadChar();

    for (j = 0; j < size; j++)
        for (i = 0; i < size - 1; i++)
        {
            if (order == 'a' || order == 'A')
            {
                if ((A[i] > A[i + 1]))
                {
                    tmp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = tmp;
                }
            }
            else if ((A[i] < A[i + 1]))
            {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
            }
        }

    PrintString("Finished array: ", 17);
    for (i = 0; i < size; ++i)
    {
        PrintNum(A[i]);
        PrintChar(' ');
    }

    Halt();
}
