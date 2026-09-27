// 第 1 关答案 · 个人信息卡片
// 关键点：char 用单引号、bool 要 = true、const 定义后不能再改

#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    std::string name = "顾言";
    char initial = 'G';              // ← 单引号！双引号是字符串
    int age = 18;
    double height = 1.75;
    bool isStudent = true;           // ← 别漏了 = true
    const int birthYear = 2007;

    std::cout << "姓名：" << name << "\n";
    std::cout << "首字母：" << initial << "\n";
    std::cout << "年龄：" << age << "\n";
    std::cout << "身高：" << height << " 米\n";

    // bool 直接打印是 1 / 0，加 boolalpha 才出 true / false
    std::cout << "是否学生：" << std::boolalpha << isStudent << "\n";

    // 算出来的那一行：常量参与计算
    std::cout << "出生年：" << birthYear << "，2026 年时 " << (2026 - birthYear) << " 岁\n";

    // 四个类型各占几个字节
    std::cout << "sizeof(int)=" << sizeof(int)
              << "  sizeof(double)=" << sizeof(double)
              << "  sizeof(char)=" << sizeof(char)
              << "  sizeof(bool)=" << sizeof(bool) << "\n";

    return 0;
}