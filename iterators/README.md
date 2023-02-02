
- 在 CMakeLists.txt 文件的目录下，执行如下命令：

  - `mkdir build` 创建名为 build 的文件夹
  - `cd build` 移动到 build 文件夹下
  - `cmake -G "MinGW Makefiles" ..` 注意其中..表示上一级目录，若为.则表示当前目录；"MinGW Makefiles"指定了使用 MinGW 编译器，否则默认是 MSVC（Visual Studio 的编译器）
  - `mingw32-make.exe` 编译程序，错误提示会显示在终端中
  - `./main.exe` 若上一步无错误，则可运行程序(这里的 main 为可执行文件名，可参照 CMakeLists.txt 中修改)