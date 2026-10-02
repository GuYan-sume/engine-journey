/* 01_hello.c —— 工具链验收
 *
 * 编译运行：c-lang\run.bat 01_hello.c
 *
 * 验收标准（两条都对，说明环境没问题）：
 *   1. 屏幕上出现的中文不是乱码
 *   2. 输入一个整数后，能算出它的两倍
 */

#include <stdio.h>

int main(void) {
    double S,C,r;
    printf("请输入圆的半径r：\n");
    scanf("%lf",&r);
    S = 3.14 * r * r;
    C = 2 * 3.14 * r;


    printf("圆的面积是：%lf，圆的周长是：%lf", S,C);

    return 0;
}