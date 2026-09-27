// Week 2 · Day 11（9/27）任务：std::vector —— 一个能装很多个数的箱子
//
//   今天只有一件事：认识「容器」。
//
//   到现在为止，一个变量只能装一个数。要存 5 个成绩怎么办？
//   总不能写 int a1, a2, a3, a4, a5; 吧（那存 500 个呢）。
//   vector 就是「一个能装很多个的变量」，能往里加、能取出来、能数一共装了几个。
//
//   四个新动作（今天只要会这几个）：
//     std::vector<int> scores;   // 造一个空箱子，专门装 int
//     scores.push_back(85);      // 从末尾塞一个数进去
//     scores.size()              // 问它现在装了几个
//     scores[0]                  // 取出第 0 个 —— ★ 从 0 开始数！
//
//   任务：输入 5 个成绩，算出总分、平均分、最高分
//
//   验收：
//     - 输入 88 92 76 95 84（总分 435）→ 平均分 87
//     - 输入 88 92 76 95 100（总分 451）→ 平均分 90.2   ← 有小数才是对的
//     - 最高分正确
//
//   ★ 提前告诉你的四个坑：
//     1. 忘了 #include <vector> → 一堆找不到标识符的报错。
//     2. 整数除法的坑会换个样子回来：sum 是 int，sum / 5 还是整数。
//        想留小数，得写 sum / 5.0，或者先把 sum 变成 double。
//     3. 下标从 0 开始。装了 5 个数时，合法下标是 0 1 2 3 4；
//        写成 scores[5] 就是越界 —— 编译器不拦你，结果是垃圾数据（Week 4 会讲为什么危险）。
//     4. 求最大值，别一上来就把 maxScore 设成 0 ——
//        万一成绩全是负数，0 就变成了答案。正确做法：先让 maxScore = scores[0]，再一个个比。
//
//   加分题（可选）：再加一行「最低分」。

#include <iostream>
#include <vector>
#include<windows.h>

int main() {
    SetConsoleOutputCP(65001);

    std::vector<int> scores;
    std::cout << "依次输入 5 个成绩，每输一个按一次回车：\n";
    for (int i = 0; i < 5; ++i) {
        int x = 0;
        std::cin >> x;
        scores.push_back(x);
    }

    // ★ 今天要你写的就下面三行
    //    提示：三个都要「再写一个 for 循环，从 0 转到 scores.size()」
    int    sum      = 0;   // 总分：一路加上去
    double average  = 0;   // 平均分：★ 小心整数除法，见上面第 2 个坑
    int    maxScore = 0;   // 最高分：先设成 scores[0]，再一个个比

    std::cout << "总分："   << sum      << "\n";
    std::cout << "平均分：" << average  << "\n";
    std::cout << "最高分：" << maxScore << "\n";

    return 0;
}