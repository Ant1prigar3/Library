#pragma once

enum { name_len = 60, title_len = 120, cat_len = 50 };
struct BOOK {
	char autor[name_len]{};
	char title[title_len]{};
	int year;
	double price;
	char category[cat_len]{};
};
extern char cat[8][100];
void CopyBK(BOOK* bk, char aut[], char tit[], int yr, double pr, char cat[]);
void InputBK(BOOK* bk);
void PrintBK(BOOK* bk);
