#include"Edit_Text.h"
void Edit_Text(Text& text,size_t& pages)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                    �ı�Ŀ¼�˵�                    |\n";
	cout << "\t\t\t\t|---->  1���鿴��һҳ                                |\n";
	cout << "\t\t\t\t|---->  2���鿴��һҳ                                |\n";
	cout << "\t\t\t\t|---->  3���ı����һҳ                              |\n";
	cout << "\t\t\t\t|---->  4���ı���һҳ                                |\n";
	cout << "\t\t\t\t|---->  5���鿴ָ��ҳ��                              |\n";
	cout << "\t\t\t\t|---->  6���½�һҳ                                  |\n";
	cout << "\t\t\t\t|---->  7��ɾ��ָ��ҳ                                |\n";
	cout << "\t\t\t\t|---->  8���༭                                      |\n";
	cout << "\t\t\t\t|---->  9���������˵�                                |\n";
	cout << "\t\t\t\t|  ע��ָ������Ҫ�༭��ҳ��������༭���ɽ���༭ҳ��|\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	int choice, temp = 1;
	while (temp == 1)
	{	
		Show_Page(pages,text);//��ʾ��ǰҳ������
		cout << "\t\t\t\t\t���ı�����" << text.context.size() << "ҳ����ǰ�ڵ�" << pages << "ҳ" << endl;
		cout << "����������ѡ��";
		temp = 0;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case 1:
			Next_Page(pages, text);
			break;
		case 2:
			//�鿴��һҳ�Ĳ���
			Pervious_Page(pages, text);
			break;
		case 3:
			//�鿴���һҳ�Ĳ���
			Final_Page(pages, text);
			break;
		case 4:
			Begin_Page(pages, text);
			//�鿴��һҳ�Ĳ���
			break;
		case 5:
			//�鿴ָ��ҳ��������
			Sure_page(pages, text);
			break;
		case 6:
			//�½�һҳ
			Add_page(pages, text);
			break;
		case 7:
			//ɾ��һҳ
			Delete_page(pages, text);
			break;
		case 8:
			//���У��༭�������Ա༭���棬����Ҫ������ҳ��
			if (text.voke[pages - 1].v.size() == 0)//����һ�ν����ҳ�ı༭��������ԭ��ҳ�����ݱ���
			{
				text.voke[pages - 1].Add_Voke(text.context[pages - 1],text.voke[pages-1]);
			}
			Edit_Page_Text(text,pages);
			break;
		case 9:
			//�������˵�
			Operator_Main_Menu(text);
			break;
		default:
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
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
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��һҳ����ʧ�ܣ��Ѿ�Ϊ���һҳ�����������ı�Ŀ¼�˵�!\n";
	    cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	    getchar();
	    Edit_Text(text,pages);
	}
	else {
        pages++;
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��һҳ�����ɹ������������ı�Ŀ¼�˵�!\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��һҳ����ʧ�ܣ��Ѿ�Ϊ��һҳ�����������ı�Ŀ¼�˵�!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Edit_Text(text, pages);
	}
	else {
		pages--;
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��һҳ�����ɹ������������ı�Ŀ¼�˵�!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Edit_Text(text, pages);
	}
}
void Final_Page(size_t& pages, Text& text)
{
	system("cls");
	pages = text.context.size();
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴���ҳ�����ɹ������������ı�Ŀ¼�˵�!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text,pages);
}
void Begin_Page(size_t& pages, Text& text)
{
	system("cls");
	pages = 1;
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��һҳ�����ɹ������������ı�Ŀ¼�˵�!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text,pages);
}
void Sure_page(size_t& pages,Text& text)
{
	cout << "����Ҫ�鿴��ҳ��: ";
	size_t n;
	cin >> n;
	getchar();
	system("cls");
	if (n<1 || n>text.context.size())
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��" << n << "ҳ����ʧ�ܣ�������������Чҳ�룬���������ı�Ŀ¼�˵�!\n";
	}
	else {
		pages = n;
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  �鿴��" << pages << "ҳ�����ɹ������������ı�Ŀ¼�˵�!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\n press Enter to continue...";
	getchar();
	Edit_Text(text, pages);
}
void Add_page(size_t& pages, Text& text)
{
	cout << "�������½�ҳ��ҳ��:  ";
	size_t n;
	cin >> n;
	pages = n;
	getchar();
	if (n<1 || n>text.context.size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���һҳ�ı�����ʧ�ܣ��½�ҳ��ҳ�벻�Ϸ������������ı�Ŀ¼�˵�!\n";
	}
	else {
		cout << "������Ҫ���ҳ���ı�(������Ӳ��ɳ���20��,�Ե���һ��end�������,Ĭ�ϼ���ָ��ҳ��ǰһҳ)" << endl;
		string lines;
		vector<string>* group = new vector<string>;//��һ����̬�ڴ�����ʱ��Ŷ��������ı�
		while (getline(cin, lines) && lines != "end")
		{
			text.Read_Line(lines, group);
		}
		Page page;
		Line line;
		size_t l = 40;//Ĭ��һ�д�40������
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
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ���һҳ�ı������ɹ������������ı�Ŀ¼�˵�!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text, pages);
}
void Delete_page(size_t& pages, Text& text)
{
	cout << "������ɾ��ҳ��ҳ�룺 ";
	size_t n;
	cin >> n;
	pages = n;
	getchar();
	if (n<1 || n>text.context.size())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ɾ��һҳ�ı�����ʧ�ܣ�ɾ��ҳ��ҳ�벻�Ϸ������������ı�Ŀ¼�˵�!\n";
	}
	else {
	    text.context.erase(text.context.begin() + pages - 1);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\t  ɾ����ҳ�ı������ɹ������������ı�Ŀ¼�˵�!\n";
	}
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Edit_Text(text, pages);
}
