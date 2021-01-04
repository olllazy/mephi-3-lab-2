#pragma once
#ifndef ALPHABETINDEX_H
#define ALPHABETINDEX_H

#include <string>
#include <stdexcept>

#include "iss.h"
#include "kvp.h"

const std::string AI_INDEX_OUT_OF_RANGE_MESSAGE = "QuackAI! Index out of range.";
const std::string AI_NEGATIVE_SIZE_MESSAGE = "QuackAI! Size < 0.";
const std::string AI_ZERO_SIZE_MESSAGE = "QuackAI! Size = 0.";
const std::string AI_ABNSENSE_MESSAGE = "QuackAI! This element is absent.";
const std::string AI_INCORRECT_PARAM_MESSAGE = "QuackAI! The parameter is incorrect.";


class AlphabetIndex {
private:
	std::string text = "";
	int wordcapacity = 1;
	ISortedSequence<KeyValuePair<std::string*, int>>* index;
	int pages = 0;
public: 
	
	AlphabetIndex() { text = ""; wordcapacity = 1; index = new ISortedSequence<KeyValuePair<std::string*, int>>(); pages = 0; }
	AlphabetIndex(int count) { text = ""; wordcapacity = count; index = new ISortedSequence<KeyValuePair<std::string*, int>>(); pages = 0; }

	int page_capacity(int capacity, int number) {
		if (number == 1) return capacity / 2;
		if (number % 10 == 0) return capacity * 3 / 4;
		return capacity;
	}
	ISortedSequence<KeyValuePair<std::string*, int>>* decomposition(std::string str, int capacity) {
		str.append(" "); // добавл€ем пробел в конец строки		
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
		//std::cout << "Now string is: " << std::endl << str << std::endl;
		ISortedSequence<KeyValuePair<std::string*, int>>* res = new ISortedSequence<KeyValuePair<std::string*, int>>;
		int counter = 0;
		int page = 1;
		while (true) {
			int pos = str.find(" ");
			if (pos == -1) { 
				this->pages = page;
				break; 
			}
			std::string* tmp_str = new std::string(str.substr(0, pos));
			counter++; // номер рассматриваемого слова		
			while (true)
			{
				int this_page_capacity = page_capacity(capacity, page); // вместимость данной страницы 
				if (counter <= this_page_capacity) // слово помещаетс€ на страницу
				{
					KeyValuePair<std::string*, int> tmp = { tmp_str, page };
					//std::cout << "	page: " << tmp.key << ", word " << counter << ": " << *(tmp.value) << std::endl;
					res->add(tmp);
					str.erase(0, pos + 1);
					break;
				}
				else // слово уже Ќ≈ ѕќћ≈ўј≈“—я на страницу 
				{
					//std::cout << "Page: " << page << ",  " << counter - 1 << " words." << std::endl;
					counter = 1;
					page++; //обновл€ем счЄтчик страниц и слов
					continue;
				}
			}
		}
		//std::cout << counter << " words in total." << std::endl;
		//std::cout << res->getLength() << " elements in total." << std::endl;
		return res;
	}
	AlphabetIndex(std::string text, int count) { 
		std::string tmp(text);
		this->text = text;
		this->wordcapacity = count; 
		this->index = decomposition(tmp, wordcapacity);
	}
	void setText(std::string text) {
		this->text = text;
		std::string tmp(text);
		this->index = decomposition(tmp, wordcapacity);
	}
	void setCapacity(int capacity) {
		if (capacity < 0) throw std::length_error(AI_NEGATIVE_SIZE_MESSAGE);
		if (capacity == 0) throw std::length_error(AI_ZERO_SIZE_MESSAGE);

		this->wordcapacity = capacity;
		if (this->text != "") {
			std::string tmp(this->text);
			this->index = decomposition(tmp, wordcapacity);
		}			
	}
	int getLength() {
		return this->index->getLength();
	}
	int getNumberOfPages() {
		return this->pages;
	}
	int getCapacity() {
		return this->wordcapacity;
	}
	std::string getText() {
		return this->text;
	}
	ISortedSequence<KeyValuePair<std::string*, int>>* getIndex() {
		return this->index;
	}

