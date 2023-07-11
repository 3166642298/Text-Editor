#pragma once
#ifndef SAVE_TEXT_H
#define SAVE_TEXT_H
#include<iostream>
#include"Main_Menu.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Text.h"
using namespace std;
void Save_Text(Text& text);
void Save_File(Text text, string& file_name);
#endif