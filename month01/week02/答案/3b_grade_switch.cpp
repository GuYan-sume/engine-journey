// 第 3 关答案（写法二）· 成绩等级：switch
// 关键点：score / 10 把 0-100 压成 0-10 这十一个整数，再用 case 判断「等于几」
//         100 / 10 == 10，所以 case 10 和 case 9 要挨着写，让它们共用一段代码

#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    int score = 0;
    std::cout << "请输入成绩(0-100)：";
    std::cin >> score;

    std::string grade = "?";

    // 先拦掉非法分数。不拦的话 105 会被压成 10，反而变成 A
    if (score < 0 || score > 100) {
        grade = "?";
    } else {
        int level = score / 10;      // 93 → 9，88 → 8，100 → 10，7 → 0

        switch (level) {
        case 10:
        case 9:                      // 两个 case 挨着写 = 都走这一段
            grade = "A";
            break;                   // ★ 每个 case 结尾都要 break，否则会穿透
        case 8:
            grade = "B";
            break;
        case 7:
            grade = "C";
            break;
        case 6:
            grade = "D";
            break;
        default:                     // 0-59 全部落在 0-5，都是 E
            grade = "E";
            break;
        }
    }

    std::cout << "成绩 " << score << " 的等级是：" << grade << "\n";
    return 0;
}