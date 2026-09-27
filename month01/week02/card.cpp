// Week 2 · Day 7（9/21）任务：认识四种类型 + 常量，打印一张「个人信息卡片」
//
//   今天只有一件事：搞清楚「变量是有类型的，类型决定它能存什么、占几个字节」。
//
//   要用上的五样东西（照着往 main 里写）：
//     std::string name = "你的名字";      // 字符串：一串文字，双引号
//     char  initial    = 'G';             // 单个字符：单引号！和字符串不是一回事
//     int   age        = 18;              // 整数
//     double height    = 1.75;            // 小数（身高，单位米）
//     bool  isStudent  = true;            // 真 / 假 两种值
//     const int birthYear = 2007;         // 常量：定下来就不许再改，改了编译器直接报错
//
//   然后打印成一张卡片，要求：
//     1) 每行一个字段，例如 姓名：古言
//     2) 至少有一行是「算出来的」：用 birthYear 参与计算，比如 2026 - birthYear 得到岁数
//     3) 打印 sizeof(int)、sizeof(double)、sizeof(char)、sizeof(bool)，看看各占几个字节
//
//   验收：
//     - 卡片上姓名、首字母、年龄、身高、是否学生全部出现
//     - 算出来那一行的结果正确
//     - sizeof 的结果：int 4 / double 8 / char 1 / bool 1（自己跑出来核对）
//
//   今天会碰到的词：char、bool、std::string、const（常量）、sizeof、字节
//
//   ★ 提前告诉你的三个坑：
//     1. char 用单引号，std::string 用双引号；把 'A' 写成 "A" 编译器会拦你
//     2. bool 直接 cout 出来是 1 / 0，不是 true / false。
//        想打印 true / false，加分项：std::cout << std::boolalpha << isStudent;
//     3. std::string 要 #include <string>（任务下方已经帮你写好了）
//
//   加分题（可选）：试试 const int birthYear = 2007; 下面再写一行 birthYear = 2008;
//   看看编译器怎么骂你 —— 亲手验证一次「常量不能改」，比看十遍书管用。

#include <iostream>
#include <string>
#include<windows.h>

int main() {
    SetConsoleOutputCP(65001);

    // 你的代码从这里开始写
    std::string name = "顾言";
    char initial = "G";
    int age = 18;
    double height = 1.75;
    bool isStudent

    return 0;
}