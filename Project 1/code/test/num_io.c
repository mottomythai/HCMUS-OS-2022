#include "../userprog/syscall.h"

int main()
{
    PrintNum(ReadNum());
    PrintChar('\n');
    return;
}