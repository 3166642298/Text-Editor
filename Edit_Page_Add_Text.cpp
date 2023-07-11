#include"Edit_Page_Add_Text.h"
void Edit_Page_Add_Text(Text& text, size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    添加菜单                        |\n";
	cout << "\t\t\t\t|---->  1、添加一个文本                              |\n";
	cout << "\t\t\t\t|---->  2、添加一行文本                              |\n";
	cout << "\t\t\t\t|---->  3、返回编辑菜单                              |\n";
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
			Edit_Page_Add_One(text, pages);
			break;
		case 2:
			Edit_Page_Add_Line(text, pages);
			break;
		case 3:
			Edit_Page_Text(text, pages);
			break;
		default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Add_One(Text& text, size_t& pages)
{
	size_t n;
	string s;
	string word;
	cout << "请输入将要添加的文本(如果想添加空格，请输入""#""):  ";
	cin >> word;
	if (word == "#")
	{
		word = " ";
	}
	getchar();
	cout << "请输入添加文本所要加入的行号以及插入在哪一个单词后面:  ";
	cin >> n >> s;
	getchar();
	system("cls");
	if (n > text.context[pages - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  添加一个文本操作失败，超过现有行数，即将返回删除菜单!\n";
	}
	else {
		int count = 0;
		for (auto a : text.context[pages - 1][n - 1])
		{
			count++;
			if (a == s)
			{
				text.context[pages - 1][n - 1].insert(text.context[pages - 1][n - 1].begin() + count, word);
				break;
			}
		}
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  添加一个文本操作成功，即将返回添加菜单!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Add_Text(text, pages);
}
void Edit_Page_Add_Line(Text& text, size_t& pages)
{   
	cout << "请输入要添加的文本(单次添加不可超过20个文本)" << endl;
	string lines;
	getline(cin, lines);
	vector<string>* group = new vector<string>;//用一个动态内存来暂时存放读进来的文本
	text.Read_Line(lines, group);
	cout << "请输入添加文本将要插入的行号:  ";
	size_t n;
	cin >> n;
	getchar();
	system("cls");
	if (n > text.context[pages - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  添加一行文本操作失败，超过现有行数，即将返回删除菜单!\n";
	}
	else {
	    Line line;
	    line.insert(line.begin(), (*group).begin(), (*group).end());
	    text.context[pages - 1].insert(text.context[pages - 1].begin() + n, line);
	 	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  添加一行文本操作成功，即将返回添加菜单!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
    delete group;//文本已经保存在text中，可释放group的内存
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Add_Text(text, pages);
}