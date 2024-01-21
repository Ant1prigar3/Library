#define _CRT_SECURE_NO_WARNINGS

#include "library.h"
#include "book.h"
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

///////////////////////////////////////////////
extern char cat[8][100];
//������� ���������� ���� �� ���������
void CatCount(LIB& myCart, int num) {
	char str[100];
	int kol = 0;
	for (int i = 0; i < 100; i++)
	{
		str[i] = cat[num][i];
	}
	for (int i = 0; i < myCart.count; i++)
	{
		if (strcmp(myCart.books[i]->category, str) == 0) {
			kol++;
		}
	}
	printf("\n���� � ������ ���������� %d.\n\n", kol);
}
//���������� ����� ����� � ���������
void �reatbook(LIB& myCart) {
	if (myCart.count < myCart.maxlen) {
		myCart.books[myCart.count] = new BOOK;
		InputBK(myCart.books[myCart.count]);
		myCart.count++;
	}
	else {
		printf("\n� ���������, ��������� ��������� ���������, ���������� ������� ���� ����.\n\n");
	}
}
//����� ����������� ���������
void PrintLib(LIB& myCart) {
	if (myCart.count) {
		for (int i = 0; i < myCart.count; i++)
		{
			printf("����� ����� <%d>:", (i + 1));
			PrintBK(myCart.books[i]);
		}
	}
	else {
		printf("\n� ���������, � ��������� ��� �� ����� �����, ���������� �� ��������.\n\n");
	}
}
//�������� ����� ����������� ��������
void DeleteLib(LIB& myCart) {
	for (int i = 0; i < myCart.count; i++)
	{
		delete myCart.books[i];
	}
	delete[] myCart.books;
}
//�������� ������������ ����
void DeleteBK(LIB& myCart, int start, int end) {
	int x = myCart.count;
	for (int i = start; i <= end; i++)
	{
		delete myCart.books[i];
		myCart.count--;
	}
	for (int j = 0; j < (end - start + 1); j++)
	{
		for (int i = start; i < x; i++)
		{
			myCart.books[i] = myCart.books[i + 1];
		}
	}
}