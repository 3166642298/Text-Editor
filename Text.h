#pragma once
#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef vector<string> Line;//代表一行文本，Line的基本单元是string；Line的下表即可代表列号
typedef vector<Line>  Page;//代表一页文章,Page的基本单元是Line，Page的下表即可代表行号
typedef vector<Page> Context;//代表一整个文本，Context的基本单元是Page,Context的下标即可代表页码
class Voke;
class Text {
    public:
        Context context;//存储文本,相当于一个三维容器
        map<size_t, Voke> voke;//用一个map容器，保存每一页的撤销和回退操作，键是页码，值是保存该页所有的操作
        void Read_Line(string& line, vector<string>* group);//用来读取给定字符串，将里面的文本提取出来，然后保存在动态内存group中
        void Save_Line(Text& text, vector<string>* group);//将保存在group中的文本，保存到text对象中，真正实现文本的保存
};
/*
    Voke类实现撤销和回退操作，该文本编译器撤销和回退操作的实现原理：每进行一次操作后
，将改变后该页的内容保存在一个容器中，进行撤销和回退操作时取出该容器之前保存的页，去
替换当前页
*/
class Voke {
    public:
       vector<Page> v;//用来保存每次变更操作后，该页的内容
       int count;//用来表示撤销和回退操作进行到哪一步了
       void Add_Voke(Page page, Voke& voke);//该函数实现对该页文章内容更改的保存
       void Push_Up_Voke(Voke& voke);//更新v容器所保存的撤销和回退操作，主要模仿实现word的撤销和回退操作
       void Revoke(Voke& voke, Text& text, size_t pages);//进行撤销操作会调用该函数
       void Recove(Voke& voke, Text& text, size_t pages);//进行回退操作会调用该函数
};
#endif