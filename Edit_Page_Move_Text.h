#pragma once
#ifndef EDIT_PAGE_MOVE_H
#define EDIT_PAGE_MOVE_H
#include<iostream>
#include"Text.h"
#include"Edit_Page_Text.h"
using namespace std;
void Edit_Page_Move_Text(Text& text,size_t& pages);
void Edit_Page_Move_Next_Line(Text& text, size_t& pages);
void Edit_Page_Move_Pervious_Line(Text& text, size_t& pages);
void Edit_Page_Move_Left_Column(Text& text, size_t& pages);
void Edit_Page_Move_Right_Column(Text& text, size_t& pages);
#endif 
