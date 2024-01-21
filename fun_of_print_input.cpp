#define _CRT_SECURE_NO_WARNINGS

#include "fun_of_print_input.h"
#include "library.h"
#include "sort.h"
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

///////////////////////////////////////////////
extern char cat[8][100];
//�������� ������� - ����� �� ������ �����
void PrintMenu() {
	printf("�������� ���� � ������������� ����������:\n");
	printf(" 1. ['n'] - �������� ����� �����.\n");
	printf(" 2. ['p'] - ������� ���������� ���������.\n");
	printf(" 3. ['s'] - ���� ����������.\n");
	printf(" 4. ['d'] - ���� �������� �����.\n");
	printf(" 5. ['e'] - ������ ���������� � ����.\n");
	printf(" 6. ['i'] - ������������� ����� �� �����.\n");
	printf(" 7. ['�'] - ������� �������.\n");
	printf(" 8. ['k'] - ���������� ���� ������������ ���������.\n");
	printf(" 9. ['f'] - ��������� ������ ���������.\n");
}
void PrintSortMenu() {
	printf("���� � ������������� ���������� ���������:\n");
	printf(" 1. ['a'] - ����������� �� ������.\n");
	printf(" 2. ['t'] - ����������� �� ��������.\n");
	printf(" 3. ['p'] - ����������� �� ����.\n");
	printf(" 4. ['y'] - ����������� �� ���� �������.\n");
	printf(" 5. ['c'] - ����������� �� ���������.\n");
	printf(" 6. ['b'] - ��������� � ������� ����.\n");
}
void PrintDelMenu() {
	printf("���� � ������������� �������� ���� �� ���������:\n");
	printf(" 1. ['o'] - ������� ���� �����.\n");
	printf(" 2. ['i'] - ������� �������� ����.\n");
	printf(" 3. ['a'] - ������� ��� �����.\n");
	printf(" 4. ['b'] - ��������� � ������� ����.\n");
}
void PrintList() {
	printf(" 1. 'import1.txt'\n");
	printf(" 2. 'import2.txt'\n");
	printf(" 3. 'import3.txt'\n");
	printf(" 4. 'import4.txt'\n");
	printf(" 5. 'import5.txt'\n");
}
void PrintCat() {
	printf("�� ����� ��������� ��������� ���������� ����?");
	printf(" '0' - �����.\n");
	printf(" '1' - �������.\n");
	printf(" '2' - ��������.\n");
	printf(" '3' - �������.\n");
	printf(" '4' - �����.\n");
	printf(" '5' - �����.\n");
	printf(" '6' - �����������.\n");
	printf(" '7' - ������.\n");
}
//��������� ��������� �� ������� ����� ���������� ����
int ScanCat() {
	int res;
	printf("������� ����� ���������: ");
	while (true)
	{
		scanf("%d", &res);
		while (getchar() != '\n');
		if (res >= 0 || res <= 7) break;
		else printf("������������ ����. ������� ����� ��������� ������: ");
	}
	return res;
}
//��������� ������� �������.
char ScanMenu() {
	char c;
	printf("������� �������: ");
	scanf("%c", &c);
	while (getchar() != '\n');
	return c;
}
//������������� ������
char Choise() {
	char c;
	while (true)
	{
		scanf("%c", &c);
		while (getchar() != '\n');
		if (c == 'n' || c == 'y') break;
		else printf("������������ ����. ��������� �������. ������� ���� 'y' (YES), ���� 'n' (NO): ");
	}
	return c;
}
//��������� ������� �����, ������� ����� ����� ������� + ������� �� ��
bool ScanDelOne(LIB& myCart) {
	printf("\n����� � ��������� %d �����.\n\n", myCart.count);
	PrintLib(myCart);
	char yn;
	if (myCart.count > 1)
	{
		int ind;
		printf("������� ����� �����, ������� ������ �� �������: ");
		while (true) {
			scanf("%d", &ind);
			while (getchar() != '\n');;
			if (ind > 0 && ind <= myCart.count) break;
			else printf("������������ ����. ������� ����� ����� ������: ");
		}
		printf("�� ������������� ������ ������� ��� ����� ��� ����������� �� �������? ������� ���� 'y' (YES), ���� 'n' (NO): ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, (ind - 1), (ind - 1));
			printf("\n�������� ��������� �������. �������� � ������� ����.\n\n");
			return 1;
		}
	}
	else {
		printf("�� ������������� ������ ������� ��� ����� ��� ����������� �� �������? ������� ���� 'y' (YES), ���� 'n' (NO): ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, 0, 0);
			printf("\n�������� ��������� �������. �������� � ������� ����.\n\n");
			return 1;
		}
	}
	return 0;
}
//��������� ������� �����, ������� ����� ����� ������� + ������� �� �� (��������)
bool ScanDelInter(LIB& myCart) {
	printf("\n����� � ��������� %d �����.\n\n", myCart.count);
	PrintLib(myCart);
	char yn;
	if (myCart.count > 1)
	{
		int ind1, ind2;
		printf(
			"������� �������� ������� ����, ������� �� �� ������ �������\n"
			" (� ������ - 'k-m', ��� � - ����� ������ ����� � m - ����� �������� ����� ������������): ");
		while (true) {
			scanf("%d%*c%d", &ind1, &ind2);
			while (getchar() != '\n');;
			if (ind1 > 0 && ind2 <= myCart.count && ind2 > ind1) break;
			else printf("������������ ����. ������� �������� ������� ������: ");
		}
		printf("�� ������������� ������ ������� ��� ����� ��� ����������� �� �������? ������� ���� 'y' (YES), ���� 'n' (NO): ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, (ind1 - 1), (ind2 - 1));
			printf("\n�������� ��������� �������. �������� � ������� ����.\n\n");
			return 1;
		}
	}
	else {
		printf(
			"� ��������� ����� ���� �����. �� ������������� ������ ��" 
			"������� ��� ����������� �������? \n������� ���� 'y' (YES), ���� 'n' (NO) : ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, 0, 0);
			printf("\n�������� ��������� �������. �������� � ������� ����.\n\n");
			return 1;
		}
	}
	return 0;
}
//������� ��� ������ � ����������� � ���������.
void ScanSortDel(bool flag, LIB& myCart) {
	char com;
	if (flag) { //����������
		do
		{
			com = ScanMenu();
			switch (com)
			{
			case 'a': {
				Sort(myCart, 'a');
				printf("���������� �������! �������� � ������� ����.");
				PrintLib(myCart);
				return;
				break;
			}
			case 't': {
				Sort(myCart, 't');
				printf("\n���������� �������! �������� � ������� ����.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'p': {
				Sort(myCart, 'p');
				printf("\n���������� �������! �������� � ������� ����.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'y': {
				Sort(myCart, 'y');
				printf("\n���������� �������! �������� � ������� ����.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'c': {
				Sort(myCart, 'c');
				printf("\n���������� �������! �������� � ������� ����.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'b': {
				break;
			}
			default:
				printf("������������ ����, ��������� �������\n");
				break;
			}
		} while (com != 'b');
		return;
	}
	else { //��������
		do
		{
			com = ScanMenu();
			switch (com)
			{
			case 'o': {
				if (ScanDelOne(myCart)) return;
				break;
			}
			case 'i': {
				if (ScanDelInter(myCart)) return;
				break;
			}
			case 'a': {
				char yn;
				printf("\n����� � ��������� %d ����.\n\n", myCart.count);
				PrintLib(myCart);
				printf("�� ������������� ������ ������� ��� ����� ��� ����������� �� �������? ������� ���� 'y' (YES), ���� 'n' (NO): ");
				yn = Choise();
				if (yn == 'y') {
					DeleteBK(myCart, 0, myCart.count - 1);
					printf("\n�������� ��������� �������. �������� � ������� ����.\n\n");
					return;
				}
				break;
			}
			case 'b': {
				break;
			}
			default:
				printf("������������ ����, ��������� �������\n\n");
				break;
			}
		} while (com != 'b');
		return;
	}
}
//�������� ����� (����� ���� ������������� �� ������)
int ScanImp()
{
	int f;
	printf("�������� �� ������������� ������ ����, �� ��������"
		"���������� ������������� ������.\n");
	PrintList();
	printf("������� ����� �����: ");
	while (true) {
		scanf("%d", &f);
		while (getchar() != '\n');;
		if (f > 0 && f <= 5) break;
		else printf("������������ ����. ������� ����� ����� ������: ");
	}
	return f;
}
//������� �� ��������� � ����.
void ExportInFile(LIB& myCart) {
	FILE* f = fopen("cartoteka.txt", "w");
	fprintf(f, "%d\n", myCart.count);
	for (int i = 0; i < myCart.count; i++)
	{
		fprintf(f, "%d; %s; %s; %d; %lf; %s;\n",
			(i + 1), myCart.books[i]->autor, myCart.books[i]->title, 
			myCart.books[i]->year, myCart.books[i]->price, myCart.books[i]->category);
	}
	fclose(f);
}
//������ �� ����� � ���������.
bool ImportFromFile(LIB& myCart, int name) {
	setlocale(LC_ALL, "rus");
	int kol = 0, yr;
	char aut[100], tit[100], cat[100];
	FILE* f;
	f = fopen("import1.txt", "r+");
	double pr;
	switch (name){
	case 1: {
		fclose(f);
		f = fopen("import1.txt", "r+");
		break;
	}
	case 2: {
		fclose(f);
		f = fopen("import2.txt", "r+");
		break;
	}
	case 3: {
		fclose(f);
		f = fopen("import3.txt", "r+");
		break;
	}
	case 4: {
		fclose(f);
		f = fopen("import4.txt", "r+");
		break;
	}
	case 5: {
		fclose(f);
		f = fopen("import5.txt", "r+");
		break;
	}
	}
	fscanf(f, "%d\n", &kol);
	for (int i = myCart.count; i < (myCart.count + kol); i++)
	{
		fscanf(f, "%*d; %[^;]; %[^;]; %d; %lf; %[^;];\n",
			aut, tit, &yr, &pr, cat);
		if (i < myCart.maxlen) {
			myCart.books[i] = new BOOK;
			CopyBK(myCart.books[i], aut, tit, yr, pr, cat);
		}
		else {
			myCart.count += i + 1;
			printf("\n� ���������, ��������� ��������� ���������, ���������� ������� ���� ����.\n\n");
			fclose(f);
			return 0;
		}
	}
	myCart.count += kol;
	fclose(f);
	return 1;
}
