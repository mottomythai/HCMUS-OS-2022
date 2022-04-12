#include "../userprog/syscall.h"

int main()
{
    char* msg = "ABOUT:\n- TEAM: Lieu Gia Hao 20127492; To Duy Thai 20127626; Nguyen Thi Phuong Trang 20127650\n- SORT: Nhap mang N so nguyen va chuong trinh se xuat ra mang hinh mang da nhap\n- ASCII: Chuong trinh se in ra cac ky tu co the in tu ban phim\n";
    PrintString(msg, 226);

    Halt();
}