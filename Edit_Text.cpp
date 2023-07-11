#include"Edit_Text.h"
void Edit_Text(Text& text,size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    文本目录菜单                    |\n";
	cout << "\t\t\t\t|---->  1、查看下一页                                |\n";
	cout << "\t\t\t\t|---->  2、查看上一页                                |\n";
	cout << "\t\t\t\t|---->  3、文本最后一页                              |\n";
	cout << "\t\t\t\t|---->  4、文本第一页                                |\n";
	cout << "\t\t\t\t|---->  5、查看指定页数                              |\n";
	cout << "\t\t\t\t|---->  6、新建一页                                  |\n";
	cout << "\t\t\t\t|---->  7、删除指定页                                |\n";
	cout << "\t\t\t\t|---->  8、编辑                                      |\n";
	cout << "\t\t\t\t|---->  9、返回主菜单                                |\n";
	cout << "\t\t\t\t|  注：指定好所要编辑的页数，点击编辑即可进入编辑页面|\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	int choice, temp = 1;
	while (temp == 1)
	{	
		Show_Page(pages,text);//显示当前页的内容
		cout << "\t\t\t\t\t此文本共有" << text.context.size() << "页，当前在第" << pages << "页" << endl;
		cout << "请输入您的选择：";
		temp = 0;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case 1:
			Next_Page(pages, text);
			break;
		case 2:
			//查看上一页的操作
			Pervious_Page(pages, text);
			break;
		case 3:
			//查看最后一页的操作
			Final_Page(pages, text);
			break;
		case 4:
			Begin_Page(pages, text);
			//查看第一页的操作
			break;
		case 5:
			//查看指定页数的内容
			Sure_page(pages, text);
			break;
		case 6:
			//新建一页
			Add_page(pages, text);
			break;
		case 7:
			//删除一页
			Delete_page(pages, text);
			break;
		case 8:
			//进行，编辑操作，对编辑界面，传入要操作的页数
			if (text.voke[pages - 1].v.size() == 0)//若第一次进入该页的编辑操作，将原本页的内容保存
			{
				text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages-1]);
			}
			Edit_Page_Text(text,pages);
			break;
		case 9:
			//返回主菜单
			Operator_Main_Menu(text);
			break;
		default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 1;
			break;
		}
	}
}
void Show_Page(size_t pages, Text& text)
{
	for (Line line :text.context[pages-1])
	{
		for (string word : line)
		{
			cout << word;
		}
		cout<< endl;
	}
}
void Next_Page(size_t& pages, Text& text)
{
	system("cls");
	if (pages == text.context.size()) { 
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看下一页操作失败，已经为最后一页，即将返回文本目录菜单!\n";
	    cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	    getchar();
	    Edit_Text(text,pages);
	}
	else {
        pages++;
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看下一页操作成功，即将返回文本目录菜单!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Edit_Text(text, pages);
	}
}
void Pervious_Page(size_t& pages, Text& text)
{
	system("cls");
	if (pages == 1)
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看上一页操作失败，已经为第一页，即将返回文本目录菜单!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Edit_Text(text, pages);
	}
	else {
		pages--;
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看上一页操作成功，即将返回文本目录菜单!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Edit_Text(text, pages);
	}
}
void Final_Page(size_t& pages, Text& text)
{
	system("cls");
	pages = text.context.size();
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看最后页操作成功，即将返回文本目录菜单!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text,pages);
}
void Begin_Page(size_t& pages, Text& text)
{
	system("cls");
	pages = 1;
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看第一页操作成功，即将返回文本目录菜单!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text,pages);
}
void Sure_page(size_t& pages,Text& text)
{
	cout << "输入要查看的页数: ";
	size_t n;
	cin >> n;
	getchar();
	system("cls");
	if (n<1 || n>text.context.size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看第" << n << "页操作失败，由于您输入无效页码，即将返回文本目录菜单!\n";
	}
	else {
		pages = n;
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查看第" << pages << "页操作成功，即将返回文本目录菜单!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\n press Enter to continue...";
	getchar();
	Edit_Text(text, pages);
}
void Add_page(size_t& pages, Text& text)
{
	cout << "请输入新建页的页码:  ";
	size_t n;
	cin >> n;
	pages = n;
	getchar();
	if (n<1 || n>text.context.size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  添加一页文本操作失败，新建页的页码不合法，即将返回文本目录菜单!\n";
	}
	else {
		cout << "请输入要添加页的文本(单次添加不可超过20行,以单独一行end代表结束,默认加在指定页的前一页)" << endl;
		string lines;
		vector<string>* group = new vector<string>;//用一个动态内存来暂时存放读进来的文本
		while (getline(cin, lines) && lines != "end")
		{
			text.Read_Line(lines, group);
		}
		Page page;
		Line line;
		size_t l = 40;//默认一行存40个单词
		for (string word : (*group))
		{
			line.push_back(word);
			if (line.size() == l)
			{
				page.push_back(line);
				line.clear();
			}
		}
		if (line.size() != 0)
		{
			page.push_back(line);
		}
		text.context.insert(text.context.begin() + pages - 1, page);
		delete group;
		system("cls");	
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  添加一页文本操作成功，即将返回文本目录菜单!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text, pages);
}
void Delete_page(size_t& pages, Text& text)
{
	cout << "请输入删除页的页码： ";
	size_t n;
	cin >> n;
	pages = n;
	getchar();
	if (n<1 || n>text.context.size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  删除一页文本操作失败，删除页的页码不合法，即将返回文本目录菜单!\n";
	}
	else {
	    text.context.erase(text.context.begin() + pages - 1);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\t  删除该页文本操作成功，即将返回文本目录菜单!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text, pages);
}
