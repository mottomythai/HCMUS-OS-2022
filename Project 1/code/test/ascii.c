#include "../userprog/syscall.h"
int main() {
    int i;
    PrintString("Dec|Char\n", 12);
    for (i = 32; i <= 126; i++) {
        PrintNum(i);
        PrintChar('|');
        PrintChar((char)i);
        PrintChar('\n');
    }
    Halt();
}
