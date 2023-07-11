#include"Enter_Text.h"
void Enter_Text(Text& text)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                打开文件菜单                        |\n";
	cout << "\t\t\t\t|---->  1、打开已有文件                              |\n";
	cout << "\t\t\t\t|---->  2、新建空白文档                              |\n";
	cout << "\t\t\t\t|---->  3、返回主菜单                                |\n";
	cout << "\t\t\t\t|    注：新建空白文档默认该文档未进行保存操作，需    |\n";
	cout << "\t\t\t\t|        自行保存                                    |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "请输入您的选择: ";
	int choice, temp = 0;
	while (temp == 0)
	{
		temp = 1;
		cin >> choice;
		switch (choice)
		{
		  case 1:
			Enter_Open_File(text);//打开已有文件，将该文件中的内容保存至text内
			break;
		  case 2:
		    Enter_New_File(text);//兴建空白文档，支持用户自己输入文本，并且支持后续再次编辑，默认添加在文本尾部；
			break;
		  case 3:
			Operator_Main_Menu(text);//返回主菜单
		    break;
		  default:
			cout << "该选项不存在，请输入正确的选择" << endl;
			temp = 0;
			break;
		}
	}
}
void Enter_New_File(Text& text)
{
	//新建一个空的内容；
	system("cls");
	cout << "请输入您要编辑的内容，以单独输入一行end结尾：" << endl;
	string line;
	vector<string>* group = new vector<string>;//用一个动态内存来暂时存放读进来的文本
	while (cin>>line&&line!="end")
	{
		text.Read_Line(line, group);//循环读入每一行，此函数在Text.cpp定义
	}
	text.Save_Line(text, group);//实现文本保存到text中，此函数在Text.cpp定义
	delete group;//文本已经保存在text中，可释放group的内存，减少内存的使用
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t新建空白文档成功，即将返回主菜单!\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Operator_Main_Menu(text);//返回主菜单
}
void Enter_Open_File(Text& text)
{
	system("cls");
	cout << "请输入您要打开的文件名(例如:myfile.txt): ";
	string file_name;
	cin >> file_name;//打开文件的文件名
	getchar();
	ifstream ifs(file_name, ios::in);
	system("cls");
	if (!ifs.is_open())//输入的文件名对应的文件不存在
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t此文件名对应的文件不存在，文件打开失败，请重新输入!\n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Enter_Text(text);
	}
	else {
		string line;
		vector<string> *group=new vector<string>;//用一个动态内存来暂时存放读进来的文本
		while (getline(ifs, line))
		{
			text.Read_Line(line,group);
		}
		text.Save_Line(text,group);
		delete group;//文本已经保存在text中，可释放group的内存
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t文件读取成功，即将返回主菜单!\n";
		cout << "\n\n\n\n\n\n\n\n\n\n\npress Enter to continue...";	
		ifs.close();
		getchar();
		Operator_Main_Menu(text);
	}
}
