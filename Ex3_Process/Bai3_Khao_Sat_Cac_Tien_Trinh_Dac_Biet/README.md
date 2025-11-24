# Bài tập 3: Khảo sát các Trạng thái Tiến trình Đặc biệt

Quan sát và phân tích hai trạng thái đặc biệt thường gặp trong quản lý tiến trình là **Zombie** và **Orphan**.

## Yêu cầu

### 1. Tạo tiến trình Zombie

- Viết chương trình mà **tiến trình con thoát ngay lập tức**, nhưng **tiến trình cha không gọi `wait()`** mà `sleep()` trong một khoảng thời gian dài.  
- Sử dụng lệnh `ps` trong terminal để **quan sát trạng thái `<defunct>`** của tiến trình con.

### 2. Tạo tiến trình Orphan

- Viết chương trình mà **tiến trình cha thoát ngay sau khi tạo con**.  
- Tiến trình con sẽ `sleep()` một lúc và trong thời gian đó, **liên tục in ra PID của tiến trình cha (`PPID`)**.  
- Quan sát **sự thay đổi của `PPID`**.

### 3. Báo cáo

Trong báo cáo, giải thích:

> Tại sao hai trạng thái này xuất hiện và ý nghĩa của chúng trong hệ thống Linux là gì?

<br>

# Kết luận

### 1. Tiến trình Zombie
- Khi **tiến trình con kết thúc**, nhưng **tiến trình cha chưa gọi `wait()` / `waitpid()`** để thu thập trạng thái thoát (exit status), thì:
  - Tiến trình con **không bị xóa hoàn toàn khỏi hệ thống**, mà chuyển sang trạng thái **Zombie**.
  - Trong lệnh `ps`, tiến trình con sẽ hiện là **`<defunct>`**.

- Tiến trình Zombie:
  - **Không còn thực thi**, không dùng CPU nữa.
  - Vẫn chiếm một ít thông tin trong **bảng tiến trình (process table)** để lưu lại mã thoát cho tiến trình cha đọc.
  - Chỉ biến mất hoàn toàn khi **tiến trình cha gọi `wait()`** (hoặc cha kết thúc, khi đó hệ điều hành sẽ dọn dẹp).

➡️ Vì vậy, trạng thái **Zombie** xuất hiện là do **tiến trình cha không xử lý (không “nhặt xác”) tiến trình con** sau khi nó kết thúc.  
Điều này cho thấy tầm quan trọng của việc **luôn gọi `wait()` / `waitpid()`** trong các chương trình tạo nhiều tiến trình con, tránh để hệ thống tồn tại quá nhiều tiến trình Zombie làm đầy bảng tiến trình.

### 2. Tiến trình Orphan
- Khi **tiến trình cha kết thúc trước**, mọi tiến trình con còn sống sẽ trở thành **Orphan**.
- Hệ điều hành **không bỏ rơi** các tiến trình này, mà:
  - Tự động **gán cha mới** cho chúng là `init`/`systemd`.
  - Đảm bảo sau khi chúng kết thúc, có một “tiến trình cha” (init/systemd) gọi `wait()` để thu dọn.
- Do đó, **tiến trình Orphan vẫn chạy bình thường**, chỉ đổi `PPID`.

### 3. Ý nghĩa 
- **Zombie**:
  - Cho phép tiến trình cha **biết kết quả** (exit code) của tiến trình con.
  - Nếu cha **không xử lý** (không `wait()`), nhiều Zombie có thể tích tụ → **làm đầy bảng tiến trình** → ảnh hưởng hệ thống.
  - Nhắc lập trình viên phải **quản lý tiến trình con đúng cách**.

- **Orphan**:
  - Thể hiện cơ chế **bảo vệ và quản lý tiến trình tự động của hệ điều hành**.
  - Đảm bảo mọi tiến trình **luôn có một “cha” hợp lệ**, để:
    - Có chỗ nhận lại exit status.
    - Tránh rò rỉ tài nguyên (resource leak).