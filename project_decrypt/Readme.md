RC4 - DECRYPTION
1. Giới thiệu:
- Chương trình thực hiện giải mã thuật toán mã hoá RC4.
- Bạn chỉ cần chạy file run.bat trong VS Code rồi nhập input là bản mã, output hiện ra là plaintext.
2. Cấu trúc project:
- RC4.h: Header chung: khai báo kích thước, nguyên mẫu hàm, hằng số.
- swap.c: Hàm swap() hoán đổi hai giá trị byte, dùng cho KSA và PRGA.
- init_ST.c: Hàm khởi tạo mảng trạng thái S[] và mảng T[] từ khoá.
- KSA.c: Hàm thực hiện Key Scheduling Algorithm (KSA) trộn S theo khoá.
- PRGA.c: Hàm thực hiện Pseudo-Random Generation Algorithm (PRGA) để sinh keystream.
- Encrypt.c: Hàm rc4_decrypt thực hiện quá trình decrypt gồm khởi tạo S, tạo ra T, hoán vị S (KSA) rồi thực hiện PRGA để sinh keystream và thực hiện phép XOR keystream với cipher C để thu được plaintext P.
- main.c: Chương trình chính: nhập chuỗi nhị phân (có thể dùng dấu khoảng trắng để phân biệt mỗi kí tự) cipher và khoá, gọi hàm giải mã, rồi in ra kết quả.
- run.bat: Script chạy trên Windows: biên dịch (nếu cần) và thực thi chương trình, sau đó nhập input từ bàn phím.
3. Cách chạy:
- Mở thư mục project RC4_Decrytion trên VS Code
- Thực hiện chạy file run.bat trong VS Code
- Nhập input gồm chuỗi nhị phân cipher (có thể dùng dấu khoảng trắng để phân biệt mỗi kí tự) và Key (chuỗi kí tự ASCII)
- Output là bản plaintext P in ra ở chuỗi.
4. Bộ test vector:
- Cipher: 11110010 00000111 10011011 00101100 00001111 11100100 11100100 11011111 01001100 00011011 11111000 10101000 01001011 00110001 11001111 00001111 01101110 10101000 11011100 00010101 00000110 00100101 01001101 11111110 00001001 10011111 00011001 00110100 11010001 11110101 11100110 10010010 11001010 11011111 11001110 10001001 11110010 10001100 00100101 11011100 11101100 01111011
- Key: cryptography123
- Plaintext: Hanoi University of Science and Technology
