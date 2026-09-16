// Week 1 · 工具链验收
// 目标：确认「写代码 -> 编译 -> 运行 -> 看报错」这条链路是通的。
// 这个文件只有一件事：先让它跑起来。跑起来了，这个月就已经成功开始了。

#include <iostream>
#include <windows.h>   // 提供 SetConsoleOutputCP：用来设置控制台的代码页

int main() {
    SetConsoleOutputCP(65001);  // 65001 = UTF-8，让控制台按 UTF-8 解读输出

    std::cout << "engine-journey week01 OK\n";
    int age = 18;
    std::cout << "年龄:" << age << "\n";
    return 0;
}