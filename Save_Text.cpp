#include"Save_Text.h"
void Save_Text(Text& text)
{
	system("cls");
	cout << "请输入要保存的文件名(例如：myfile): ";
	string File_name;
	cin >> File_name;
	getchar();
	ifstream ifs(File_name, ios::in);
	system("cls");
	if (ifs.is_open())
	{
		cout << "同名文件已经存在，是否进行替换(Y/N):  " << endl;
		string choice;
		cin >> choice;
		getchar();
		system("cls");
		if (choice == "Y")
		{
			//进行保存文件操作
			Save_File(text,File_name);
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t   文件保存成功，即将返回主菜单!\n";
			cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
			ifs.close();
			getchar();
			Operator_Main_Menu(text);
		}
		else {
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   文件保存失败请重新选择!\n";
			cout << "\n\n\n\n\n\n\n\n\n\npress Enter to continue...";
			getchar();
			Operator_Main_Menu(text);
		}
	}
	else {
		//进行保存文件操作
		Save_File(text, File_name);
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t   文件保存成功，即将返回主菜单!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		ifs.close();
		getchar();
		Operator_Main_Menu(text);
	}
}
void Save_File(Text text, string& file_name)
{
	ofstream ofs;
	ofs.open(file_name, ios::trunc);
	for (Page page : text.context)
	{
		for (Line line : page)
		{
			for (string word : line)
			{
				ofs<< word;
			}
		}
		ofs<< endl;
	}
	ofs.close();
}