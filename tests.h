#pragma once
#ifndef TESTS_H
#define TESTS_H

#include <iostream>

#include <string>
#include "avltree.h" 
#include "da.h"
#include "iss.h"
#include "kvp.h"
#include "alphind.h"
//#include "interface.h"

const std::string ILOVEYOUBABY = "You're just too good to be true can't take my eyes off you  you'd be like heaven to touch I wanna hold you so much at long last love has arrived and I thank God I'm alive   you're just too good to be true can't take my eyes off of you  Pardon the way that I stare there's nothing else to compare  the sight of you makes me weak there are no words left to speak but if you feel like I feel please let me know that it's real you're just too good to be true can't take my eyes off of you I love you baby, and if it's quite alright  I need you baby, to warm the lonely nights I love you baby, trust in me when I say oh pretty baby, don't bring me down, I pray oh pretty baby, now that I've found you, stay and let me love you, baby, let me love you... You're just too good to be true can't take my eyes off of you you'd be like heaven to touch I wanna hold you so much at long last love has arrived  and I thank god I'm alive you're just too good to be true  can't take my eyes off of you I love you baby, and if it's quite alright I need you baby  to warm the lonely nights  I love you baby,  trust in me when I say  oh pretty baby,  don't bring me down, I pray oh pretty baby, now that I've found you, stay and let me love you, baby, let me love you.";
const std::string TEXT = "You're just too good to be true can't take my eyes off you  you'd be like heaven to touch I wanna hold you so much at long last love has arrived and I thank God I'm alive   you're just too good to be true can't take my eyes off of you Pardon the way that I stare there's nothing else to compare  the sight of you makes me weak there are no words left to speak but if you feel like I feel please let me know that it's real you're just too good to be true can't take my eyes off of you  ";
//const std::string MASTERPIECE = "В первый день весны На краешке земли Нечаянно мы встретились с тобой. Падал белый снег, И розы не цвели, Но к нам пришла весенняя любовь - Она была отчаянно красива. В первый день зимы На краешке земли Нечаянно расстались мы с тобой. Падал первый снег, И розы отцвели – От нас ушла весенняя любовь, Но ты была отчаянно красива. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка   Это сердце мое. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка Это сердце мое. Кончилась любовь, Когда пришла зима, Недолог был сезонный наш роман Но было все отчаянно красиво. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка Это сердце мое. Красиво ты вошла в мою грешную жизнь, Красиво ты ушла из нее, Но, играя, разбила мне душу, А ведь это совсем не игрушка Это сердце мое.  Это сердце мое…";

