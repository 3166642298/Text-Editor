#pragma once
#ifndef EDIT_PAGE_TEXT_H
#define EDIT_PAGE_TEXT_H
#include<iostream>
#include"Word_Find.h"
#include"Text.h"
#include"Edit_Text.h"
#include"Edit_Page_Move_Text.h"
#include"Edit_Page_Add_Text.h"
#include"Edit_Page_Delete_Text.h"
using namespace std; 
void Edit_Page_Text(Text& text,size_t& pages);
void Edit_Page_Find_Text(Text& text, size_t& pages);
void Edit_Page_Replace_Text(Text& text, size_t& pages);
void Edit_Page_Revoke_Text(Text& text, size_t& pages);
void Edit_Page_Recove_Text(Text& text, size_t& pages);
#endif
