#pragma once
#ifndef EDIT_PAGE_DELETE_TEXT_H
#define EDIT_PAGE_DELETE_TEXT_H
#include<iostream>
#include"Text.h"
#include"Edit_Page_Text.h"
using namespace std;
void Edit_Page_Delete_Text(Text& text,size_t& pages);
void Edit_Page_Delete_One(Text& text, size_t& pages);
void Edit_Page_Delete_Line(Text& text, size_t& pages);
void Edit_Page_Delete_Page(Text& text, size_t& pages);
#endif 
