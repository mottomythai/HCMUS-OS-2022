#include "../userprog/syscall.h"

int main() {
    int result;
    result = RandomNum();
    PrintNum(result);
    Halt();
}