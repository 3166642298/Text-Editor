#include"Main_Menu.h"
void Show_Main_Menu(Text& text)
{
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcom to use TXT edition system!\n";
	cout << "\n\n\t\t\t\t\t     ��ӭʹ�ü����ı��༭��!\n";
	cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
	char ch = getchar();
	Operator_Main_Menu(text);
}
void Operator_Main_Menu(Text& text)
{
	system("cls");
	cout << "\t\t\t\t ____________________________________________________\n";
	cout << "\t\t\t\t|                      ���˵�                        |\n";
	cout << "\t\t\t\t|---->  1��������������                              |\n";
	cout << "\t\t\t\t|---->  2������༭�˵�                              |\n";
	cout << "\t\t\t\t|---->  3�������ı�                                  |\n";
	cout << "\t\t\t\t|---->  4���˳��ı��༭��                            |\n";
	cout << "\t\t\t\t|                                                    |\n";
	cout << "\t\t\t\t|    ע����һ�����б�����ʱ��ѡ����1               |\n";
	cout << "\t\t\t\t|____________________________________________________|\n";
	cout << "����������ѡ��: ";
	int choice, temp=0;
	size_t p = 1;//�����һ�β鿴��ҳ��
	while (temp == 0)//����ʵ�ֵ��û����벻���ڵĹ��ܴ��ŵ�����ʱ�������û�������ȷ��ѡ��
	{
		temp = 1;
		cin >> choice;
		switch (choice)
		{
		  case 1:
			Enter_Text(text);//�����������ݣ��˺�����Enter_Text.cpp�ļ��ڶ���
			break;
		  case 2:
			Edit_Text(text,p);//ÿ�ν���༭�˵���Ĭ�ϴӵ�һҳ��ʼ�鿴���˺�����Edit_Text.cpp�ļ��ڶ���
			break;
		  case 3:
			Save_Text(text);//�����ı����˺�����Save_Text.cpp�ļ��ڶ���
			break;
		  case 4:
			Exit_Text(text);//�˳��ı����������˺�����Exit_Text.cpp�ļ��ڶ���
			break;
		  default:
			cout << "��ѡ����ڣ���������ȷ��ѡ��" << endl;
			temp = 0;
			break;
		}
	}
}