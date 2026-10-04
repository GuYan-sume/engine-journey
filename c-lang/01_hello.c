#include <stdio.h>

int main(void) {
    float S,C,r;
    printf("请输入圆的半径r：\n");
    scanf("%f",&r);
    S = 3.14 * r * r;
    C = 2 * 3.14 * r;
    printf("圆的面积是：%f，圆的周长是：%f", S,C);
    return 0;
}