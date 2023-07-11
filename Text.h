#pragma once
#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef vector<string> Line;//����һ���ı���Line�Ļ�����Ԫ��string��Line���±��ɴ����к�
typedef vector<Line>  Page;//����һҳ����,Page�Ļ�����Ԫ��Line��Page���±��ɴ����к�
typedef vector<Page> Context;//����һ�����ı���Context�Ļ�����Ԫ��Page,Context���±꼴�ɴ���ҳ��
class Voke;
class Text {
    public:
        Context context;//�洢�ı�,�൱��һ����ά����
        map<size_t, Voke> voke;//��һ��map����������ÿһҳ�ĳ����ͻ��˲���������ҳ�룬ֵ�Ǳ����ҳ���еĲ���
        void Read_Line(string& line, vector<string>* group);//������ȡ�����ַ�������������ı���ȡ������Ȼ�󱣴��ڶ�̬�ڴ�group��
        void Save_Line(Text& text, vector<string>* group);//��������group�е��ı������浽text�����У�����ʵ���ı��ı���
};
/*
    Voke��ʵ�ֳ����ͻ��˲��������ı������������ͻ��˲�����ʵ��ԭ��ÿ����һ�β�����
�����ı���ҳ�����ݱ�����һ�������У����г����ͻ��˲���ʱȡ��������֮ǰ�����ҳ��ȥ
�滻��ǰҳ
*/
class Voke {
    public:
       vector<Page> v;//��������ÿ�α�������󣬸�ҳ������
       int count;//������ʾ�����ͻ��˲������е���һ����
       void Add_Voke(Page page, Voke& voke);//�ú���ʵ�ֶԸ�ҳ�������ݸ��ĵı���
       void Push_Up_Voke(Voke& voke);//����v����������ĳ����ͻ��˲�������Ҫģ��ʵ��word�ĳ����ͻ��˲���
       void Revoke(Voke& voke, Text& text, size_t pages);//���г�����������øú���
       void Recove(Voke& voke, Text& text, size_t pages);//���л��˲�������øú���
};
#endif