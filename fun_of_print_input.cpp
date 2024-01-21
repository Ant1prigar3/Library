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
//описание функций - вывод их первых строк
void PrintMenu() {
	printf("Основное меню с возможностями приложения:\n");
	printf(" 1. ['n'] - добавить новую книгу.\n");
	printf(" 2. ['p'] - вывести содержимое картотеки.\n");
	printf(" 3. ['s'] - меню сортировки.\n");
	printf(" 4. ['d'] - меню удаления книги.\n");
	printf(" 5. ['e'] - внести библиотеку в файл.\n");
	printf(" 6. ['i'] - импортировать книги из файла.\n");
	printf(" 7. ['с'] - очистка консоли.\n");
	printf(" 8. ['k'] - количество книг определенной категории.\n");
	printf(" 9. ['f'] - завершить работу программы.\n");
}
void PrintSortMenu() {
	printf("Меню с возможностями сортировки картотеки:\n");
	printf(" 1. ['a'] - сортировать по автору.\n");
	printf(" 2. ['t'] - сортировать по названию.\n");
	printf(" 3. ['p'] - сортировать по цене.\n");
	printf(" 4. ['y'] - сортировать по году издания.\n");
	printf(" 5. ['c'] - сортировать по категории.\n");
	printf(" 6. ['b'] - вернуться в главное меню.\n");
}
void PrintDelMenu() {
	printf("Меню с возможностями удаления книг из картотеки:\n");
	printf(" 1. ['o'] - удалить одну книгу.\n");
	printf(" 2. ['i'] - удалить диапозон книг.\n");
	printf(" 3. ['a'] - удалить все книги.\n");
	printf(" 4. ['b'] - вернуться в главное меню.\n");
}
void PrintList() {
	printf(" 1. 'import1.txt'\n");
	printf(" 2. 'import2.txt'\n");
	printf(" 3. 'import3.txt'\n");
	printf(" 4. 'import4.txt'\n");
	printf(" 5. 'import5.txt'\n");
}
void PrintCat() {
	printf("По какой категории вычислить количество книг?");
	printf(" '0' - проза.\n");
	printf(" '1' - фэнтези.\n");
	printf(" '2' - детектив.\n");
	printf(" '3' - комедия.\n");
	printf(" '4' - роман.\n");
	printf(" '5' - наука.\n");
	printf(" '6' - приключения.\n");
	printf(" '7' - сказки.\n");
}
//обработка категории по которой поиск количества книг
int ScanCat() {
	int res;
	printf("Введите номер категории: ");
	while (true)
	{
		scanf("%d", &res);
		while (getchar() != '\n');
		if (res >= 0 || res <= 7) break;
		else printf("Некорректный ввод. Введите номер категории заново: ");
	}
	return res;
}
//обработка символа команды.
char ScanMenu() {
	char c;
	printf("Введите команду: ");
	scanf("%c", &c);
	while (getchar() != '\n');
	return c;
}
//подтверждение выбора
char Choise() {
	char c;
	while (true)
	{
		scanf("%c", &c);
		while (getchar() != '\n');
		if (c == 'n' || c == 'y') break;
		else printf("Некорректный ввод. Повторите попытку. Введите либо 'y' (YES), либо 'n' (NO): ");
	}
	return c;
}
//обработка индекса книги, которую нужно будет удалить + удалили ли ее
bool ScanDelOne(LIB& myCart) {
	printf("\nВсего в картотеке %d книга.\n\n", myCart.count);
	PrintLib(myCart);
	char yn;
	if (myCart.count > 1)
	{
		int ind;
		printf("Введите номер книги, которую хотели бы удалить: ");
		while (true) {
			scanf("%d", &ind);
			while (getchar() != '\n');;
			if (ind > 0 && ind <= myCart.count) break;
			else printf("Некорректный ввод. Введите номер книги заново: ");
		}
		printf("Вы действительно хотите удалить эту книгу без возможности ее вернуть? Введите либо 'y' (YES), либо 'n' (NO): ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, (ind - 1), (ind - 1));
			printf("\nУдаление произошло успешно. Вернемся в главное меню.\n\n");
			return 1;
		}
	}
	else {
		printf("Вы действительно хотите удалить эту книгу без возможности ее вернуть? Введите либо 'y' (YES), либо 'n' (NO): ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, 0, 0);
			printf("\nУдаление произошло успешно. Вернемся в главное меню.\n\n");
			return 1;
		}
	}
	return 0;
}
//обработка индекса книги, которую нужно будет удалить + удалили ли ее (интервал)
bool ScanDelInter(LIB& myCart) {
	printf("\nВсего в картотеке %d книга.\n\n", myCart.count);
	PrintLib(myCart);
	char yn;
	if (myCart.count > 1)
	{
		int ind1, ind2;
		printf(
			"Введите диапозон номеров книг, которые Вы бы хотели удалить\n"
			" (в фомате - 'k-m', где к - номер первой книги и m - номер поледней книги включительно): ");
		while (true) {
			scanf("%d%*c%d", &ind1, &ind2);
			while (getchar() != '\n');;
			if (ind1 > 0 && ind2 <= myCart.count && ind2 > ind1) break;
			else printf("Некорректный ввод. Введите диапозон номеров заново: ");
		}
		printf("Вы действительно хотите удалить эти книги без возможности их вернуть? Введите либо 'y' (YES), либо 'n' (NO): ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, (ind1 - 1), (ind2 - 1));
			printf("\nУдаление произошло успешно. Вернемся в главное меню.\n\n");
			return 1;
		}
	}
	else {
		printf(
			"В картотеке всего одна книга. Вы действительно хотите ее" 
			"удалить без возможности вернуть? \nВведите либо 'y' (YES), либо 'n' (NO) : ");
		yn = Choise();
		if (yn == 'y') {
			DeleteBK(myCart, 0, 0);
			printf("\nУдаление произошло успешно. Вернемся в главное меню.\n\n");
			return 1;
		}
	}
	return 0;
}
//функция для работы с сортировкой и удалением.
void ScanSortDel(bool flag, LIB& myCart) {
	char com;
	if (flag) { //сортировка
		do
		{
			com = ScanMenu();
			switch (com)
			{
			case 'a': {
				Sort(myCart, 'a');
				printf("Сортировка успешна! Вернемся в главное меню.");
				PrintLib(myCart);
				return;
				break;
			}
			case 't': {
				Sort(myCart, 't');
				printf("\nСортировка успешна! Вернемся в главное меню.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'p': {
				Sort(myCart, 'p');
				printf("\nСортировка успешна! Вернемся в главное меню.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'y': {
				Sort(myCart, 'y');
				printf("\nСортировка успешна! Вернемся в главное меню.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'c': {
				Sort(myCart, 'c');
				printf("\nСортировка успешна! Вернемся в главное меню.\n");
				PrintLib(myCart);
				return;
				break;
			}
			case 'b': {
				break;
			}
			default:
				printf("Некорректный ввод, повторите попытку\n");
				break;
			}
		} while (com != 'b');
		return;
	}
	else { //удаление
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
				printf("\nВсего в картотеке %d книг.\n\n", myCart.count);
				PrintLib(myCart);
				printf("Вы действительно хотите удалить все книги без возможности их вернуть? Введите либо 'y' (YES), либо 'n' (NO): ");
				yn = Choise();
				if (yn == 'y') {
					DeleteBK(myCart, 0, myCart.count - 1);
					printf("\nУдаление произошло успешно. Вернемся в главное меню.\n\n");
					return;
				}
				break;
			}
			case 'b': {
				break;
			}
			default:
				printf("Некорректный ввод, повторите попытку\n\n");
				break;
			}
		} while (com != 'b');
		return;
	}
}
//проверка ввода (какой файл импортировать из списка)
int ScanImp()
{
	int f;
	printf("Выберите из предложенного списка файл, из которого"
		"необходимо импортировать данные.\n");
	PrintList();
	printf("Введите номер файла: ");
	while (true) {
		scanf("%d", &f);
		while (getchar() != '\n');;
		if (f > 0 && f <= 5) break;
		else printf("Некорректный ввод. Введите номер файла заново: ");
	}
	return f;
}
//экспорт из картотеки в файл.
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
//импорт из файла в картотеку.
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
			printf("\nК сожаления, картотека полностью заполнена, попробуйте удалить пару книг.\n\n");
			fclose(f);
			return 0;
		}
	}
	myCart.count += kol;
	fclose(f);
	return 1;
}
