#include"Word_Find.h"
TextQuery::TextQuery(vector< vector<string> >& h)
{
	int n = 1;
	for (auto a : h)
	{
		for (auto b : a)
		{
			auto& lines = wm[b];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
		n++;
	}
}
void TextQuery::query(string& s)
{
	system("cls");
	auto iter = wm.find(s);
	if (iter != wm.end())
	{
		cout << "�ı�" + s + "�������г��ֹ�" << endl;
		for (auto s : *wm[s])
		{
			cout << s << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "�ı�" + s + "�ڸ�ҳû�г��ֹ�" << endl;
	}
	cout << "\n\n\n\n\n\n\npress Enter to continue...";
	getchar();
}