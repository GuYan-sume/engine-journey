// Week 2 · Day 9（原定 9/25）任务：多路判断 + switch
//
//   今天要学的是「同一件事可以用两种写法表达」，顺便把边界值彻底搞清楚。
//
//   任务：输入一个 0-100 的成绩，输出等级
//     90 - 100 → A
//     80 - 89  → B
//     70 - 79  → C
//     60 - 69  → D
//     0  - 59  → E
//
//   写法一：if / else if / else —— 你已经会了
//   写法二：switch —— 专门用来「一个整数，对应好几种情况」
//
//   switch 长这样（先看一遍，写的时候再回来参考）：
//     int level = score / 10;          // 93 除以 10 得 9（整数除法，小数被砍掉）
//     switch (level) {
//     case 10:
//     case 9:
//         grade = "A";                 // 两个 case 挨在一起 = 10 和 9 都走这里
//         break;                       // ★ 每个 case 结尾都要 break
//     case 8:
//         grade = "B";
//         break;
//     default:
//         grade = "E";                 // 其余情况
//         break;
//     }
//
//   验收：59 → E、60 → D、89 → B、90 → A、100 → A，五个边界一个都不能错
//
//   ★ 提前告诉你的四个坑：
//     1. C++ 不支持「连写比较」。这条最坑：
//          if (60 <= score <= 100)     ← 错误写法，而且它不报错！
//        因为程序先算 60 <= score，得到 0 或 1，再拿 0 或 1 去和 100 比，永远为真。
//        正确写法： if (score >= 60 && score <= 100)
//     2. switch 的 case 后面忘了 break，会「穿透」进下一个 case 接着执行。
//     3. switch 只能判断「等于几」，判断「大于小于」用不了，那种还得用 if。
//     4. 别忘了 default —— 输入 120 或者 -5 的时候得让它说话。
//
//   加分题（可选）：输入非法分数（比如 120）时，让它打印「这个分数不对劲」。

#include <iostream>
#include <string>
#include<windows.h>

int main() {
    SetConsoleOutputCP(65001);

    int score = 0;
    std::cout << "请输入成绩(0-100)：";
    std::cin >> score;

    // ① 第一步：用 if / else if / else 算出等级，把 grade 改成 "A" / "B" / "C" / "D" / "E"
    std::string grade = "?";

    std::cout << "成绩 " << score << " 的等级是：" << grade << "\n";

    // ② 第二步：把上面那段改成 switch 写法，五个边界值再跑一遍，
    //    确认结果和第一步完全一样。两种写法都亲手写过，才算真懂。
    return 0;
}