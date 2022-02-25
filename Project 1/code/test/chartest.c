#include "../userprog/syscall.h"

int main() { 
  PrintChar(ReadChar());
  Halt();
}