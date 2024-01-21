#pragma once
#include "library.h"

void PrintMenu();
void PrintSortMenu();
void PrintDelMenu();
void PrintList();
void PrintCat();
char ScanMenu();
int ScanCat();
bool ScanDelOne(LIB& myCart);
bool ScanDelInter(LIB& myCart);
char Choise();
void ScanSortDel(bool f, LIB& myCart);
int ScanImp();
void ExportInFile(LIB& myCart);
bool ImportFromFile(LIB& myCart, int name);