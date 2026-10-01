// Week 1 · 登录判断：把 string / cin / if 串起来
//
// 任务：问用户要「账号」和「密码」，两个都对就打印「登录成功」，否则「登录失败」。
//   账号 xiaoba，密码 123
//
//   验收：输入 xiaoba / 123  ->  登录成功
//         输入别的任意组合   ->  登录失败
//
// 今天会碰到的词：
//   string（字符串）、cin >>（把输入读进变量）、==（判断相等）、&&（两边都成立才算真）
//
//   坑 1：读输入的方向和输出相反 —— 输出用 cout <<，输入用 cin >>。
//         写成 cin << mm，编译器会报「istream 不定义 << 运算符」。
//
//   坑 2：文字要拿双引号括起来。xiaoba 不写引号，编译器会当成变量名，
//         报「未声明的标识符」；同理 string 和数字 123 类型对不上，也要写成 "123"。
//
//   提示：SetConsoleOutputCP(65001) 让控制台按 UTF-8 显示中文，它来自 <windows.h>。

#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(65001);

	string zhanghao, mima;
	cout << "请输入账号" << endl;
	cin >> zhanghao;

	cout << "请输入密码" << endl;
	cin >> mima;

	if (zhanghao == "xiaoba" && mima == "123") {
		cout << "登录成功" << endl;
	}
	else {
		cout << "登录失败" << endl;
	}

	return 0;
}