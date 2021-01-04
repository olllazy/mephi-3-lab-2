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

const std::string MASTERPIECE = "� ������ ���� �����  �� ������� ����� �������� �� ����������� � �����. ����� ����� ����, � ���� �� �����, �� � ��� ������ �������� ������ - ��� ���� �������� �������. � ������ ���� ���� �� ������� ����� �������� ���������� �� � �����. ����� ������ ����, � ���� ������� � �� ��� ���� �������� ������, �� �� ���� �������� �������. ������� �� ����� � ��� ������� �����, ������� �� ���� �� ���, ��, �����, ������� ��� ����, � ���� ��� ������ �� �������   ��� ������ ���. ������� �� ����� � ��� ������� �����, ������� �� ���� �� ���, ��, �����, ������� ��� ����, � ���� ��� ������ �� ������� ��� ������ ���. ��������� ������, ����� ������ ����, ������� ��� �������� ��� ����� �� ���� ��� �������� �������. ������� �� ����� � ��� ������� �����, ������� �� ���� �� ���, ��, �����, ������� ��� ����, � ���� ��� ������ �� ������� ��� ������ ���. ������� �� ����� � ��� ������� �����, ������� �� ���� �� ���, ��, �����, ������� ��� ����, � ���� ��� ������ �� ������� ��� ������ ���.  ��� ������ ���";

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
			std::cout << "���������� ������� ����� �� " << std::to_string(from) << " �� " << std::to_string(to) << ": ";
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
			std::cout << std::endl<< "��������: " << page << std::endl;
			number = 0;
			i--;
		}
	}
	std::cout << std::endl;
}
void info(AlphabetIndex* ai) {
	std::cout << "����������� ��������: " << ai->getCapacity() << " (� ������)" << std::endl;
	std::cout << "���������� ����: " << ai->getLength() << std::endl;
	std::cout << "���������� �������: " << ai->getNumberOfPages() << std::endl;
	std::cout << "�����: " << std::endl << ai->getText() << std::endl;
	print(ai);
	std::cout << "______" << std::endl;
}

