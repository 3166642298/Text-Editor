#include"Edit_Page_Delete_Text.h"
void Edit_Page_Delete_Text(Text& text, size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    ɾ���˵�                        |\n";
	cout << "\t\t\t\t|---->  1��ɾ��һ���е�һ���ı�                      |\n";
	cout << "\t\t\t\t|---->  2��ɾ��һ���ı�                              |\n";
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
			Edit_Page_Delete_One(text,pages);
			break;
		case 2:
			Edit_Page_Delete_Line(text,pages);
			break;
		case 3:
			Edit_Page_Text(text,pages);
			break;
		default:
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Delete_One(Text& text,  size_t& pages)
{
	cout << "������Ҫɾ���ı����ڵ��к��Լ���Ҫɾ���ĵ���(����ж�����ʷ��ϣ�Ĭ��ɾ����һ��,���Ҫɾ���ո�����""#""):  ";
	size_t n;
	string s;
	cin >> n >> s;
	if (n > text.context[pages - 1].size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ɾ��һ���ı������ɹ���ָ�����������߽磬��������ɾ���˵�!\n";
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
	      cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ɾ��һ���ı������ɹ�����������ɾ���˵�!\n";
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
	cout << "������Ҫɾ�����кţ� ";
	cin >> n;
	getchar();
	if (n > text.context[pages - 1].size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ɾ��һ���ı�����ʧ�ܣ�����������������������ɾ���˵�!\n";
	}
	else {
        text.context[pages - 1].erase(text.context[pages - 1].begin() + n - 1);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ɾ��һ���ı������ɹ�����������ɾ���˵�!\n";	
		text.voke[pages - 1].Push_Up_Voke(text.voke[pages - 1]);
		text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages - 1]);
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Delete_Text(text,pages);
}