#include"Exit_Text.h"
void Exit_Text(Text& text)
{
	system("cls");
	cout << "\t\t\t\t\t请再次确认是否退出文本编译器(Y/N)!\n";
	char ch = getchar();
	cin >> ch;
	getchar();
	system("cls");
	if (ch == 'Y')
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t即将退出文本编译器系统，欢迎您的再次使用!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		exit(0);
	}
	else if (ch == 'N')
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t退出文本编译器系统失败，请再次选择!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
        getchar();
		system("cls");
		Operator_Main_Menu(text);
	}
}