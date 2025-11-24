# Bài tập 2: Thay thế Mã thực thi và Tương tác với Môi trường

## Mục tiêu

Tìm hiểu cách một tiến trình có thể thay thế hoàn toàn mã lệnh đang chạy của nó
bằng một chương trình khác và cách truyền thông tin qua biến môi trường.

## Yêu cầu

- Viết chương trình mà **tiến trình cha** thiết lập một biến môi trường  
  (ví dụ: `MY_COMMAND=ls`).

- **Tiến trình con** sẽ đọc biến môi trường này.  
  Dựa vào giá trị đọc được, nó sẽ dùng **họ hàm `exec()`**  
  (ví dụ `execlp()`) để thực thi lệnh tương ứng (`ls`, `date`, ...).

- Trong báo cáo, giải thích:  
  > Điều gì xảy ra với không gian địa chỉ và mã lệnh của tiến trình con  
  > sau khi `exec()` được gọi thành công?

<br>

# Giải thích: Điều gì xảy ra sau khi `exec()` được gọi thành công?

Khi một hàm trong họ `exec()` thực thi thành công:

- **Không gian địa chỉ của tiến trình con sẽ bị xóa hoàn toàn.**  
  Điều này bao gồm:
  - Mã lệnh (*text segment*)
  - Dữ liệu (*data segment*)
  - Vùng nhớ **heap**
  - Vùng nhớ **stack**

- Tất cả được **thay bằng nội dung của chương trình mới**, được nạp từ file thực thi mà hàm `exec()` chỉ định.

- **PID của tiến trình không thay đổi**, vì tiến trình cũ không kết thúc mà chỉ thay đổi nội dung.

---

Nói cách khác:

> 👉 Sau `exec()`, tiến trình con vẫn là tiến trình cũ, nhưng chạy như một chương trình hoàn toàn mới.
