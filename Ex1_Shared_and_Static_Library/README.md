# Thư viện trong C – Static & Shared, Tổ chức Module và Makefile

Trong lập trình C, khi một dự án lớn dần, việc tổ chức mã nguồn thành các module có thể tái sử dụng là cực kỳ quan trọng. **Thư viện (library)** là cách chúng ta đóng gói một tập hợp các hàm liên quan để chia sẻ giữa nhiều dự án khác nhau mà không cần sao chép mã nguồn.

- **Static Library (`.a`)**:  
  Mã của thư viện được sao chép và nhúng trực tiếp vào tệp thực thi của bạn tại thời điểm biên dịch (*compile time*).  
  → Tệp thực thi sẽ **lớn hơn** nhưng có thể **chạy độc lập**.

- **Shared Library (`.so` – Shared Object)**:  
  Mã của thư viện **không** được nhúng vào tệp thực thi. Thay vào đó, hệ điều hành sẽ tải thư viện này vào bộ nhớ **một lần tại thời điểm chạy (*runtime*)** và **nhiều chương trình** có thể dùng chung.

---

## 1. Xây dựng Thư viện Tiện ích Xử lý Chuỗi (`strutils`)

### 1.1. Cấu trúc Mã nguồn

- `strutils.h`: Định nghĩa các hàm mà thư viện sẽ cung cấp, ví dụ:
  - `str_reverse`: Reverses a string in-place.
  - `str_trim`: Removes leading and trailing whitespace from a string.
  - `str_to_int`: Safely converts a string to an integer.
- `strutils.c`: Mã nguồn để triển khai các hàm đã định nghĩa trong `strutils.h`.
- `main.c`: Chương trình chính để kiểm thử các hàm trong thư viện `strutils`.

### 1.2. Đóng gói Thư viện

- Tạo một **Static Library**: `libstrutils.a`
- Tạo một **Shared Library**: `libstrutils.so`

### 1.3. Sử dụng Thư viện

- Viết một chương trình chính để kiểm thử các hàm trong thư viện `strutils`.
- Biên dịch và Liên kết (Linking):
  - Với **Static Library**:  
    ```bash
    gcc main.c -L. -lstrutils -o main_static
    ```
  - Với **Shared Library**:  
    ```bash
    gcc main.c -L. -lstrutils -o main_shared
    ```

---

## 2. Tự động hóa với Makefile

Hãy tạo một file tên là **`Makefile`** để tự động hóa toàn bộ các bước trên, bao gồm các "target" sau:

- `all`: Target mặc định, xây dựng cả hai phiên bản `main_static` và `main_shared`.
- `static`: Chỉ xây dựng `libstrutils.a` và `main_static`.
- `shared`: Chỉ xây dựng `libstrutils.so` và `main_shared`.
- `clean`: Xóa tất cả các file được tạo ra trong quá trình build (`.o`, `.a`, `.so`, và các tệp thực thi).
