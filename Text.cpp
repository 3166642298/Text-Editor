#include"Text.h"
//Ӣ�ĵ�����һ�������ʱ��棬�������Ե����ַ�����
void Text::Read_Line(string& line,vector<string>* group)
{
	string s = "";
	for (int i = 0; i < line.size(); i++)
	{
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
		{
			s = s + line[i];//ʵ��Ӣ�ĵ��ʵ�����
			if (i == line.size() - 1)
			{
				(*group).push_back(s);
			}//��ֹ��һ���ı�����������Ӣ�ĵ���
		}
		else {
			if (s != "")//��ʾs�Ѿ������ַ������൱���Ѿ�����һ��Ӣ�ĵ��ʣ��Ƚ�֮ǰ�ı���
			{
				(*group).push_back(s);
			}
			s = line[i];
			(*group).push_back(s);//�����ַ�����
			s = "";
		}
	}
}
void Text::Save_Line(Text& text, vector<string>* group)
{
	Page page;
	Line line;
	size_t l = 40;//Ĭ��һ�д�40������
	size_t p = 20;//Ĭ��һҳ��20��
	if (text.context.size() != 0 && text.context[text.context.size() - 1].size() < p)
	{
		page.insert(page.begin(), text.context[text.context.size() - 1].begin(), text.context[text.context.size() - 1].end());
		if (page.size() != 0 && page[page.size() - 1].size() < l)
		{
			line.insert(line.begin(), page[page.size() - 1].begin(), page[page.size() - 1].end());
		}
	}
	for (string word :(*group))
	{
		line.push_back(word);
		if (line.size() == l)//һ���Ѿ�����l������ʱ��ʵ�ֻ���
		{
			if (page.size() == p)//һҳ�Ѿ�����p���ı���ʵ�ֻ�ҳ
			{
				text.context.push_back(page);//��Page������text������
				page.clear();
				page.push_back(line);
			}
			page.push_back(line);//��Line���浽Page��
			line.clear();
		}
    }
	if (line.size() != 0)
	{
		page.push_back(line);
	}
	if (page.size() != 0) {
		text.context.push_back(page);
	}
}
void Voke::Add_Voke(Page page,Voke& voke)
{
	voke.v.push_back(page);//�����ĺ��ҳ�����ݱ��浽voke������
	voke.count++;//�����ҳ�����˼��θ���
}
void Voke::Push_Up_Voke(Voke& voke)
{
	voke.v.erase(voke.v.begin() + voke.count, voke.v.end());//����voke����
}
void Voke::Revoke(Voke& voke, Text& text,size_t pages)
{
	voke.count -= 2;
	text.context[pages-1] = voke.v[voke.count];//��voke������ָ��������ȥ�滻text�ж�Ӧҳ������
	voke.count++;
}
void Voke::Recove(Voke& voke, Text& text,size_t pages)
{
	text.context[pages-1] = voke.v[voke.count];//��voke������ָ��������ȥ�滻text�ж�Ӧҳ������
	voke.count++;
}