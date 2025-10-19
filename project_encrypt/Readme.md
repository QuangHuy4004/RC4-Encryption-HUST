RC4 Encryption Project
1. Giới thiệu

Dự án này triển khai thuật toán mã hóa dòng RC4 (Rivest Cipher 4) – một thuật toán mã hóa đối xứng cổ điển. RC4 hoạt động bằng cách sinh ra một chuỗi khóa giả ngẫu nhiên (keystream) từ khóa bí mật ban đầu, sau đó thực hiện phép XOR giữa chuỗi khóa và bản rõ để tạo ra bản mã. Quá trình giải mã được thực hiện theo cùng cách, chỉ cần XOR bản mã với cùng chuỗi khóa để thu lại bản rõ.
Chương trình cho phép người dùng nhập vào chuỗi Plaintext và Key, sau đó hiển thị kết quả mã hóa ở dạng nhị phân (binary) và thập lục phân (hexadecimal).

2. Cấu trúc thư mục

RC4.h: Khai báo hằng số, nguyên mẫu hàm và kích thước mảng S, T.
swap.c: Hàm hoán đổi hai byte, được dùng trong KSA và PRGA.
init_ST.c: Khởi tạo mảng S[] và T[] từ khóa.
KSA.c: Thực hiện thuật toán Key Scheduling Algorithm (KSA) – trộn mảng S theo khóa.
PRGA.c: Thực hiện thuật toán Pseudo-Random Generation Algorithm (PRGA) – sinh chuỗi khóa keystream.
Encrypt.c: Gọi toàn bộ quy trình RC4 để mã hóa.
main.c: Chương trình chính, thực hiện nhập dữ liệu, mã hóa và in kết quả.
run.bat: Tập lệnh chạy tự động trên Windows.
main.exe: File thực thi đã biên dịch sẵn.

3. Cách chạy chương trình

Mở thư mục dự án trong Visual Studio Code.

Chạy file run.bat, hoặc biên dịch thủ công bằng lệnh:

gcc main.c Encrypt.c init_ST.c KSA.c PRGA.c swap.c -o main.exe
./main.exe


Khi được yêu cầu, nhập:

Plaintext: chuỗi ký tự ASCII (có thể chứa khoảng trắng).

Key: chuỗi khóa bí mật (ASCII).

Kết quả đầu ra bao gồm:

Cipher (binary): bản mã ở dạng nhị phân.

Cipher (hex): bản mã ở dạng thập lục phân.

4. Quy trình hoạt động của thuật toán RC4

Bước 1: Hàm rc4_init_ST() khởi tạo mảng S và T từ khóa.
Bước 2: Hàm rc4_ksa() thực hiện trộn mảng S theo khóa (Key Scheduling Algorithm).
Bước 3: Hàm rc4_prga() sinh chuỗi khóa giả ngẫu nhiên (Pseudo-Random Generation Algorithm).
Bước 4: Mỗi byte của bản rõ được XOR với chuỗi khóa để tạo ra bản mã.

5. Bộ kiểm thử (Test Vector)

Plaintext: Hanoi University of Science and Technology
Key: cryptography123
Cipher (Binary):
11110010 00000111 10011011 00101100 00001111 11100100 11100100 11011111 01001100 00011011 11111000 10101000 01001011 00110001 11001111 00001111 01101110 10101000 11011100 00010101 00000110 00100101 01001101 11111110 00001001 10011111 00011001 00110100 11010001 11110101 11100110 10010010 11001010 11011111 11001110 10001001 11110010 10001100 00100101 11011100 11101100 01111011
Cipher (Hex):
F2 07 9B 2C 0F E4 E4 DF 4C 1B F8 A8 4B 31 CF 0F 6E A8 DC 15 06 25 4D FE 09 9F 19 34 D1 F5 E6 92 CA DF CE 89 F2 8C 25 DC EC 7B

Khi chạy chương trình với dữ liệu kiểm thử trên, kết quả đầu ra phải trùng khớp hoàn toàn với giá trị Cipher ở trên nếu thuật toán hoạt động chính xác.

6. Ghi chú

Giải mã RC4 được thực hiện bằng cách XOR bản mã với cùng chuỗi khóa.
Có thể mở rộng chương trình để thêm chức năng đọc/ghi file hoặc kiểm tra độ dài khóa trước khi mã hóa.
Dự án tương thích với chuẩn ANSI C và có thể biên dịch bằng GCC trên Windows hoặc Linux.

7. Thông tin tác giả

Tên dự án: RC4 Encryption Project
Ngôn ngữ lập trình: C