void t_info_tree(AVLTree<int>* avltree) {
	std::cout << "Root is: " << avltree->getRoot()->getData() << std::endl;
	std::cout << "Size is: " << avltree->getLength() << std::endl;
	avltree->print();
	std::cout << "Min is: " << avltree->findMin()->getData() << std::endl;
	std::cout << "Max is: " << avltree->findMax()->getData() << std::endl;
	std::cout << "______" << std::endl;
}
void t_find_less_elem_tree(AVLTree<int>* avltree,int x) {
	std::cout << "	Find elem < "<< x << std::endl;
	try {
		std::cout << "First element: "
			<< avltree->find([](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
				}, x, -1)
			<< std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree->print();
	std::cout << "______" << std::endl;
}
void t_find_more_elem_tree(AVLTree<int>* avltree, int x) {
	std::cout << "	Find elem > " << x << std::endl;
	try {
		std::cout << "First element: "
			<< avltree->find([](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
				}, x, 1)
			<< std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree->print();
	std::cout << "______" << std::endl;
}
void t_find_equal_elem_tree(AVLTree<int>* avltree, int x) {
	std::cout << "	Find elem = " << x << std::endl;
	try {
		std::cout << "First element: "
			<< avltree->find([](int a, int b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			else
				return 0;
				}, x, 0)
			<< std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree->print();
	std::cout << "______" << std::endl;
}
void t_add_tree(AVLTree<int>* avltree, int x) {
	std::cout << "	Add " << x << std::endl;
	avltree->add(x);
	t_info_tree(avltree);
}
void t_remove_tree(AVLTree<int>* avltree, int x) {
	std::cout << "	Add " << x << std::endl;
	avltree->remove(x);
	t_info_tree(avltree);
}
void t_find_tree(AVLTree<int>* avltree, int x) {
	std::cout << "	Find " << x << std::endl;
	if (avltree->find(x)) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	std::cout << "______" << std::endl;
}
void t_avltree_int() {
	std::cout << "Test AVLTree class " << std::endl;
	int arr[20] = { 1,10,19,3,5,2,78,0,2,34,54,6,12,13,14,15,16,17,18,20 };

	std::cout << "	Negtive size" << std::endl;
	try {
		AVLTree<int>* avltree1 = new AVLTree<int>(arr, -1);
	} 
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "______" << std::endl; 

	std::cout << "	Zero size" << std::endl;
	try {
		AVLTree<int>* avltree1 = new AVLTree<int>(arr, 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "______" << std::endl;

	std::cout << "	Normal size" << std::endl;
	AVLTree<int>* avltree = new AVLTree<int>(arr, 20);
	t_info_tree(avltree);

	t_add_tree(avltree,-5);
	t_remove_tree(avltree, -5);
	t_remove_tree(avltree, 2);
	t_remove_tree(avltree, 4);

	for (int i = 100; i < 107; i++)
		t_add_tree(avltree, i);
	
	t_find_tree(avltree, 106);
	t_find_tree(avltree, 4);

	t_remove_tree(avltree, 106);

	t_find_less_elem_tree(avltree, 15);
	t_find_less_elem_tree(avltree, 6);
	t_find_less_elem_tree(avltree, -1);
	t_find_more_elem_tree(avltree, 15);
	t_find_more_elem_tree(avltree, 34);
	t_find_more_elem_tree(avltree, 200);
	t_find_equal_elem_tree(avltree, 27);
	t_find_equal_elem_tree(avltree, 1);
	t_find_equal_elem_tree(avltree, 105);

}

void t_avltree_int_da_int() {
	std::cout << "Test AVLTree class " << std::endl;
	int arr[20] = { 1,10,19,3,5,2,78,0,2,34,54,6,12,13,14,15,16,17,18,20 }; 
	AVLTree<int>* avltree = new AVLTree<int>(arr, 20);
	std::cout << "AVLTree: " << std::endl;
	//avltree->print();
	std::cout << "______" << std::endl;


	DynamicArray<int>* da = avltree->treeToDA();
	std::cout << "DA: " << std::endl;
	da->print();
	
	int arr_true[20] = { 0,1,2,2,3,5,6,10,12,13,14,15,16,17,18,19,20,34,54,78 };
	if (da->isEqual(arr_true, 20)) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	std::cout << "______" << std::endl;

	std::cout << "AVL from DA: " << std::endl;
	AVLTree<int>* avltree2 = nullptr;

	try { avltree2 = new AVLTree<int>(*(da), 5, 12); }	
	catch (std::exception& e) {	std::cout << e.what() << '\n';	}
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da), 1, -18); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da), -1, 18); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da), -18, -1); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da), 5, 20); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da), 20, 19); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da), 19, 19); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;

	try { avltree2 = new AVLTree<int>(*(da)); }
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	//avltree2->print();
	std::cout << "______" << std::endl;


}

void findNone(DynamicArray<int>* da, int elem) {
	std::cout << "	"<< elem <<": ";
	if (da->indexOf(elem) == -1) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
}
void t_da_int() {
	int arr[20] = { 0,1,2,2,3,5,6,10,12,13,14,15,16,17,18,19,20,34,54,78 };
	DynamicArray<int>* da = new DynamicArray<int>(arr,20);

	std::cout << "	0 = arr[?] (0)" << std::endl;
	if (da->indexOf(0) == 0) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	std::cout << "______" << std::endl;

	std::cout << "	1 = arr[?] (1)" << std::endl;
	if (da->indexOf(1) == 1) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	std::cout << "______" << std::endl;

	std::cout << "	78 = arr[?] (19)" << std::endl;
	if (da->indexOf(78) == 19) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	std::cout << "______" << std::endl;

	findNone(da,4);
	findNone(da, 7);
	findNone(da, 8);
	findNone(da, 9);
	findNone(da, 11);
	findNone(da, 21);
	findNone(da, 100);
	findNone(da, 56);
	std::cout << "______" << std::endl;

} 

