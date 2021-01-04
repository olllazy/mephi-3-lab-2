#pragma once

#ifndef INTERFACE_H
#define INTERFACE 
#include <string>
#include <limits>
#include <iostream> 
#include <exception>
//#include <ctime> 
//#include <chrono>
#include "alphind.h"
#include "kvp.h"
#include "tests.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

const std::string MASTERPIECE = "В первый день весны  На краешке земли Нечаянно мы встретились с тобой. Падал белый снег, И розы не цвели, Но к нам пришла весенняя любовь - Она была отчаянно красива. В первый день зимы На краешке земли Нечаянно расстались мы с тобой. Падал первый снег, И розы отцвели – От нас ушла весенняя любовь, Но ты была отчаянно красива. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка   Это сердце мое. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка Это сердце мое. Кончилась любовь, Когда пришла зима, Недолог был сезонный наш роман Но было все отчаянно красиво. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка Это сердце мое. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка Это сердце мое.  Это сердце мое…";

int readInt(int from, int to) {
	while (true) {
		try {
			std::string line;
			std::getline(std::cin, line);
			if (line.empty()) throw std::exception();

			int read = std::stoi(line);
			if (read < from || read > to) throw std::exception();

			std::cout << endl;
			return read;
		}
		catch (...) {
			std::cout << "Пожалуйста введите цифру от " << std::to_string(from) << " до " << std::to_string(to) << ": ";
		}
	}
}

void print(AlphabetIndex* ai) {
	ISortedSequence<KeyValuePair<std::string*, int>>* seq = ai->getIndex();
	int number = 0;
	int page = 0;
	for (int i = 0; i < seq->getLength(); i++) {
		if (seq->get(i).key == page) {
			number++;
			std::cout << *(seq->get(i).value)<< " ";
		}
		else {
			page++;
			std::cout << std::endl<< "Страница: " << page << std::endl;
			number = 0;
			i--;
		}
	}
	std::cout << std::endl;
}
void info(AlphabetIndex* ai) {
	std::cout << "Вместимость страницы: " << ai->getCapacity() << " (в словах)" << std::endl;
	std::cout << "Количество слов: " << ai->getLength() << std::endl;
	std::cout << "Количество страниц: " << ai->getNumberOfPages() << std::endl;
	std::cout << "Текст: " << std::endl << ai->getText() << std::endl;
	print(ai);
	std::cout << "______" << std::endl;
}

void printmenu1(AlphabetIndex* ai) {
	while (true)
	{
		cout << "		(1)Информация об указателе." << endl;
		cout << "	|1 - показать всю инофрмацию об указателе;" << endl;
		cout << "	|2 -  --//--  вместимость страницы;" << endl;
		//cout << "2 - задать вместимось страницы (в словах);" << endl;
		cout << "	|3 -  --//--  количество слов;" << endl;
		cout << "	|4 -  --//--  количество страниц" << endl;
		cout << "	|5 -  --//--  текст;" << endl;
		//cout << "7 - печать страниц после определённой;" << endl;
		cout <<"	|"<< endl;
		cout << "	|6 - выйти в Главное меню." << endl;
		cout << "	|Введите номер выбранного вами действия: ";
		int choice = readInt(1, 6);
		switch (choice)
		{
		case 1:
			info(ai);
			break;
		case 2:
			std::cout << "	Вместимость страницы: " << ai->getCapacity() << " (в словах)" << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 3:
			std::cout << "	Количество слов: " << ai->getLength() << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 4:
			std::cout << "	Количество страниц: " << ai->getNumberOfPages() << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 5:
			std::cout << "	Текст: " << std::endl << ai->getText() << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 6:
			std::cout << "	______" << std::endl << std::endl;
			return;
			break;
		}
	}
}
void printmenu2(AlphabetIndex* ai) {
	while (true)
	{
		cout << "		(2)Задать параметры." << endl;
		cout << "	|1 - задать текст;" << endl;
		cout << "	|2 - --//-- вместимость страницы;" << endl;
		//cout << "2 - задать вместимось страницы (в словах);" << endl;
		cout << "	|" << endl;
		cout << "	|3 - выйти в Главное меню." << endl;
		cout << "	|Введите номер выбранного вами действия: ";
		int choice = readInt(1, 6);
		std::string text;
		int capacity;
		switch (choice)
		{
		case 1:
			std::cout << "	Введите ваш текст ниже: " << std::endl;
			std::getline(std::cin, text);
			ai->setText(text);
			std::cout << "	Принято: " << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 2:
			std::cout << "	Введите вместимость страницы (в словах): ";
			capacity = readInt(1, INT_MAX);
			ai->setCapacity(capacity);
			std::cout << "	Принято: " << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 3:
			std::cout << "	______" << std::endl << std::endl;
			return;
			break;
		}
	}
}

