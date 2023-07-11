#include"Edit_Page_Move_Text.h"
void Edit_Page_Move_Text(Text& text, size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    �ƶ��˵�                        |\n";
	cout << "\t\t\t\t|---->  1�������ƶ�n��                               |\n";
	cout << "\t\t\t\t|---->  2�������ƶ�n��                               |\n";
	cout << "\t\t\t\t|---->  3�������ƶ�n��                               |\n";
	cout << "\t\t\t\t|---->  4�������ƶ�n��                               |\n";
	cout << "\t\t\t\t|---->  5�����ر༭�˵�                              |\n";
	cout << "\t\t\t\t|  ע���������в������Ƕ�Ӧ��ĳһ��������            |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "��" << pages << "ҳ������Ϊ��" << endl;
	Show_Page(pages, text);
	cout << "����������ѡ��: ";
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
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Move_Next_Line(Text& text, size_t& pages)
{
	size_t line, column = 0, n;
	string word;
	cout << "������Ҫ�ƶ��������ڵ��кţ��Լ���Ҫ�ƶ��ĵ��ʣ�";
	cin >> line >> word;
	getchar();
	cout << "���������ƶ�����: ";
	cin >> n;
	getchar();
	system("cls");
	if (line - 1 + n >= text.context[pages - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����߽磬�����ƶ�"<<n<<"�в���ʧ�ܣ����������ƶ��˵�!\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����ƶ�"<<n<<"�в����ɹ������������ƶ��˵�!\n";
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
	cout << "������Ҫ�ƶ��������ڵ��кţ��Լ���Ҫ�ƶ��ĵ��ʣ�";
	cin >> line >> word;
	getchar();
	cout << "���������ƶ�����: ";
	cin >> n;
	getchar();
	system("cls");
	if (line<=n)
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����߽������ƶ�" << n << "�в���ʧ�ܣ����������ƶ��˵�!\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����ƶ�" << n << "�в����ɹ������������ƶ��˵�!\n";
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
	cout << "������Ҫ�ƶ��������ڵ��кţ��Լ���Ҫ�ƶ��ĵ��ʣ�";
	cin >> line >> word;
	getchar();
	cout << "���������ƶ�����: ";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����߽������ƶ�" << n << "�в���ʧ�ܣ����������ƶ��˵�!\n";
	}
	else 
	{
		text.context[pages - 1][line - 1].erase(text.context[pages - 1][line - 1].begin() + column);
		text.context[pages - 1][line - 1].insert(text.context[pages - 1][line - 1].begin() + column - n, word);
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����ƶ�" << n << "�в����ɹ������������ƶ��˵�!\n";
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
	cout << "������Ҫ�ƶ��������ڵ��кţ��Լ���Ҫ�ƶ��ĵ��ʣ�";
	cin >> line >> word;
	getchar();
	cout << "���������ƶ�����: ";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����߽������ƶ�" << n << "�в���ʧ�ܣ����������ƶ��˵�!\n";
	}
	else
	{
		text.context[pages - 1][line - 1].erase(text.context[pages - 1][line - 1].begin() + column);
		text.context[pages - 1][line - 1].insert(text.context[pages - 1][line - 1].begin() + column + n, word);
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �����ƶ�" << n << "�в����ɹ������������ƶ��˵�!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Move_Text(text, pages);
}