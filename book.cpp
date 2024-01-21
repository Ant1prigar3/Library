 #define _CRT_SECURE_NO_WARNINGS

#include "book.h"
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

///////////////////////////////////////////////
char cat[8][100] = { "проза", "фэнтези", "детектив",
		"комедия", "роман", "наука", "приключения", "сказки" };
//создание новой книги, зная все данные из файла.
void CopyBK(BOOK* bk, char aut[], char tit[], int yr, double pr, char cat1[]) {
	strncpy(bk->autor, aut, name_len);
	bk->autor[name_len - 1] = '\0';
	strncpy(bk->title, tit, title_len);
	bk->title[title_len - 1] = '\0';
	bk->year = yr;
	bk->price = pr;
	strcpy(bk->category, cat1);
	bk->category[cat_len - 1] = '\0';
}
//функция добавления новой книги.
void InputBK(BOOK* bk) {
	printf("\nДобавление новой книги.\n");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//автор
	char temp_aut[300]{};
	printf("Введите автора: ");
	scanf("%299[^\n]", temp_aut);		
	strncpy(bk->autor, temp_aut, name_len);
	bk->autor[name_len - 1] = '\0';

	//название
	char temp_tt[300]{};
	printf("Введите название: ");
	while (getchar() != '\n');
	scanf("%299[^\n]", temp_tt);
	strncpy(bk->title, temp_tt, title_len);
	bk->title[title_len - 1] = '\0';

	//год
	int temp_y;
	printf("Введите год издания: ");
	while (true) {
		while (getchar() != '\n');
		scanf("%d", &temp_y);
		if (temp_y >= -3000 && temp_y <= 2024) break;
		else printf("Некорректный ввод. Введите год издания заново: ");
	}
	bk->year = temp_y;

	//стоимость
	double temp_p;
	printf("Введите стоимость: ");
	while (true) {
		while (getchar() != '\n');
		scanf("%lf", &temp_p);
		if (temp_p > 0) break;
		else printf("Некорректный ввод. Введите стоимость заново: ");
	}
	bk->price = temp_p;

	//жанр
	int num;
	printf(
		"Введите номер категории\n('0' - проза, '1' - фэнтези,"
		"'2' - детектив, '3' - комедия," 
		" '4' - роман, '5' - наука, '6' - приключения, '7' - сказки): "
	);
	while (true) {
		while (getchar() != '\n');
		scanf("%d", &num);
		if (num >= 0 && num <= 7) break;
		else printf("Некорректный ввод. Введите номер категории заново: ");
	}
	strcpy(bk->category, cat[num]);
	while (getchar() != '\n');
}
//вывод одной книги.
void PrintBK(BOOK* bk) {
	printf(
		"\nАвтор - %s;\nНазвание - '%s';\nГод издания - %d;"
		"\nСтоимость - %lf; \nЖанр - %s;\n\n",
		 bk->autor, bk->title, bk->year, bk->price, bk->category);
}