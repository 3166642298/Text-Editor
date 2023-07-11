#include"Main_Menu.h"
void Show_Main_Menu(Text& text)
{
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcom to use TXT edition system!\n";
	cout << "\n\n\t\t\t\t\t     欢迎使用简易文本编辑器!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	char ch = getchar();
	Operator_Main_Menu(text);
}
void Operator_Main_Menu(Text& text)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                      主菜单                        |\n";
	cout << "\t\t\t\t|---->  1、输入文章内容                              |\n";
	cout << "\t\t\t\t|---->  2、进入编辑菜单                              |\n";
	cout << "\t\t\t\t|---->  3、保存文本                                  |\n";
	cout << "\t\t\t\t|---->  4、退出文本编辑器                            |\n";
	cout << "\t\t\t\t|                                                    |\n";
	cout << "\t\t\t\t|    注：第一次运行本程序时请选择功能1               |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "请输入您的选择: ";
	int choice, temp=0;
	size_t p = 1;//代表第一次查看的页数
	while (temp == 0)//用来实现当用户输入不存在的功能代号的数字时，提醒用户输入正确的选项
	{
		temp = 1;
		cin >> choice;
		switch (choice)
		{
		  case 1:
			Enter_Text(text);//输入文章内容，此函数在Enter_Text.cpp文件内定义
			break;
		  case 2:
			Edit_Text(text,p);//每次进入编辑菜单，默认从第一页开始查看，此函数在Edit_Text.cpp文件内定义
			break;
		  case 3:
			Save_Text(text);//保存文本，此函数在Save_Text.cpp文件内定义
			break;
		  case 4:
			Exit_Text(text);//退出文本编译器，此函数在Exit_Text.cpp文件内定义
			break;
		  default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 0;
			break;
		}
	}
}