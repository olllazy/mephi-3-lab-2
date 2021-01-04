#pragma once
#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H 
#include <iostream> 
#include <fstream>
#include <string>
//#include "iss.h"

template <typename V, typename K>
struct KeyValuePair {

	V value = 0;
	K key = 0;
	K getKey() {
		return key;
	}
	bool operator>(KeyValuePair<V, K>& p2) const {
		return this->key > p2.key;
	}
	bool operator<(KeyValuePair<V,K>& p2) const {
		return this->key < p2.key;
	}
	//friend std::ostream& operator<<(std::ostream& out, const KeyValuePair<V,K>& p2);
};

template <typename V, typename K>
std::ostream& operator<<(std::ostream& os, KeyValuePair<V,K>& p2)
{
	os << p2.value;
	return os;
}

//class AlphabetIndex {
//private:
//	std::string text;
//	ISortedSequence<KeyValuePair<int, std::string>>* alind;
//public:
//	AlphabetIndex() { text = ""; alind = nullptr; }
//};


#endif // KEYVALUEPAIR_H
