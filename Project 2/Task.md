#Tasks

To-Do   |Doing  |Finished
--      |--     |--      
**Syscall**|**Syscall**|**Syscall**
Create      |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[]</li></ul>
Open        |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[]</li></ul>
Close       |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[]</li></ul>
Read        |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[]</li></ul>
Write       |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Seek        |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Remove      |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
**Userprog**|**Userprog**|**Userprog**
Createfile  |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[]</li></ul>
Cat         |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Copy        |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Delete      |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Concatenate |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>

##Lưu ý

- Nếu muốn nhận làm hàm nào thì điền tên vào cột `Doing` tương ứng của hàng đó, khi xong thì nhớ điền vào cột `Finished` (Không cần xóa tên bên cột `Doing`)
- Làm và đánh dấu từng hàm, đừng ôm nhiều, để người khác làm với 👉👈
- Nên làm những hàm bên trong Syscall trước vì các hàm Userprog sẽ cần các hàm Syscall

##Instruction:

Userprog|Syscall
--|--
Createfile|<p>Create</p>
Cat|<p>Open</p><p>Read</p><p>Close</p>
Copy|<p>Open</p><p>Read</p><p>Create</p><p>Write</p><p>Close</p>
Delete|<p>Remove</p>
Concatenate|<p>Open</p><p>Read</p><p>Close</p>
