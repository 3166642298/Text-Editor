#include"Save_Text.h"
void Save_Text(Text& text)
{
	system("cls");
	cout << "������Ҫ������ļ���(���磺myfile): ";
	string File_name;
	cin >> File_name;
	getchar();
	ifstream ifs(File_name, ios::in);
	system("cls");
	if (ifs.is_open())
	{
		cout << "ͬ���ļ��Ѿ����ڣ��Ƿ�����滻(Y/N):  " << endl;
		string choice;
		cin >> choice;
		getchar();
		system("cls");
		if (choice == "Y")
		{
			//���б����ļ�����
			Save_File(text,File_name);
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t   �ļ�����ɹ��������������˵�!\n";
			cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
			ifs.close();
			getchar();
			Operator_Main_Menu(text);
		}
		else {
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   �ļ�����ʧ��������ѡ��!\n";
			cout << "\n\n\n\n\n\n\n\n\n\npress Enter to continue...";
			getchar();
			Operator_Main_Menu(text);
		}
	}
	else {
		//���б����ļ�����
		Save_File(text, File_name);
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t   �ļ�����ɹ��������������˵�!\n";
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