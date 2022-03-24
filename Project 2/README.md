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