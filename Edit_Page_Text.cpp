#include"Edit_Page_Text.h"
void Edit_Page_Text(Text& text,size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    编辑菜单                        |\n";
	cout << "\t\t\t\t|---->  1、移动                                      |\n";
	cout << "\t\t\t\t|---->  2、添加                                      |\n";
	cout << "\t\t\t\t|---->  3、删除                                      |\n";
	cout << "\t\t\t\t|---->  4、查找                                      |\n";
	cout << "\t\t\t\t|---->  5、替换                                      |\n";
	cout << "\t\t\t\t|---->  6、撤销                                      |\n";
	cout << "\t\t\t\t|---->  7、回退                                      |\n";
	cout << "\t\t\t\t|---->  8、返回文本目录                              |\n";
	cout << "\t\t\t\t|  注：以上所有操作都是对应在某一页上进行            |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "第"<<pages<<"页的内容为：" << endl;
	Show_Page(pages,text);
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
			Edit_Page_Move_Text(text,pages);//移动操作，此函数定义在Edit_Page_Move_Text.cpp文件中
			break;
		case 2:
			Edit_Page_Add_Text(text, pages);//添加操作，此函数定义在Edit_Page_Add_Text.cpp文件中
			break;
		case 3:
			Edit_Page_Delete_Text(text, pages);//删除操作，此函数定义在Edit_Page_Delete_Text.cpp文件中
			break;
		case 4:
			Edit_Page_Find_Text(text, pages);//查找操作
			break;
		case 5:
			Edit_Page_Replace_Text(text, pages);//替换操作
			break;
		case 6:
			Edit_Page_Revoke_Text(text, pages);//撤销操作
			break;
		case 7:
			Edit_Page_Recove_Text(text, pages);//回退操作
			break;
		case 8:
			Edit_Text(text,pages);//返回文本目录菜单
			break;
		default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Find_Text(Text& text, size_t& pages)//实现查找操作
{
	cout << "输入要查找的文本（一个单词或一个汉字）：";
	string word;
	cin >> word;
	getchar();
	TextQuery find(text.context[pages - 1]);//生成一个TextQuery类的对象名为find，调用其构造函数,此类定义在TextQuery.cpp文件中
	find.query(word);//调用find中的query函数，并传入要查找的文本
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  查找操作成功，即将返回编辑菜单!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text, pages);
}
void Edit_Page_Replace_Text(Text& text, size_t& pages)//实现替换操作
{
	string s1, s2;
	cout << "请输入要替换的单词和替换后的单词(以空格分隔):  ";
	cin >> s1 >> s2;
	getchar();
	for (auto& a :text.context[pages-1])
	{
		for (auto& b : a)
		{
			if (b == s1)
			{
				b = s2;
			}
		}
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  替换操作成功，即将返回编辑菜单!\n";
	text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
	text.voke[pages-1].Add_Voke(text.context[pages - 1],text.voke[pages-1]);
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text, pages);
}
void Edit_Page_Revoke_Text(Text& text, size_t& pages)
{
	if (text.voke[pages-1].count==1)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  撤销操作失败，已经不能进行撤销操作，即将返回编辑菜单!\n";
	}
	else {
        text.voke[pages-1].Revoke(text.voke[pages - 1], text,pages);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\t  撤销操作成功，即将返回编辑菜单!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text, pages);
}
void Edit_Page_Recove_Text(Text& text, size_t& pages)
{
	if (text.voke[pages-1].count >= text.voke[pages-1].v.size()) {
	   system("cls");
	   cout << "\n\n\n\n\n\n\n\n\n\t\t\t  回退操作失败，已经不能执行回退操作，即将返回编辑菜单!\n";
	}
	else {
       text.voke[pages - 1].Recove(text.voke[pages - 1], text,pages);
	   system("cls");
	   cout << "\n\n\n\n\n\n\n\n\n\t\t\t  回退操作成功，即将返回编辑菜单!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text,pages);
}