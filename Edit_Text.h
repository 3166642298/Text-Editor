#pragma once
#ifndef EDIT_TEXT_H
#define EDIT_TEXT_H
#include<iostream>
#include"Main_Menu.h"
#include"Text.h"
#include"Edit_Page_Text.h"
using namespace std;
void Edit_Text(Text& text,size_t& pages);
void Show_Page(size_t pages, Text& text);
void Next_Page(size_t& pages, Text& text);
void Pervious_Page(size_t& pages, Text& text);
void Final_Page(size_t& pages, Text& text);
void Begin_Page(size_t& pages, Text& text);
void Sure_page(size_t& pages, Text& text);
void Add_page(size_t& pages, Text& text);
void Delete_page(size_t& pages, Text& text);
#endif
