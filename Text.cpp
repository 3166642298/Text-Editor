#include"Text.h"
//英文单词以一整个单词保存，其他则以单个字符保存
void Text::Read_Line(string& line,vector<string>* group)
{
	string s = "";
	for (int i = 0; i < line.size(); i++)
	{
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
		{
			s = s + line[i];//实现英文单词的连接
			if (i == line.size() - 1)
			{
				(*group).push_back(s);
			}//防止该一行文本最后输入的是英文单词
		}
		else {
			if (s != "")//表示s已经存了字符，即相当于已经存了一个英文单词，先将之前的保存
			{
				(*group).push_back(s);
			}
			s = line[i];
			(*group).push_back(s);//单个字符保存
			s = "";
		}
	}
}
void Text::Save_Line(Text& text, vector<string>* group)
{
	Page page;
	Line line;
	size_t l = 40;//默认一行存40个单词
	size_t p = 20;//默认一页存20行
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
		if (line.size() == l)//一行已经存了l个单词时，实现换行
		{
			if (page.size() == p)//一页已经存了p行文本后，实现换页
			{
				text.context.push_back(page);//将Page保存在text容器中
				page.clear();
				page.push_back(line);
			}
			page.push_back(line);//将Line保存到Page中
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
	voke.v.push_back(page);//将更改后该页的内容保存到voke容器中
	voke.count++;//计算该页进行了几次更改
}
void Voke::Push_Up_Voke(Voke& voke)
{
	voke.v.erase(voke.v.begin() + voke.count, voke.v.end());//更新voke容器
}
void Voke::Revoke(Voke& voke, Text& text,size_t pages)
{
	voke.count -= 2;
	text.context[pages-1] = voke.v[voke.count];//用voke容器中指定的内容去替换text中对应页的内容
	voke.count++;
}
void Voke::Recove(Voke& voke, Text& text,size_t pages)
{
	text.context[pages-1] = voke.v[voke.count];//用voke容器中指定的内容去替换text中对应页的内容
	voke.count++;
}