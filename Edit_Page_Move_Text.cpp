#include"Edit_Page_Move_Text.h"
void Edit_Page_Move_Text(Text& text, size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    移动菜单                        |\n";
	cout << "\t\t\t\t|---->  1、向下移动n行                               |\n";
	cout << "\t\t\t\t|---->  2、向上移动n行                               |\n";
	cout << "\t\t\t\t|---->  3、向左移动n列                               |\n";
	cout << "\t\t\t\t|---->  4、向右移动n列                               |\n";
	cout << "\t\t\t\t|---->  5、返回编辑菜单                              |\n";
	cout << "\t\t\t\t|  注：以上所有操作都是对应在某一个单词上            |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "第" << pages << "页的内容为：" << endl;
	Show_Page(pages, text);
	cout << "请输入您的选择: ";
	int choice, temp = 0;
	while (temp == 0)
	{
		temp = 1;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case 1:
			Edit_Page_Move_Next_Line(text ,pages);
			break;
		case 2:
			Edit_Page_Move_Pervious_Line(text, pages);
			break;
		case 3:
			Edit_Page_Move_Left_Column(text, pages);
			break;
		case 4:
			Edit_Page_Move_Right_Column(text, pages);
			break;
		case 5:
			Edit_Page_Text(text, pages);
			break;
		default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Move_Next_Line(Text& text, size_t& pages)
{
	size_t line, column = 0, n;
	string word;
	cout << "请输入要移动单词所在的行号，以及将要移动的单词：";
	cin >> line >> word;
	getchar();
	cout << "输入向下移动几行: ";
	cin >> n;
	getchar();
	system("cls");
	if (line - 1 + n >= text.context[pages - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  超出边界，向下移动"<<n<<"行操作失败，即将返回移动菜单!\n";
	}
	else {
		for (string s : text.context[pages - 1][line - 1])
		{
			if (s == word)
			{
				text.context[pages - 1][line - 1].erase(text.context[pages - 1][line - 1].begin() + column);
				break;
			}
			column++;
		}
		text.context[pages - 1][line- 1+n].insert(text.context[pages - 1][line- 1+n].begin() + column, word);
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  向下移动"<<n<<"行操作成功，即将返回移动菜单!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Move_Text(text, pages);
}
void Edit_Page_Move_Pervious_Line(Text& text, size_t& pages)
{
	size_t line, column = 0, n;
	string word;
	cout << "请输入要移动单词所在的行号，以及将要移动的单词：";
	cin >> line >> word;
	getchar();
	cout << "输入向上移动几行: ";
	cin >> n;
	getchar();
	system("cls");
	if (line<=n)
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  超出边界向上移动" << n << "行操作失败，即将返回移动菜单!\n";
	}
	else {
		for (string s : text.context[pages - 1][line - 1])
		{
			if (s == word)
			{
				text.context[pages - 1][line - 1].erase(text.context[pages - 1][line - 1].begin() + column);
				break;
			}
			column++;
		}
		text.context[pages - 1][line - 1 - n].insert(text.context[pages - 1][line - 1 -n].begin() + column, word);
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  向上移动" << n << "行操作成功，即将返回移动菜单!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages-1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Move_Text(text, pages);
}
void Edit_Page_Move_Left_Column(Text& text, size_t& pages)
{
	size_t line,column = 0, n;
	string word;
	cout << "请输入要移动单词所在的行号，以及将要移动的单词：";
	cin >> line >> word;
	getchar();
	cout << "输入向左移动几列: ";
	cin >> n; 
	getchar();
	system("cls");
	for (string s : text.context[pages - 1][line - 1])
	{
		if (s == word)
		{
			break;
		}
		column++;
	}
	if (column<n)
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  超出边界向左移动" << n << "列操作失败，即将返回移动菜单!\n";
	}
	else 
	{
		text.context[pages - 1][line - 1].erase(text.context[pages - 1][line - 1].begin() + column);
		text.context[pages - 1][line - 1].insert(text.context[pages - 1][line - 1].begin() + column - n, word);
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  向左移动" << n << "列操作成功，即将返回移动菜单!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Move_Text(text, pages);
}
void Edit_Page_Move_Right_Column(Text& text, size_t& pages)
{
	size_t line, column = 0, n;
	string word;
	cout << "请输入要移动单词所在的行号，以及将要移动的单词：";
	cin >> line >> word;
	getchar();
	cout << "输入向右移动几列: ";
	cin >> n;
	getchar();
	system("cls");
	for (string s : text.context[pages - 1][line - 1])
	{
		if (s == word)
		{
			break;
		}
		column++;
	}
	if (column + n >= text.context[pages - 1][line - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  超出边界向右移动" << n << "列操作失败，即将返回移动菜单!\n";
	}
	else
	{
		text.context[pages - 1][line - 1].erase(text.context[pages - 1][line - 1].begin() + column);
		text.context[pages - 1][line - 1].insert(text.context[pages - 1][line - 1].begin() + column + n, word);
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  向右移动" << n << "列操作成功，即将返回移动菜单!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Move_Text(text, pages);
}