// 第 2 关答案 · 闰年判断
// 关键点：&& 是「并且」、|| 是「或者」，括号把两组条件分开

#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    int year = 0;
    std::cout << "请输入年份：";
    std::cin >> year;

    // 读法：能被 4 整除 且 不能被 100 整除，或者 能被 400 整除
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (isLeap) {
        std::cout << year << " 是闰年\n";
    } else {
        std::cout << year << " 不是闰年\n";
    }

    return 0;
}