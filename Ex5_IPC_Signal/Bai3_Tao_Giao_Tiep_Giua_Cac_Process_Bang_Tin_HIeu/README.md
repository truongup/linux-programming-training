# Bài tập 3: Tạo Giao tiếp giữa Các Process bằng Tín hiệu

## Yêu cầu

Viết chương trình tạo hai process (cha và con) và sử dụng tín hiệu `SIGUSR1` để
giao tiếp giữa chúng.

1. Dùng `fork()` để tạo process con từ process cha.  
2. Process cha sẽ gửi tín hiệu `SIGUSR1` cho process con mỗi 2 giây.  
3. Khi nhận tín hiệu `SIGUSR1`, process con sẽ in ra thông báo  
   `Received signal from parent`.  
4. Dừng chương trình sau khi đã gửi tín hiệu 5 lần.

## Gợi ý

- Dùng `kill()` để gửi tín hiệu từ process cha đến process con.  
- Sử dụng `signal()` trong process con để bắt tín hiệu `SIGUSR1`.

## Câu hỏi

Tại sao chúng ta cần sử dụng `kill()` để gửi tín hiệu trong bài này?

<br>

# Giải thích
- kill() dùng trong bài này là một system call
   - bản chất nó cũng giống comment line kill
   - mục đích duy nhất là gửi signal đến một process thông qua pid mình truyền vào