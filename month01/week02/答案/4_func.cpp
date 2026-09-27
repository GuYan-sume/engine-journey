// 第 4 关答案 · 函数 c2f
// 关键点：9 / 5 是整数除法得 1，必须写 9.0 / 5.0

#include <iostream>
#include <windows.h>

// 函数写在 main 上面，才不用另外声明
// 读法：输入一个 double 的摄氏温度 c，返回一个 double 的华氏温度
double c2f(double c) {
    return c * 9.0 / 5.0 + 32.0;     // ← 就是这一行
}

int main() {
    SetConsoleOutputCP(65001);

    std::cout << "0 摄氏度 = "   << c2f(0)   << " 华氏度\n";
    std::cout << "37 摄氏度 = "  << c2f(37)  << " 华氏度\n";
    std::cout << "100 摄氏度 = " << c2f(100) << " 华氏度\n";

    return 0;
}