void find_by_param(AlphabetIndex* ai, int page, int param) {
	try
	{
		std::cout << "	Найти слово на странице ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << " " << page << std::endl;
		KeyValuePair<std::string*, int> res = ai->find_by_param(page, param);
		std::cout << "	Первое найденное слово: страница " << res.key << ", слово '" << *(res.value) << "'"<< std::endl;

	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "	______" << std::endl << std::endl;
}
void find_elements_by_param(AlphabetIndex* ai, int page, int param) {
	try
	{
		std::cout << "	Найти слова на странице(ах) ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << " " << page << std::endl;
		ISortedSequence<KeyValuePair<std::string*, int>>* res = ai->find_elements_by_param(page, param);
		std::cout << "	Найденные страницы (в скобках указывается номер страницы): " << std::endl;
		for (int i = 0; i < res->getLength(); i++) {
			std::cout << "(" << res->get(i).key << ")" << *(res->get(i).value) << " ";
		}
		std::cout << std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "	______" << std::endl << std::endl;
}
void printmenu3(AlphabetIndex* ai) {
	while (true)
	{
		cout << "		(3)Слово, удовлетворяющее условию." << endl;
		cout << "	|Пожалуйста, введите команду в указанном формате." << endl;
		cout << "	Введите номер страницы: ";
		int page = readInt(1, ai->getNumberOfPages());
		cout << "	|Параметры: " << endl;
		cout << "	|    1 - до указанной страницы;" << endl;
		cout << "	|    2 - на странице;" << endl;
		cout << "	|    3 - после указанной страницы." << endl;
		cout << "	Введите параметр: ";
		int param = readInt(1, 3);
		param = param - 2;
		///int page = readInt(1, ai->getNumberOfPages());
		find_by_param(ai, page, param);
		//cout << "2 - задать вместимось страницы (в словах);" << endl;
		/*cout << "	|" << endl;
		cout << "	|3 - выйти в Главное меню." << endl;*/
		cout << "	|Желаете выйти в главное меню? " << endl;
		cout << "	|    1 - да;" << endl;
		cout << "	|    2 - нет." << endl;
		cout << "	Ваш ответ: ";
		param = readInt(1, 2);
		std::cout << "	______" << std::endl << std::endl;
		if (param == 1) {
			return;
		}
	}
}

void printmenu4(AlphabetIndex* ai) {
	while (true)
	{
		cout << "		(4)Печать страниц(ы)." << endl;
		cout << "	|Пожалуйста, введите команду в указанном формате." << endl;
		cout << "	Введите номер страницы: ";
		int page = readInt(1, ai->getNumberOfPages());
		cout << "	|Параметры: " << endl;
		cout << "	|    1 - до указанной страницы;" << endl;
		cout << "	|    2 - эта страница;" << endl;
		cout << "	|    3 - после указанной страницы." << endl;
		cout << "	Введите параметр: ";
		int param = readInt(1, 3);
		param = param - 2;
		///int page = readInt(1, ai->getNumberOfPages());
		find_elements_by_param(ai, page, param);
		//cout << "2 - задать вместимось страницы (в словах);" << endl;
		/*cout << "	|" << endl;
		cout << "	|3 - выйти в Главное меню." << endl;*/
		cout << "	|Желаете выйти в главное меню? " << endl;
		cout << "	|    1 - да;" << endl;
		cout << "	|    2 - нет." << endl;
		cout << "	Ваш ответ: ";
		param = readInt(1, 2);
		std::cout << "	______" << std::endl << std::endl;
		if (param == 1) {
			return;
		}
	}
}

void all_tests() {
	while (true)
	{
		std::cout << std::endl;
		std::cout << "	Test Menu." << std::endl;
		std::cout << "1 - All tests;" << std::endl;
		std::cout << "2 - AVLTree<int>;" << std::endl;
		//std::cout << "2 - задать вместимось страницы (в словах);" << std::endl;
		std::cout << "3 - Сomparison of KVP<int,int>;" << std::endl;
		std::cout << "4 - DA of KVP<string,int>;" << std::endl;
		//std::cout << "6 - печать страниц до определённой;" << std::endl;
		//std::cout << "7 - печать страниц после определённой;" << std::endl;		
		std::cout << "5 - ISS of KVP<string,int>;" << std::endl;
		std::cout << "6 - AI;" << std::endl;
		std::cout << std::endl;
		std::cout << "7 - EXIT." << std::endl;
		std::cout << "Answer: ";
		int choice = readInt(1, 6);
		switch (choice)
		{
		case 1:
			t_avltree_int();
			t_kvp();
			t_kvp_da();
			t_kvp_iss();
			t_ai();
			std::cout << std::endl;
			break;
		case 2:
			t_avltree_int();
			std::cout << std::endl;
			break;
		case 3:
			t_kvp();
			std::cout << std::endl;
			break;
		case 4:
			t_kvp_da();
			std::cout << std::endl;
			break;
		case 5:
			t_kvp_iss();
			std::cout << std::endl;
			break;
		case 6:
			t_ai();
			std::cout << std::endl;
			break;
		case 7:
			return;
			break;
		}
	}

}


void printmenu0(AlphabetIndex* ai) {
	while (true)
	{
		cout << "	Главное меню." << endl;
		cout << "1 - показать информацию об указателе;" << endl;
		cout << "2 - задать параметры;" << endl;
		//cout << "2 - задать вместимось страницы (в словах);" << endl;
		cout << "3 - показать первое найденное слово, удовлетворяющее условию;" << endl;
		cout << "4 - печать страницы (определённую, все до, все после);" << endl;
		//cout << "6 - печать страниц до определённой;" << endl;
		//cout << "7 - печать страниц после определённой;" << endl;
		cout << endl;
		cout << "5 - выход." << endl;
		cout << "6 - TESTS." << endl;
		cout << "Введите номер выбранного вами действия: ";
		int choice = readInt(1, 6);
		switch (choice)
		{
		case 1:
			printmenu1(ai);
			break;
		case 2:
			printmenu2(ai);
			break;
		case 3:
			printmenu3(ai);
			break;
		case 4:
			printmenu4(ai);
			break;
		case 5:
			return;
			break;
		case 6:
			all_tests();
			break;
		}
	}	
}


void programm() {
	AlphabetIndex* ai = new AlphabetIndex(MASTERPIECE,12);
	printmenu0(ai);
}


#endif // INTERFACE_H

