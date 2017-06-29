# Hướng dẫn build phần mềm trên console

## Build bằng GCC

Các yêu cầu cần có trước khi thực hiệ

* [ ] GCC phiên bản 4.9 trở lên
* [ ] Make
* [ ] CMake

### Windows

Để build trên windows, chạy cmake và make.

Để build với test, cần build thư viện động của google test trước. Vào thư mục googletest và chạy cmake với câu lệnh: 

```
cmake .. -DBUILD_SHARED_LIBS=ON
make
```

Sau khi chạy xong, copy hai file libgtest.so và libgtest_main.so vào thư mục libs ở ngoài, lúc này chạy cmake với câu lệnh:

```
cmake .. -DTEST=ON
make
```

### UNIX

Chạy make từ thư mục gốc. Với các câu lệnh,

1. all
Build phần mềm với release

2. debug
Build phần mềm với debug

3. unittes
Khởi tạo chạy test với release

4. unittestdb
Khởi tạo chạy test với debug

## Build bằng Visual Studio

Yêu cầu: Visual Studio 2013 trở lên, và CMake
Khuyến khích Visual Studio 2015

Chạy cmake, sẽ tạo ra file sln và các file cấu hình của project Visual Studio. Chạy file sln và trong cửa sổ project, chọn LIBPRO chuột phải và bấm vào "Set as startup project". Build và chạy thử phần mềm.

Với google test, chưa biết cách để tích hợp vào.


# Build phần mềm bằng Qt

...