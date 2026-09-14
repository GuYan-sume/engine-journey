// Week 4 · 调试器实战
// ============================================================
// 这个文件里有 3 个 bug。先别改代码，先用调试器把它们找出来。
//
// 【期望行为】
//   总分：505
//   平均分：84.1667        <- 要保留小数
//   第一个历史分数：88
//   程序结束时，所有动态申请的内存都已释放（没有泄漏）
//
// 【实际行为】
//   跑一下就知道，至少有一行输出是错的。
//
// 【你的任务】
//   1. 先通读，写下自己的猜测（猜错也算收获）
//   2. 用断点 / 单步 / 监视窗口定位
//   3. 打开 AddressSanitizer 再跑一遍，看它能不能帮你抓到什么
//   4. 修复，并把过程写进 调试记录.md
// ============================================================

#include <iostream>

int main() {
    const int count = 6;
    int scores[count] = {88, 92, 79, 95, 67, 84};

    int sum = 0;
    for (int i = 0; i <= count; ++i) {
        sum += scores[i];
    }

    int average = sum / count;

    int* history = new int[count];
    for (int i = 0; i < count; ++i) {
        history[i] = scores[i];
    }

    std::cout << "总分: " << sum << "\n";
    std::cout << "平均分: " << average << "\n";
    std::cout << "第一个历史分数: " << history[0] << "\n";

    return 0;
}