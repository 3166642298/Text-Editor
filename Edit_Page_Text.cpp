#include"Edit_Page_Text.h"
void Edit_Page_Text(Text& text,size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    �༭�˵�                        |\n";
	cout << "\t\t\t\t|---->  1���ƶ�                                      |\n";
	cout << "\t\t\t\t|---->  2�����                                      |\n";
	cout << "\t\t\t\t|---->  3��ɾ��                                      |\n";
	cout << "\t\t\t\t|---->  4������                                      |\n";
	cout << "\t\t\t\t|---->  5���滻                                      |\n";
	cout << "\t\t\t\t|---->  6������                                      |\n";
	cout << "\t\t\t\t|---->  7������                                      |\n";
	cout << "\t\t\t\t|---->  8�������ı�Ŀ¼                              |\n";
	cout << "\t\t\t\t|  ע���������в������Ƕ�Ӧ��ĳһҳ�Ͻ���            |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "��"<<pages<<"ҳ������Ϊ��" << endl;
	Show_Page(pages,text);
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
			Edit_Page_Move_Text(text,pages);//�ƶ��������˺���������Edit_Page_Move_Text.cpp�ļ���
			break;
		case 2:
			Edit_Page_Add_Text(text, pages);//��Ӳ������˺���������Edit_Page_Add_Text.cpp�ļ���
			break;
		case 3:
			Edit_Page_Delete_Text(text, pages);//ɾ���������˺���������Edit_Page_Delete_Text.cpp�ļ���
			break;
		case 4:
			Edit_Page_Find_Text(text, pages);//���Ҳ���
			break;
		case 5:
			Edit_Page_Replace_Text(text, pages);//�滻����
			break;
		case 6:
			Edit_Page_Revoke_Text(text, pages);//��������
			break;
		case 7:
			Edit_Page_Recove_Text(text, pages);//���˲���
			break;
		case 8:
			Edit_Text(text,pages);//�����ı�Ŀ¼�˵�
			break;
		default:
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
			temp = 0;
			break;
		}
	}
}
void Edit_Page_Find_Text(Text& text, size_t& pages)//ʵ�ֲ��Ҳ���
{
	cout << "����Ҫ���ҵ��ı���һ�����ʻ�һ�����֣���";
	string word;
	cin >> word;
	getchar();
	TextQuery find(text.context[pages - 1]);//����һ��TextQuery��Ķ�����Ϊfind�������乹�캯��,���ඨ����TextQuery.cpp�ļ���
	find.query(word);//����find�е�query������������Ҫ���ҵ��ı�
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���Ҳ����ɹ����������ر༭�˵�!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text, pages);
}
void Edit_Page_Replace_Text(Text& text, size_t& pages)//ʵ���滻����
{
	string s1, s2;
	cout << "������Ҫ�滻�ĵ��ʺ��滻��ĵ���(�Կո�ָ�):  ";
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
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �滻�����ɹ����������ر༭�˵�!\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ��������ʧ�ܣ��Ѿ����ܽ��г����������������ر༭�˵�!\n";
	}
	else {
        text.voke[pages-1].Revoke(text.voke[pages - 1], text,pages);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���������ɹ����������ر༭�˵�!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text, pages);
}
void Edit_Page_Recove_Text(Text& text, size_t& pages)
{
	if (text.voke[pages-1].count >= text.voke[pages-1].v.size()) {
	   system("cls");
	   cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���˲���ʧ�ܣ��Ѿ�����ִ�л��˲������������ر༭�˵�!\n";
	}
	else {
       text.voke[pages - 1].Recove(text.voke[pages - 1], text,pages);
	   system("cls");
	   cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���˲����ɹ����������ر༭�˵�!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Page_Text(text,pages);
}