void test_more_less(int x, int y) {
	KeyValuePair<int, int> tmp1;
	tmp1.key = x;
	tmp1.value = 2;
	KeyValuePair<int, int> tmp2;
	tmp2.key = y;
	tmp2.value = 2;
	bool tmp = tmp1 < tmp2;
	if (tmp)
		std::cout << "("<< tmp1.key << ", "<< tmp1.value << ") < " << "(" << tmp2.key << ", " << tmp2.value << ") || ";
	else std::cout << "(" << tmp1.key << ", " << tmp1.value << ") >= " << "(" << tmp2.key << ", " << tmp2.value << ") || ";
	tmp = tmp1 > tmp2;
	if (tmp)
		std::cout << "(" << tmp1.key << ", " << tmp1.value << ")  > " << "(" << tmp2.key << ", " << tmp2.value << ")" << std::endl;
	else std::cout << "(" << tmp1.key << ", " << tmp1.value << ") <= " << "(" << tmp2.key << ", " << tmp2.value << ")" << std::endl;
}
void t_kvp() {
	test_more_less(1, 2);
	test_more_less(0, 3);
	test_more_less(4, 6);
	test_more_less(2, 3);
	test_more_less(3, 2);
	test_more_less(4, 2);
	test_more_less(4, 3);
	test_more_less(9, 2);
	test_more_less(2, 2);
	test_more_less(4, 4);
	test_more_less(3, 3);
	test_more_less(9, 9);

}

DynamicArray<KeyValuePair<std::string*,int>>* decomposition_da(std::string str) {
	str.append(" "); // добавляем пробел в конец строки
	while (true) {
		int pos = str.find("  ");
		if (pos == -1) break;
		str.replace(pos, 2, " ");
	}
	while (true) {
		if (str[0] == ' ')
			str.erase(0, 1);
		else break;
	}
	std::cout << "	Now string is: " << std::endl << '	' << str << std::endl;
	DynamicArray<KeyValuePair<std::string*,int>>* res = new DynamicArray<KeyValuePair<std::string*,int>>;
	while (true) {
		int pos = str.find(" ");
		if (pos == -1) break;
		std::string* tmp_str = new std::string(str.substr(0, pos));
		KeyValuePair<std::string*,int> tmp = { tmp_str, 1 };
		
		std::cout << "	word: " << *(tmp.value) << std::endl;
		res->append(tmp);
		str.erase(0, pos + 1);
	}
	return res;
}
void t_kvp_da() {
	std::string str = "  I love you, baby And if it's  quite all right I need you,   baby To warm these lonely nights  I love you, baby Trust in me when I say  ";
	std::cout << "String: " << std::endl << str << std::endl;
	DynamicArray<KeyValuePair<std::string*,int>>*res = decomposition_da(str);
	/*DynamicArray<KeyValuePair<int, int>>* res = new DynamicArray<KeyValuePair<int, int>>;
	for (int i = 0; i < 20; i++) {
		KeyValuePair<int, int> tmp = { i,i };
		res->append(tmp);
	}	*/
	std::cout << "Sequence: " << std::endl;
	for (int i = 0; i < res->getLength(); i++) {
		std::cout << *(res->get(i).value) << ' ';
	}
	std::cout << std::endl;
} 

