## Bài tập 3: Đồng bộ hóa với Condition Variables (Mô hình Producer–Consumer)

Bài tập này giải quyết bài toán **"Nhà sản xuất - Người tiêu dùng" (Producer–Consumer)** kinh điển. Nó giới thiệu cách sử dụng **Condition Variables** để một luồng có thể chờ đợi một điều kiện cụ thể xảy ra một cách hiệu quả, thay vì phải liên tục kiểm tra (*busy-waiting*).

### Yêu cầu

1. Xây dựng chương trình với **một luồng Producer** và **một luồng Consumer**.

2. Sử dụng một biến toàn cục `data` và một biến cờ `data_ready` để chia sẻ dữ liệu.

3. **Producer**:
   - Lặp 10 lần.
   - Mỗi lần tạo một số ngẫu nhiên.
   - Đặt số đó vào `data`.
   - Bật cờ `data