void printmenu1(AlphabetIndex* ai) {
	while (true)
	{
		cout << "		(1)���������� �� ���������." << endl;
		cout << "	|1 - �������� ��� ���������� �� ���������;" << endl;
		cout << "	|2 -  --//--  ����������� ��������;" << endl;
		//cout << "2 - ������ ���������� �������� (� ������);" << endl;
		cout << "	|3 -  --//--  ���������� ����;" << endl;
		cout << "	|4 -  --//--  ���������� �������" << endl;
		cout << "	|5 -  --//--  �����;" << endl;
		//cout << "7 - ������ ������� ����� �����������;" << endl;
		cout <<"	|"<< endl;
		cout << "	|6 - ����� � ������� ����." << endl;
		cout << "	|������� ����� ���������� ���� ��������: ";
		int choice = readInt(1, 6);
		switch (choice)
		{
		case 1:
			info(ai);
			break;
		case 2:
			std::cout << "	����������� ��������: " << ai->getCapacity() << " (� ������)" << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 3:
			std::cout << "	���������� ����: " << ai->getLength() << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 4:
			std::cout << "	���������� �������: " << ai->getNumberOfPages() << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 5:
			std::cout << "	�����: " << std::endl << ai->getText() << std::endl;
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
		cout << "		(2)������ ���������." << endl;
		cout << "	|1 - ������ �����;" << endl;
		cout << "	|2 - --//-- ����������� ��������;" << endl;
		//cout << "2 - ������ ���������� �������� (� ������);" << endl;
		cout << "	|" << endl;
		cout << "	|3 - ����� � ������� ����." << endl;
		cout << "	|������� ����� ���������� ���� ��������: ";
		int choice = readInt(1, 6);
		std::string text;
		int capacity;
		switch (choice)
		{
		case 1:
			std::cout << "	������� ��� ����� ����: " << std::endl;
			std::getline(std::cin, text);
			ai->setText(text);
			std::cout << "	�������: " << std::endl;
			std::cout << "	______" << std::endl << std::endl;
			break;
		case 2:
			std::cout << "	������� ����������� �������� (� ������): ";
			capacity = readInt(1, INT_MAX);
			ai->setCapacity(capacity);
			std::cout << "	�������: " << std::endl;
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
		std::cout << "	����� ����� �� �������� ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << " " << page << std::endl;
		KeyValuePair<std::string*, int> res = ai->find_by_param(page, param);
		std::cout << "	������ ��������� �����: �������� " << res.key << ", ����� '" << *(res.value) << "'"<< std::endl;

	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "	______" << std::endl << std::endl;
}
void find_elements_by_param(AlphabetIndex* ai, int page, int param) {
	try
	{
		std::cout << "	����� ����� �� ��������(��) ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << " " << page << std::endl;
		ISortedSequence<KeyValuePair<std::string*, int>>* res = ai->find_elements_by_param(page, param);
		std::cout << "	��������� �������� (� ������� ����������� ����� ��������): " << std::endl;
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
		cout << "		(3)�����, ��������������� �������." << endl;
		cout << "	|����������, ������� ������� � ��������� �������." << endl;
		cout << "	������� ����� ��������: ";
		int page = readInt(1, ai->getNumberOfPages());
		cout << "	|���������: " << endl;
		cout << "	|    1 - �� ��������� ��������;" << endl;
		cout << "	|    2 - �� ��������;" << endl;
		cout << "	|    3 - ����� ��������� ��������." << endl;
		cout << "	������� ��������: ";
		int param = readInt(1, 3);
		param = param - 2;
		///int page = readInt(1, ai->getNumberOfPages());
		find_by_param(ai, page, param);
		//cout << "2 - ������ ���������� �������� (� ������);" << endl;
		/*cout << "	|" << endl;
		cout << "	|3 - ����� � ������� ����." << endl;*/
		cout << "	|������� ����� � ������� ����? " << endl;
		cout << "	|    1 - ��;" << endl;
		cout << "	|    2 - ���." << endl;
		cout << "	��� �����: ";
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
		cout << "		(4)������ �������(�)." << endl;
		cout << "	|����������, ������� ������� � ��������� �������." << endl;
		cout << "	������� ����� ��������: ";
		int page = readInt(1, ai->getNumberOfPages());
		cout << "	|���������: " << endl;
		cout << "	|    1 - �� ��������� ��������;" << endl;
		cout << "	|    2 - ��� ��������;" << endl;
		cout << "	|    3 - ����� ��������� ��������." << endl;
		cout << "	������� ��������: ";
		int param = readInt(1, 3);
		param = param - 2;
		///int page = readInt(1, ai->getNumberOfPages());
		find_elements_by_param(ai, page, param);
		//cout << "2 - ������ ���������� �������� (� ������);" << endl;
		/*cout << "	|" << endl;
		cout << "	|3 - ����� � ������� ����." << endl;*/
		cout << "	|������� ����� � ������� ����? " << endl;
		cout << "	|    1 - ��;" << endl;
		cout << "	|    2 - ���." << endl;
		cout << "	��� �����: ";
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
		//std::cout << "2 - ������ ���������� �������� (� ������);" << std::endl;
		std::cout << "3 - �omparison of KVP<int,int>;" << std::endl;
		std::cout << "4 - DA of KVP<string,int>;" << std::endl;
		//std::cout << "6 - ������ ������� �� �����������;" << std::endl;
		//std::cout << "7 - ������ ������� ����� �����������;" << std::endl;		
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
		cout << "	������� ����." << endl;
		cout << "1 - �������� ���������� �� ���������;" << endl;
		cout << "2 - ������ ���������;" << endl;
		//cout << "2 - ������ ���������� �������� (� ������);" << endl;
		cout << "3 - �������� ������ ��������� �����, ��������������� �������;" << endl;
		cout << "4 - ������ �������� (�����������, ��� ��, ��� �����);" << endl;
		//cout << "6 - ������ ������� �� �����������;" << endl;
		//cout << "7 - ������ ������� ����� �����������;" << endl;
		cout << endl;
		cout << "5 - �����." << endl;
		cout << "6 - TESTS." << endl;
		cout << "������� ����� ���������� ���� ��������: ";
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

