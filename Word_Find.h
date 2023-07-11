#pragma once
#ifndef WORD_FIND_H
#define WORD_FIND_H
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
using line_no = vector<string>::size_type;
class TextQuery {
public:
	TextQuery(vector< vector<string> >&);
	map<string, shared_ptr<set<line_no> > > wm;
	void query(string& s);
};
#endif