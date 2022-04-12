#Tasks

To-Do   |Doing  |Finished
--      |--     |--      
**Syscall**|**Syscall**|**Syscall**
Create      |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[x]</li></ul>
Open        |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[x]</li></ul>
Close       |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[x]</li></ul>
Read        |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[x]</li></ul>
Write       |<ul><li>[ ] Hạo</li><li>[x] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Seek        |<ul><li>[ ] Hạo</li><li>[x] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Remove      |<ul><li>[ ] Hạo</li><li>[x] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
**Userprog**|**Userprog**|**Userprog**
Createfile  |<ul><li>[ ] Hạo</li><li>[ ] Thái</li><li>[x] Trang</li></ul>|<ul><li>[x]</li></ul>
Cat         |<ul><li>[x] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Copy        |<ul><li>[ ] Hạo</li><li>[x] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Delete      |<ul><li>[x] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>
Concatenate |<ul><li>[x] Hạo</li><li>[ ] Thái</li><li>[ ] Trang</li></ul>|<ul><li>[ ]</li></ul>

##Lưu ý

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
