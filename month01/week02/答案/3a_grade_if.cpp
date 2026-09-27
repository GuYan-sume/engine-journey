// 第 3 关答案（写法一）· 成绩等级：if / else if / else
// 关键点：条件要从大到小往下排，走通一个就出去了

#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    int score = 0;
    std::cout << "请输入成绩(0-100)：";
    std::cin >> score;

    std::string grade = "";
    if (score < 0 || score > 100) {
        grade = "?";                 // 非法分数先拦掉
    } else if (score >= 90) {        // 90 及以上
        grade = "A";
    } else if (score >= 80) {        // 走到这里说明已经小于 90 了
        grade = "B";
    } else if (score >= 70) {
        grade = "C";
    } else if (score >= 60) {
        grade = "D";
    } else {                         // 剩下的都是 60 以下
        grade = "E";
    }

    std::cout << "成绩 " << score << " 的等级是：" << grade << "\n";
    return 0;
}