## Bài tập 1: Khởi tạo và Thu dọn Tiến trình

Khảo sát vòng đời cơ bản nhất của một tiến trình: được tạo ra, thực thi, kết thúc và được tiến trình cha chờ đợi.

### Yêu cầu

* **Tạo tiến trình con** bằng lời gọi hệ thống `fork()`.
* **Tiến trình cha**:

  * In ra PID của chính nó và PID của tiến trình con.
  * Gọi `wait()` để chờ tiến trình con kết thúc.
  * Sử dụng `WIFEXITED()` và `WEXITSTATUS()` để kiểm tra và in ra mã thoát của tiến trình con.
* **Tiến trình con**:

  * In ra PID của chính nó.
  * Gọi `exit()` với một giá trị cụ thể (ví dụ: `exit(10)`).

### Yêu cầu

* Tiến trình cha tạo một tiến trình con bằng `fork()`.
* Tiến trình cha:

  * In ra PID của chính nó và PID của tiến trình con.
  * Gọi `wait()` để chờ tiến trình con kết thúc.
  * Sử dụng `WIFEXITED()` và `WEXITSTATUS()` để ghi nhận và in ra mã thoát của tiến trình con.
* Tiến trình con:

  * In ra PID của chính nó.
  * Gọi `exit()` với một giá trị cụ thể (ví dụ: `exit(10)`).
