#include"Exit_Text.h"
void Exit_Text(Text& text)
{
	system("cls");
	cout << "\t\t\t\t\t���ٴ�ȷ���Ƿ��˳��ı�������(Y/N)!\n";
	char ch = getchar();
	cin >> ch;
	getchar();
	system("cls");
	if (ch == 'Y')
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t�����˳��ı�������ϵͳ����ӭ�����ٴ�ʹ��!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
		getchar();
		exit(0);
	}
	else if (ch == 'N')
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t�˳��ı�������ϵͳʧ�ܣ����ٴ�ѡ��!\n";
		cout << "\n\n\n\n\n\n\n\n\npress Enter to continue...";
        getchar();
		system("cls");
		Operator_Main_Menu(text);
	}
}