	// page - страница, param - параметр, (1:больше/-1:меньше/0:равна€) заданной странице
	KeyValuePair<std::string*, int> find_by_param(int page,int param) 
	{
		if (param < -1 || param > 1) throw std::logic_error(AI_INCORRECT_PARAM_MESSAGE);
		std::string* str = new std::string("");
		KeyValuePair<std::string*, int> tmp = { str,page };
		try
		{
			return this->index->find([](KeyValuePair<std::string*, int> a, KeyValuePair<std::string*, int> b) {
				if (a.key < b.key)
					return -1;
				if (a.key > b.key)
					return 1;
				else
					return 0;
				}, tmp, param);
		}
		catch (const std::exception& e)
		{
			throw std::logic_error(e.what());
		}		
	} 
	
	/*KeyValuePair<std::string*, int> find_by_param(std::string word, int param)
	{
		if (param < -1 || param > 1) throw std::logic_error(AI_INCORRECT_PARAM_MESSAGE);
		DynamicArray<KeyValuePair<std::string*, int>>* oldda = this->index->getTree()->treeToDA();
		DynamicArray<KeyValuePair<int, std::string*>>* newda = new DynamicArray<KeyValuePair<int, std::string*>>();
		for (int i = 0; i < oldda->getLength(); i++) {
			KeyValuePair<int, std::string*> tmpstruct = {
				oldda->get(i).key, oldda->get(i).value
			};
			newda->append(tmpstruct);
		}
		AVLTree<KeyValuePair<int, std::string*>>* tmpavl = new AVLTree<KeyValuePair<int, std::string*>>(*newda);
		ISortedSequence<KeyValuePair<int, std::string* >> *seq = new ISortedSequence<KeyValuePair<int, std::string* > > (tmpavl);
		
		try
		{
			std::string* str = new std::string(word);
			KeyValuePair<int, std::string*> tmp = {-1,str };
			KeyValuePair<int, std::string*> tmpstruct = seq->find([](KeyValuePair<int, std::string*> a, KeyValuePair<int, std::string*> b) {
				if (*(a.key) < *(b.key))
					return -1;
				if (*(a.key) > *(b.key))
					return 1;
				else
					return 0;
				}, tmp, param);

			KeyValuePair<std::string*, int> ans = { tmpstruct.key,tmpstruct.value };
			return ans;
		}
		catch (const std::exception& e)
		{
			throw std::logic_error(e.what());
		}
	}*/
	ISortedSequence<KeyValuePair<std::string*, int>>* find_elements_by_param(int page, int param) {
		//ISortedSequence<KeyValuePair<std::string*, int>>* tmpseq = this->index->getSubSequence(0, this->getLength() - 1);
		//ISortedSequence<KeyValuePair<std::string*, int>>* res = new ISortedSequence< KeyValuePair<std::string*, int>>();

		if (param < -1 || param > 1) throw std::logic_error(AI_INCORRECT_PARAM_MESSAGE);
		if (param < 0) {
			if (page <= 1) throw std::logic_error(AI_ABNSENSE_MESSAGE);
			int mini = 0;
			int count = min(this->pages, page);
			if (count == this->pages) count++;
			int maxi = 0;
			for (int i = 1; i < count; i++)
				maxi = maxi + page_capacity(this->wordcapacity, i);
			maxi--;
			return this->index->getSubSequence(mini, maxi);
		}
		else if (param > 0) {
			if (page >= this->pages) throw std::logic_error(AI_ABNSENSE_MESSAGE);
			int maxi = this->getLength()-1;
			int mini = 0;
			for (int i = 1; i < page+1; i++)
				mini = mini + page_capacity(this->wordcapacity, i);
			//mini;
			return this->index->getSubSequence(mini, maxi);
		}
		else {
			if (page > this->pages || page < 1) throw std::logic_error(AI_ABNSENSE_MESSAGE);
			int maxi = 0;
			int mini = 0;
			for (int i = 1; i < page; i++)
				mini = mini + page_capacity(this->wordcapacity, i);
			if (page  ==  this->pages) 
				maxi = this->getLength();
			else
				maxi = mini + page_capacity(this->wordcapacity, page);
			maxi--;
			return this->index->getSubSequence(mini, maxi);
		}
	}
};


#endif // ALPHABETINDEX_H
