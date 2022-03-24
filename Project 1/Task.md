# Tasks

To-Do   |Doing  |Finished
--      |--     |--      
**Syscall**|**Syscall**|**Syscall**
Create|<input type="checkbox">Hạo
Open|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Close|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Read|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Write|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Seek|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Remove|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
**Userprog**|**Userprog**|**Userprog**
Createfile|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Cat|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Copy|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Delete|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>
Concatenate|<ul><li><input type="checkbox">Hạo</li><li><input type="checkbox">Thái</li><li><input type="checkbox">Trang</li></ul>|<ul><li><input type="checkbox"></li></ul>

## Lưu ý

- Nếu muốn nhận làm hàm nào thì điền tên vào cột `Doing` tương ứng của hàng đó, khi xong thì nhớ điền vào cột `Finished` (Không cần xóa tên bên cột `Doing`)
- Làm và đánh dấu từng hàm, đừng ôm nhiều, để người khác làm với 👉👈
- Nên làm những hàm bên trong Syscall trước vì các hàm Userprog sẽ cần các hàm Syscall

## Instruction:

Userprog|Syscall
--|--
Createfile|<p>Create</p>
Cat|<p>Open</p><p>Read</p><p>Close</p>
Copy|<p>Open</p><p>Read</p><p>Create</p><p>Write</p><p>Close</p>
Delete|<p>Remove</p>
Concatenate|<p>Open</p><p>Read</p><p>Close</p>