// 第 5 关答案 · vector 成绩统计
// 关键点：求和要单独循环一遍；平均分必须让除法发生在小数上，否则小数被砍掉

#include <iostream>
#include <vector>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    std::vector<int> scores;
    std::cout << "依次输入 5 个成绩，每输一个按一次回车：\n";
    for (int i = 0; i < 5; ++i) {
        int x = 0;
        std::cin >> x;
        scores.push_back(x);
    }

    // ① 总分：从 0 开始，一个个加上去
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];            // += 就是 sum = sum + scores[i] 的简写
    }

    // ② 平均分：★ 除以 5.0 而不是 5，否则 435 / 5 会得到 87 而不是 87 的那种怪数
    double average = sum / 5.0;

    // ③ 最高分：先假定第一个最大，再一个个比
    int maxScore = scores[0];
    for (int i = 1; i < 5; ++i) {    // 从 1 开始，因为第 0 个已经当种子了
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    std::cout << "总分："   << sum      << "\n";
    std::cout << "平均分：" << average  << "\n";
    std::cout << "最高分：" << maxScore << "\n";

    return 0;
}