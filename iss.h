#pragma once
#ifndef ISS_H
#define ISS_H

#include <string>
#include "avltree.h"


const std::string ISS_INDEX_OUT_OF_RANGE_MESSAGE = "QuackISS! Index out of range.";
const std::string ISS_ABNSENSE_MESSAGE = "QuackISS! This element is absent.";
const std::string ISS_INCORRECT_PARAM_MESSAGE = "QuackISS! The parameter is incorrect.";

template <typename T>
class ISortedSequence {
private: 
	AVLTree<T>* ptr;
public:
	ISortedSequence<T>() { ptr = new AVLTree<T>(); }
	ISortedSequence<T>(AVLTree<T>* tree) {
		this->ptr = tree;
	};
	AVLTree<T>* getTree() {
		return this->ptr;
	}
	int getLength() {
		return this->ptr->getLength();
	}
	bool isEmpty() {
		if (this->ptr == nullptr) 
			return true; 
		else
			return false;
	}
	T getFirst() {
		return this->ptr->findMin()->getData();
	}
	T getLast() {
		return this->ptr->findMax()->getData();
	}
	void add(T data) {
		this->ptr->add(data);
		return;
	}
	void remove(T data) {
		this->ptr->remove(data);
		return;
	}
	T get(int index) {
		if (index < 0 || index >= this->ptr->getLength()) throw std::out_of_range(ISS_INDEX_OUT_OF_RANGE_MESSAGE);
		return this->ptr->treeToDA()->get(index);
	}
	int indexOf(T data) {
		if (!this->ptr->find(data)) return -1;
		return this->ptr->treeToDA()->indexOf(data);
	}
	ISortedSequence<T>* getSubSequence(int first, int last) {
		if (first > last)
			throw std::out_of_range(AVL_INDEX_OUT_OF_RANGE_MESSAGE);
		else if ((last < 0) || (first < 0))
			throw std::out_of_range(AVL_INDEX_OUT_OF_RANGE_MESSAGE);
		else if (last >= this->ptr->getLength())
			throw std::out_of_range(AVL_INDEX_OUT_OF_RANGE_MESSAGE);

		DynamicArray<T>* dares = this->ptr->treeToDA();
		AVLTree<T>* avlres = new AVLTree<T>(*(dares), first, last);
		return new ISortedSequence<T>(avlres);
	}
	bool find(T data) {
		return this->ptr->find();
	}
	T find(int (*func)(T, T), T a, int param) {
		if (param < -1 || param > 1) throw std::logic_error(ISS_INCORRECT_PARAM_MESSAGE);
		try
		{
			return this->ptr->find(func, a, param);
		}
		catch (const std::exception&)
		{
			throw std::logic_error(ISS_ABNSENSE_MESSAGE);
		}
		
	}
	ISortedSequence<T>* getSubSequence(int (*func)(T, T), T a, int param) {
		ISortedSequence<T>* tmp = this->getSubSequence(0, this->getLength() - 1);
		ISortedSequence<T>* res = new ISortedSequence();
		try		{
			while (true)
			{
				T item = tmp->find(func, a, param);
				tmp->remove(item);
				res->add(item);
			}
		}
		catch (const std::exception&)
		{
			//continue;
		}
		return res;
	}
	/*void print() {
		this->ptr->print();
		return;
	}*/


};





#endif // IIS_H
