# PROJECT 1
*Việc Cần Làm*
- [x] Viết lại file exception.cc để xử lý tất cả các exceptions được liệt kê trong machine/machine.h
- [x] Viết mã để tăng gia trị biến program counter
- [x] Cài đặt system call int ReadNum()
- [x] Cài đặt system call void PrintNum(int number)
- [x] Cài đặt system call char ReadChar()
- [x] Cài đặt system call void PrintChar(char character)
- [x] Cài đặt system call int RandomNum()
- [x] Cài đặt đặt system call void ReadString (char[] buffer, int length)
- [x] Cài đặt system call void PrintString (char[] buffer)
- [x] Viết chương trình help, CT help dùng để in ra các dòng giới thiệu cơ bản về nhóm và mô tả vắn tắt về chương trình sort và ASCII
- [x] Viết chương trình ascii để in ra bảng mã ASCII
- [x] Viết chương trình sort với yêu cầu sau:
      
      ● Cho phép người dùng nhập vào một mảng n số nguyên với n là số do người dùng nhập vào (n <=100)
      ● Sử dụng thuật toán bubble sort để sắp xếp mảng trên theo chiều tăng dần hoặc giảm dần tuỳ vào người dùng lựa chọn.

# PROJECT 2

## Hàm *Systemcall*
- [ ] **Create(char\* *name*)**: Tạo một file rỗng ở vị trí nhập vào; Return `0` nếu thành công, `-1` nếu lỗi
- [ ] **Open(char\* *name*)**: Mở file, Return `OpenFileID`
- [ ] **Close(char\* *name*)**: Đóng file, Return `OpenFileID`
- [ ] **Read(char\* *buffer*, int *size*, OpenFileID *ID*)**: Đọc và lưu dữ liệu, kiểu string, ở buffer
- [ ] **Write(char\* *buffer*, int *size*, OpenFileID *ID*)**: Ghi dữ liệu, kiểu string, từ buffer vào file
- [ ] **Seek(int *position*, OpenFileID *ID*)**: Di chuyển con trỏ chuột đền vị trí global, -1 thì cuối file, Return `position` nếu thành công, `-1` nếu lỗi
- [ ] **Remove(char\* *name*)**: Xoá file được nhập tên
- [x] ***User2System* and *System2User***: sao chép vùng nhớ vào kernel-user (Đã làm ở phần Prj 1)

## Hàm *Userprog*
- [ ] **Createfile**: Tạo file hello.txt 
  >./nachos -x ../test/createfile hello.txt
- [ ] **Cat**: Hiển thị nội dung file hello.txt 
  >./nachos -x ../test/cat hello.txt
- [ ] **Copy**: Copy file a thành file b 
  >./nachos -x ../test/copy a.txt b.txt
- [ ] **Delete**: Xoá file file hello.c 
  >./nachos -x ../test/delete hello.c
- [ ] **Concatenate**: Nối nội dung file a và b và in ra  
  >./nachos -x ../test/concatenate a.txt b.txt

### Note:
- Sử dụng `main(int argc, char* argv[])` để thực hiện các hàm ***userprog***
- Kiểu `typedef int OpenFileID` trong syscall
- Hàm `Seek` nếu được gọi trên console thì báo lỗi
- Hàm `Remove` phải kiểm tra file tồn tại và có đang được mở
- Một số file header đã có sẵn và có thể hỗ trợ `code\filesys\`, đế ý cả các include header khác (Chỉ là mẫu có thể tham khảo, không thể sử dụng)
- Công việc sẽ được lưu ở file `Tasks.md`