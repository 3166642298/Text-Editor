#include<iostream>
#include"Main_Menu.h"
#include"Text.h"
using namespace std;
int main()
{
	Text text;//Text是保存文本编译器的文本的一个抽象类，程序开始前首先生成一个该对象
	Show_Main_Menu(text);//显示开始界面，该函数声明在Main_Menu.h文件，实现在其.cpp文件，该函数传text的引用
	return 0;
}