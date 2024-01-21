 #define _CRT_SECURE_NO_WARNINGS

#include "book.h"
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

///////////////////////////////////////////////
char cat[8][100] = { "�����", "�������", "��������",
		"�������", "�����", "�����", "�����������", "������" };
//�������� ����� �����, ���� ��� ������ �� �����.
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
//������� ���������� ����� �����.
void InputBK(BOOK* bk) {
	printf("\n���������� ����� �����.\n");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//�����
	char temp_aut[300]{};
	printf("������� ������: ");
	scanf("%299[^\n]", temp_aut);		
	strncpy(bk->autor, temp_aut, name_len);
	bk->autor[name_len - 1] = '\0';

	//��������
	char temp_tt[300]{};
	printf("������� ��������: ");
	while (getchar() != '\n');
	scanf("%299[^\n]", temp_tt);
	strncpy(bk->title, temp_tt, title_len);
	bk->title[title_len - 1] = '\0';

	//���
	int temp_y;
	printf("������� ��� �������: ");
	while (true) {
		while (getchar() != '\n');
		scanf("%d", &temp_y);
		if (temp_y >= -3000 && temp_y <= 2024) break;
		else printf("������������ ����. ������� ��� ������� ������: ");
	}
	bk->year = temp_y;

	//���������
	double temp_p;
	printf("������� ���������: ");
	while (true) {
		while (getchar() != '\n');
		scanf("%lf", &temp_p);
		if (temp_p > 0) break;
		else printf("������������ ����. ������� ��������� ������: ");
	}
	bk->price = temp_p;

	//����
	int num;
	printf(
		"������� ����� ���������\n('0' - �����, '1' - �������,"
		"'2' - ��������, '3' - �������," 
		" '4' - �����, '5' - �����, '6' - �����������, '7' - ������): "
	);
	while (true) {
		while (getchar() != '\n');
		scanf("%d", &num);
		if (num >= 0 && num <= 7) break;
		else printf("������������ ����. ������� ����� ��������� ������: ");
	}
	strcpy(bk->category, cat[num]);
	while (getchar() != '\n');
}
//����� ����� �����.
void PrintBK(BOOK* bk) {
	printf(
		"\n����� - %s;\n�������� - '%s';\n��� ������� - %d;"
		"\n��������� - %lf; \n���� - %s;\n\n",
		 bk->autor, bk->title, bk->year, bk->price, bk->category);
}