ISortedSequence<KeyValuePair<std::string*,int>>* decomposition_iss(std::string str) {
	str.append(" "); // добавляем пробел в конец строки
	while (true) {
		int pos = str.find("  ");
		if (pos == -1) break;
		str.replace(pos, 2, " ");
	}
	while (true) {
		if (str[0] == ' ')
			str.erase(0, 1);
		else break;
	}
	std::cout << "	Now string is: " << std::endl << '	' << str << std::endl;
	ISortedSequence<KeyValuePair<std::string*,int>>* res = new ISortedSequence<KeyValuePair<std::string*,int>>;
	while (true) {
		int pos = str.find(" ");
		if (pos == -1) break;
		std::string* tmp_str = new std::string(str.substr(0, pos));
		KeyValuePair<std::string*,int> tmp = { tmp_str,1 };

		std::cout << "	word: " << *(tmp.value) << std::endl;
		res->add(tmp);
		str.erase(0, pos + 1);
	}
	return res;
} 
int page_capacity(int capacity,int number){
	if (number == 1) return capacity / 2;
	if (number % 10 == 0) return capacity * 3 / 4;
	return capacity;
}
ISortedSequence<KeyValuePair<std::string*,int>>* decomposition_iss(std::string str,int capacity) {
	str.append(" "); // добавляем пробел в конец строки
	while (true) {
		int pos = str.find("  ");
		if (pos == -1) break;
		str.replace(pos, 2, " ");
	}
	while (true) {
		if (str[0] == ' ')
			str.erase(0, 1);
		else break;
	}
	std::cout << "Now string is: " << std::endl << str << std::endl;
	ISortedSequence<KeyValuePair<std::string*,int>>* res = new ISortedSequence<KeyValuePair<std::string*,int>>;
	int counter = 0;
	int page = 1;
	while (true) {
		int pos = str.find(" ");
		if (pos == -1) break;
		std::string* tmp_str = new std::string(str.substr(0, pos)); 		
		counter++; // номер рассматриваемого слова		
		while (true)
		{
			int this_page_capacity = page_capacity(capacity, page); // вместимость данной страницы 
			if (counter <= this_page_capacity) // слово помещается на страницу
			{
				KeyValuePair<std::string*, int> tmp = { tmp_str, page };
				std::cout << "	page: " << tmp.key << ", word " << counter << ": " << *(tmp.value) << std::endl;
				res->add(tmp);
				str.erase(0, pos + 1);
				break;
			}
			else // слово уже НЕ ПОМЕЩАЕТСЯ на страницу 
			{
				std::cout << "Page: " << page << ",  " << counter-1 << " words." << std::endl;
				counter = 1;
				page++; //обновляем счётчик страниц и слов
				continue;
			}
		}								
	}
	//std::cout << counter << " words in total." << std::endl;
	std::cout << res->getLength() << " elements in total." << std::endl;
	return res;
}
KeyValuePair<std::string*,int> t_find_equal_key_iss_kvp(ISortedSequence<KeyValuePair<std::string*,int>>* seq, KeyValuePair<std::string*,int> x) {
	
	try {
		KeyValuePair<std::string*,int> res = seq->find([](KeyValuePair<std::string*,int> a, KeyValuePair<std::string*,int> b) {
			if (a.key < b.key)
				return -1;
			if (a.key > b.key)
				return 1;
			else
				return 0;
			}, x, 0);
		return res;		
	}
	catch (std::exception& e) {
		//std::cout <<  << '\n'; 
		throw std::logic_error(e.what());
	}
	//seq->print();
	//std::cout << "______" << std::endl;
}
void t_equal_key(ISortedSequence<KeyValuePair<std::string*,int>>* seq, int key) { 
	std::string* tmp_str = new std::string("");
	KeyValuePair<std::string*,int> tmp = { tmp_str,key };
	try
	{
		std::cout << "	Find elem with page = " << key << std::endl;
		KeyValuePair<std::string*,int> res = t_find_equal_key_iss_kvp(seq, tmp);
		std::cout << "First elem: page " << res.key << ", word " << *(res.value) << std::endl; 
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "______" << std::endl;	
} 
KeyValuePair<std::string*,int> t_find_less_key_iss_kvp(ISortedSequence<KeyValuePair<std::string*,int>>* seq, KeyValuePair<std::string*,int> x) {

	try {
		KeyValuePair<std::string*,int> res = seq->find([](KeyValuePair<std::string*,int> a, KeyValuePair<std::string*,int> b) {
			if (a.key < b.key)
				return -1;
			if (a.key > b.key)
				return 1;
			else
				return 0;
			}, x, -1);
		return res;
	}
	catch (std::exception& e) {
		//std::cout <<  << '\n'; 
		throw std::logic_error(e.what());
	}
	//seq->print();
	//std::cout << "______" << std::endl;
}
void t_less_key(ISortedSequence<KeyValuePair<std::string*,int>>* seq, int key) {
	std::string* tmp_str = new std::string("");
	KeyValuePair<std::string*,int> tmp = {tmp_str, key };
	try
	{
		std::cout << "	Find elem with page = " << key << std::endl;
		KeyValuePair<std::string*,int> res = t_find_less_key_iss_kvp(seq, tmp);
		std::cout << "First elem: page " << res.key << ", word " << *(res.value) << std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "______" << std::endl;
}
KeyValuePair<std::string*,int> t_find_more_key_iss_kvp(ISortedSequence<KeyValuePair<std::string*,int>>* seq, KeyValuePair<std::string*,int> x) {

	try {
		KeyValuePair<std::string*,int> res = seq->find([](KeyValuePair<std::string*,int> a, KeyValuePair<std::string*,int> b) {
			if (a.key < b.key)
				return -1;
			if (a.key > b.key)
				return 1;
			else
				return 0;
			}, x, 1);
		return res;
	}
	catch (std::exception& e) {
		//std::cout <<  << '\n'; 
		throw std::logic_error(e.what());
	}
	//seq->print();
	//std::cout << "______" << std::endl;
}
void t_more_key(ISortedSequence<KeyValuePair<std::string*,int>>* seq, int key) {
	std::string* tmp_str = new std::string("");
	KeyValuePair<std::string*,int> tmp = { tmp_str,key };
	try
	{
		std::cout << "	Find elem with page = " << key << std::endl;
		KeyValuePair<std::string*,int> res = t_find_more_key_iss_kvp(seq, tmp);
		std::cout << "First elem: page " << res.key << ", word " << *(res.value) << std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "______" << std::endl;
}
ISortedSequence<KeyValuePair<std::string*,int>>* t_get_page_iss_kvp(ISortedSequence<KeyValuePair<std::string*,int>>* seq, KeyValuePair<std::string*,int> x, int param) {
	try {
		ISortedSequence<KeyValuePair<std::string*,int>>* res = seq->getSubSequence([](KeyValuePair<std::string*,int> a, KeyValuePair<std::string*,int> b) {
			if (a.key < b.key)
				return -1;
			if (a.key > b.key)
				return 1;
			else
				return 0;
			}, x, param);
		return res;
	}
	catch (std::exception& e) {
		//std::cout <<  << '\n'; 
		throw std::logic_error(e.what());
	}
	//seq->print();
	//std::cout << "______" << std::endl;
}
void t_get_page(ISortedSequence<KeyValuePair<std::string*,int>>* seq, int x, int param) {
	std::string* tmp_str = new std::string("");
	KeyValuePair<std::string*,int> tmp = {  tmp_str,x };
	try
	{
		std::cout << "	Find elements with page = ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << x << std::endl;
		ISortedSequence<KeyValuePair<std::string*,int>>* res = t_get_page_iss_kvp(seq, tmp, param);
		for (int i = 0; i < res->getLength(); i++) {
			std::cout << "	Elem "<< i <<": page " << res->get(i).key << ", word " << *(res->get(i).value) << std::endl;
		}
		std::cout << "Page " << x << std::endl;
		for (int i = 0; i < res->getLength(); i++) {
			std::cout << *(res->get(i).value) << ' ';
		}
		std::cout << std::endl;
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "______" << std::endl;
}
void t_kvp_iss() {
	std::string str(ILOVEYOUBABY);
	std::cout << "String: " << std::endl << str << std::endl;
	ISortedSequence<KeyValuePair<std::string*, int>>* res = nullptr;
	//res = decomposition_iss(str);
	/*DynamicArray<KeyValuePair<int, int>>* res = new DynamicArray<KeyValuePair<int, int>>;
	for (int i = 0; i < 20; i++) {
		KeyValuePair<int, int> tmp = { i,i };
		res->append(tmp);
	}	*/
	/*std::cout << "Sequence without pages: " << std::endl;
	for (int i = 0; i < res->getLength(); i++) {
		std::cout << *(res->get(i).value) << ' ';
	}
	std::cout << std::endl << "__________" << std::endl;*/

	res = decomposition_iss(str,12);
	std::cout << "Sequence with pages: " << std::endl;
	for (int i = 0; i < res->getLength(); i++) {
		std::cout << *(res->get(i).value) << ' ';
	}
	std::cout << std::endl;
	t_equal_key(res, 15);
	t_equal_key(res, 30);
	t_less_key(res, -1);
	t_less_key(res, 1);
	t_more_key(res, 20);
	t_more_key(res, 30);

	t_get_page(res, 10,0);
	t_get_page(res, 3, -1);
	t_get_page(res, 8, 1);
}
void print_ai(AlphabetIndex* ai) {
	ISortedSequence<KeyValuePair<std::string*, int>>* seq = ai->getIndex();
	int number = 0;
	int page = 0;
	for (int i = 0; i < seq->getLength(); i++) {
		if (seq->get(i).key == page) {
			number++;
			std::cout << "	word "<< number<<": " << *(seq->get(i).value) << std::endl;
		}
		else {
			page++;
			std::cout << "Page: " << page << std::endl;
			number = 0;
			i--;
		}
	}
}
void t_ai_info(AlphabetIndex* ai) {
	std::cout << "Capacity: " << ai->getCapacity() << std::endl;
	std::cout << "Length: " << ai->getLength() << std::endl;
	std::cout << "Text: " << std::endl << ai->getText() << std::endl;
	print_ai(ai);
	std::cout << "______" << std::endl;
}
void t_ai_find_by_param(AlphabetIndex* ai, int page, int param) {
	try
	{
		std::cout << "	Find elem on page ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << " " << page << std::endl;
		KeyValuePair<std::string*, int> res = ai->find_by_param(page, param);
		std::cout << "First elem: page " << res.key << ", word " << *(res.value) << std::endl;
		
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "______" << std::endl;
}
void t_ai_find_elements_by_param(AlphabetIndex* ai, int page, int param) {
	try
	{
		std::cout << "	Find elements on page ";
		if (param == 0) std::cout << "=";
		else if (param == 1) std::cout << ">";
		else std::cout << "<";
		std::cout << " " << page << std::endl;
		ISortedSequence<KeyValuePair<std::string*, int>>* res = ai->find_elements_by_param(page, param);
		for (int i = 0; i < res->getLength(); i++) {
			std::cout << "(" << res->get(i).key << ")" << *(res->get(i).value) << " ";
		}
		std::cout << std::endl;		
	}
	catch (std::exception& e) { std::cout << e.what() << '\n'; }
	std::cout << "______" << std::endl;
}
//void t_ai_find_by_param(AlphabetIndex* ai, std::string word, int param) {
//	try
//	{
//		std::cout << "	Find elem by word ";
//		if (param == 0) std::cout << "=";
//		else if (param == 1) std::cout << ">";
//		else std::cout << "<";
//		std::cout << " " << word << std::endl;
//		KeyValuePair<std::string*, int> res = ai->find_by_param(word, param);
//		std::cout << "First elem: page " << res.key << ", word " << *(res.value) << std::endl;
//	}
//	catch (std::exception& e) { std::cout << e.what() << '\n'; }
//	std::cout << "______" << std::endl;
//}
void t_ai() {
	AlphabetIndex* ai = new AlphabetIndex(); 
	ai->setCapacity(12);
	ai->setText(TEXT);
	t_ai_info(ai); 
	ai->setCapacity(24);
	t_ai_info(ai);
	// wrong parameter 
	t_ai_find_by_param(ai, 1, -2);
	t_ai_find_by_param(ai, 1, 3);
	// wrong page 
	t_ai_find_by_param(ai, 8, -1);
	t_ai_find_by_param(ai, 8, 0);
	t_ai_find_by_param(ai, 8, 1);
	t_ai_find_by_param(ai, -1, -1);
	t_ai_find_by_param(ai, -1, 0);
	t_ai_find_by_param(ai, -1, 1); 
	// correct page and param 
	t_ai_find_by_param(ai, 1, -1);
	t_ai_find_by_param(ai, 2, -1);
	//t_ai_find_by_param(ai, 8, -1);
	t_ai_find_by_param(ai, 1, 0);
	t_ai_find_by_param(ai, 2, 0);
	t_ai_find_by_param(ai, 5, 0);
	t_ai_find_by_param(ai, 5, 1);
	t_ai_find_by_param(ai, 2, 1);
	// по слову 
	/*t_ai_find_by_param(ai, "you", 0);
	t_ai_find_by_param(ai, "love", 0);*/
	t_ai_find_by_param(ai, 1, -2);
	t_ai_find_by_param(ai, 1, 3);
	// wrong page 
	t_ai_find_elements_by_param(ai, 8, -1);
	t_ai_find_elements_by_param(ai, 8, 0);
	t_ai_find_elements_by_param(ai, 8, 1);
	t_ai_find_elements_by_param(ai, -1, -1);
	t_ai_find_elements_by_param(ai, -1, 0);
	t_ai_find_elements_by_param(ai, -1, 1);
	// correct page and param 
	t_ai_find_elements_by_param(ai, 1, -1);
	t_ai_find_elements_by_param(ai, 2, -1);
	//t_ai_find_by_param(ai, 8, -1);
	t_ai_find_elements_by_param(ai, 1, 0);
	t_ai_find_elements_by_param(ai, 2, 0);
	t_ai_find_elements_by_param(ai, 5, 0);
	t_ai_find_elements_by_param(ai, 5, 1);
	t_ai_find_elements_by_param(ai, 2, 1);
}





#endif //TESTS_H

