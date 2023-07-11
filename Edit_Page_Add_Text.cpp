#include"Edit_Page_Add_Text.h"
void Edit_Page_Add_Text(Text& text, size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    ��Ӳ˵�                        |\n";
	cout << "\t\t\t\t|---->  1�����һ���ı�                              |\n";
	cout << "\t\t\t\t|---->  2�����һ���ı�                              |\n";
	cout << "\t\t\t\t|---->  3�����ر༭�˵�                              |\n";
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
			Edit_Page_Add_One(text, pages);
			break;
		case 2:
			Edit_Page_Add_Line(text, pages);
			break;
		case 3:
			Edit_Page_Text(text, pages);
			break;
		default:
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
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
	cout << "�����뽫Ҫ��ӵ��ı�(�������ӿո�������""#""):  ";
	cin >> word;
	if (word == "#")
	{
		word = " ";
	}
	getchar();
	cout << "����������ı���Ҫ������к��Լ���������һ�����ʺ���:  ";
	cin >> n >> s;
	getchar();
	system("cls");
	if (n > text.context[pages - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���һ���ı�����ʧ�ܣ�����������������������ɾ���˵�!\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���һ���ı������ɹ�������������Ӳ˵�!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Add_Text(text, pages);
}
void Edit_Page_Add_Line(Text& text, size_t& pages)
{   
	cout << "������Ҫ��ӵ��ı�(������Ӳ��ɳ���20���ı�)" << endl;
	string lines;
	getline(cin, lines);
	vector<string>* group = new vector<string>;//��һ����̬�ڴ�����ʱ��Ŷ��������ı�
	text.Read_Line(lines, group);
	cout << "����������ı���Ҫ������к�:  ";
	size_t n;
	cin >> n;
	getchar();
	system("cls");
	if (n > text.context[pages - 1].size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���һ���ı�����ʧ�ܣ�����������������������ɾ���˵�!\n";
	}
	else {
	    Line line;
	    line.insert(line.begin(), (*group).begin(), (*group).end());
	    text.context[pages - 1].insert(text.context[pages - 1].begin() + n, line);
	 	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���һ���ı������ɹ�������������Ӳ˵�!\n";
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
    delete group;//�ı��Ѿ�������text�У����ͷ�group���ڴ�
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Add_Text(text, pages);
}