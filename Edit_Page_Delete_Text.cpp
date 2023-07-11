#include"Edit_Page_Delete_Text.h"
void Edit_Page_Delete_Text(Text& text, size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    删除菜单                        |\n";
	cout << "\t\t\t\t|---->  1、删除一行中的一个文本                      |\n";
	cout << "\t\t\t\t|---->  2、删除一行文本                              |\n";
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
			Edit_Page_Delete_One(text,pages);
			break;
		case 2:
			Edit_Page_Delete_Line(text,pages);
			break;
		case 3:
			Edit_Page_Text(text,pages);
			break;
		default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Delete_One(Text& text,  size_t& pages)
{
	cout << "请输入要删除文本所在的行号以及将要删除的单词(如果有多个单词符合，默认删除第一个,如果要删除空格，输入""#""):  ";
	size_t n;
	string s;
	cin >> n >> s;
	if (n > text.context[pages - 1].size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  删除一个文本操作成功，指定行数超出边界，即将返回删除菜单!\n";
	}
	else {
        if (s == "#")
	    {
		   s = " ";
	     }
	     getchar();
	     int count = 0;
	     for (auto a : text.context[pages-1][n-1])
	     {
		    if (a == s)
		    {
			   text.context[pages - 1][n - 1].erase(text.context[pages - 1][n - 1].begin() + count);
			   break;
		     }
		    count++;
	      }
	      system("cls");
	      cout << "\n\n\n\n\n\n\n\n\n\t\t\t  删除一个文本操作成功，即将返回删除菜单!\n";
		  text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		  text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Delete_Text(text,pages);
}
void Edit_Page_Delete_Line(Text& text, size_t& pages)
{
	size_t n;
	cout << "请输入要删除的行号： ";
	cin >> n;
	getchar();
	if (n > text.context[pages - 1].size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  删除一行文本操作失败，超过现有行数，即将返回删除菜单!\n";
	}
	else {
        text.context[pages - 1].erase(text.context[pages - 1].begin() + n - 1);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\t  删除一行文本操作成功，即将返回删除菜单!\n";	
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Delete_Text(text,pages);
}