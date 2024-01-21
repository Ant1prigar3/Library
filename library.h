#pragma once

#include "book.h"

struct LIB {
	BOOK** books;
	int count;
	int maxlen;
};

void CatCount(LIB& myCart, int num);
void Ñreatbook(LIB& myCart);
void PrintLib(LIB& myCart);
void DeleteLib(LIB& myCart);
void DeleteBK(LIB& myCart, int start = 0, int end = 0);