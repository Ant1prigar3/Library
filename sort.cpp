#define _CRT_SECURE_NO_WARNINGS

#include "fun_of_print_input.h"
#include "library.h"
#include <cstdio>
#include <tchar.h>
#include <iostream>
#include <Windows.h>

///////////////////////////////////////////////
extern char cat[8][100];
//сортировка оптимальным пузырьком
void Sort(LIB& myCart, char c) {
	if (c == 'a') {
		int x = myCart.count;
		for (int i = 0; i < x; i++) {
			bool flag = true;
			for (int j = 0; j < x - (i + 1); j++) {
				if (strcmp(myCart.books[j]->autor, myCart.books[j + 1]->autor) > 0) {
					flag = false;
					BOOK* tmp = myCart.books[j];
					myCart.books[j] = myCart.books[j + 1];
					myCart.books[j + 1] = tmp;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	if (c == 't') {
		int x = myCart.count;
		for (int i = 0; i < x; i++) {
			bool flag = true;
			for (int j = 0; j < x - (i + 1); j++) {
				if (strcmp(myCart.books[j]->title, myCart.books[j + 1]->title) > 0) {
					flag = false;
					BOOK* tmp = myCart.books[j];
					myCart.books[j] = myCart.books[j + 1];
					myCart.books[j + 1] = tmp;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	if (c == 'y') {
		int x = myCart.count;
		for (int i = 0; i < x; i++) {
			bool flag = true;
			for (int j = 0; j < x - (i + 1); j++) {
				if (myCart.books[j]->year > myCart.books[j + 1]->year) {
					flag = false;
					BOOK* tmp = myCart.books[j];
					myCart.books[j] = myCart.books[j + 1];
					myCart.books[j + 1] = tmp;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	if (c == 'p') {
		int x = myCart.count;
		for (int i = 0; i < x; i++) {
			bool flag = true;
			for (int j = 0; j < x - (i + 1); j++) {
				if (myCart.books[j]->price > myCart.books[j + 1]->price) {
					flag = false;
					BOOK* tmp = myCart.books[j];
					myCart.books[j] = myCart.books[j + 1];
					myCart.books[j + 1] = tmp;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	if (c == 'c') {
		int x = myCart.count;
		for (int i = 0; i < x; i++) {
			bool flag = true;
			for (int j = 0; j < x - (i + 1); j++) {
				if (strcmp(myCart.books[j]->category, myCart.books[j + 1]->category) > 0) {
					flag = false;
					BOOK* tmp = myCart.books[j];
					myCart.books[j] = myCart.books[j + 1];
					myCart.books[j + 1] = tmp;
				}
			}
			if (flag) {
				break;
			}
		}
	}
}