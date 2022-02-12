#include "../userprog/syscall.h"

int main() { 
  // ReadChar();
  PrintChar(ReadChar());
  //DEBUG
  Halt();
  }