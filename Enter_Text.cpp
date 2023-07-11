#include"Enter_Text.h"
void Enter_Text(Text& text)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                ���ļ��˵�                        |\n";
	cout << "\t\t\t\t|---->  1���������ļ�                              |\n";
	cout << "\t\t\t\t|---->  2���½��հ��ĵ�                              |\n";
	cout << "\t\t\t\t|---->  3���������˵�                                |\n";
	cout << "\t\t\t\t|    ע���½��հ��ĵ�Ĭ�ϸ��ĵ�δ���б����������    |\n";
	cout << "\t\t\t\t|        ���б���                                    |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "����������ѡ��: ";
	int choice, temp = 0;
	while (temp == 0)
	{
		temp = 1;
		cin >> choice;
		switch (choice)
		{
		  case 1:
			Enter_Open_File(text);//�������ļ��������ļ��е����ݱ�����text��
			break;
		  case 2:
		    Enter_New_File(text);//�˽��հ��ĵ���֧���û��Լ������ı�������֧�ֺ����ٴα༭��Ĭ��������ı�β����
			break;
		  case 3:
			Operator_Main_Menu(text);//�������˵�
		    break;
		  default:
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
			temp = 0;
			break;
		}
	}
}
void Enter_New_File(Text& text)
{
	//�½�һ���յ����ݣ�
	system("cls");
	cout << "��������Ҫ�༭�����ݣ��Ե�������һ��end��β��" << endl;
	string line;
	vector<string>* group = new vector<string>;//��һ����̬�ڴ�����ʱ��Ŷ��������ı�
	while (cin>>line&&line!="end")
	{
		text.Read_Line(line, group);//ѭ������ÿһ�У��˺�����Text.cpp����
	}
	text.Save_Line(text, group);//ʵ���ı����浽text�У��˺�����Text.cpp����
	delete group;//�ı��Ѿ�������text�У����ͷ�group���ڴ棬�����ڴ��ʹ��
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t�½��հ��ĵ��ɹ��������������˵�!\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
	Operator_Main_Menu(text);//�������˵�
}
void Enter_Open_File(Text& text)
{
	system("cls");
	cout << "��������Ҫ�򿪵��ļ���(����:myfile.txt): ";
	string file_name;
	cin >> file_name;//���ļ����ļ���
	getchar();
	ifstream ifs(file_name, ios::in);
	system("cls");
	if (!ifs.is_open())//������ļ�����Ӧ���ļ�������
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t���ļ�����Ӧ���ļ������ڣ��ļ���ʧ�ܣ�����������!\n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		Enter_Text(text);
	}
	else {
		string line;
		vector<string> *group=new vector<string>;//��һ����̬�ڴ�����ʱ��Ŷ��������ı�
		while (getline(ifs, line))
		{
			text.Read_Line(line,group);
		}
		text.Save_Line(text,group);
		delete group;//�ı��Ѿ�������text�У����ͷ�group���ڴ�
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t�ļ���ȡ�ɹ��������������˵�!\n";
		cout << "\n\n\n\n\n\n\n\n\n\n\npress Enter to continue...";	
		ifs.close();
		getchar();
		Operator_Main_Menu(text);
	}
}
