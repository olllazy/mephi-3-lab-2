#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H 

#include <stdexcept> 
#include <typeinfo>
#include "da.h"
#include "kvp.h" 

const std::string AVL_INDEX_OUT_OF_RANGE_MESSAGE = "QuackAVLT! Index out of range.";
const std::string AVL_NEGATIVE_SIZE_MESSAGE = "QuackAVLT! Size < 0.";
const std::string AVL_ZERO_SIZE_MESSAGE = "QuackAVLT! Size = 0.";
const std::string AVL_ABNSENSE_MESSAGE = "QuackAVLT! This element is absent.";
const std::string AVL_INCORRECT_PARAM_MESSAGE = "QuackAVLT! The parameter is incorrect.";


template <typename T> 
class AVLTree {
private:
	// описываем узел дерева
	template <typename D>
	class Node {
	private:
		D data;

	public:
		Node<D>* pLeft = nullptr;
		Node<D>* pRight = nullptr;
		int height = 1; // для балансировки
		// для прошивки 

		Node<D>() { data = 0; pLeft = nullptr;  pRight = nullptr; height = 1; }
		Node<D>(D k) { data = k; pLeft = nullptr;  pRight = nullptr; height = 1; }

		int getheight() {
			if (this == nullptr)
				return 0;
			else
				return this->height;
		}
		D getData() { return this->data; }
		void setData(D item) { this->data = item; return; }


		int bf() // фактор балансировки 
		{
			return this->pRight->getheight() - this->pLeft->getheight();
		}

		void setheight() // установить правильную высоту
		{
			int hr = this->pRight->getheight();
			int hl = this->pLeft->getheight();
			this->height = (hl > hr ? hl : hr) + 1;

		}
	};

	Node<T>* root = nullptr;
	int length = 0;

	//void printThreadTree(Node<T>* ptr) // вывод элементов по порядку 
	//{
	//	Node<T>* tmp = this->rootThread;
	//	while (tmp != nullptr) {
	//		std::cout << tmp->data << " ";
	//		tmp = tmp->pNext;
	//	}
	//	return;
	//}

	//void printTree(Node<T>* ptr)
	//{
	//	Node<T>* tmp = ptr;
	//	if (tmp == nullptr)
	//		return;
	//	printTree(tmp->pLeft);
	//	std::cout << tmp->data << " ";
	//	printTree(tmp->pRight);
	//}

public:

	// пустой конструктор
	AVLTree()
	{
		this->root = nullptr;
		this->length = 0;
	}

	AVLTree(T* item, int len) : AVLTree()
	{
		if (len == 0) throw std::length_error(AVL_ZERO_SIZE_MESSAGE);
		if (len < 0) throw std::length_error(AVL_NEGATIVE_SIZE_MESSAGE);
		//this->root = new Node<T>;		
		this->root = new Node<T>(*(item));
		this->length = 1;
		//std::cout << "Quack_Control!" << std::endl;
		for (int i = 1; i < len; ++i) {
			//std::cout << "	Root was: " << this->root->getData() << std::endl; 
			//std::cout << "	Item is: " << *(item + i) << std::endl; 
			this->add(*(item + i));
			//std::cout << "	Root now: " << this->root->getData() << std::endl; 
			//std::cout << "___" << std::endl;
		}
	}

	AVLTree(const DynamicArray<T>& array, int first, int last) : AVLTree()
	{
		if (first > last)
			throw std::out_of_range(AVL_INDEX_OUT_OF_RANGE_MESSAGE);
		else if ((last < 0) || (first < 0))
			throw std::out_of_range(AVL_INDEX_OUT_OF_RANGE_MESSAGE);
		else if (last >= array.getLength())
			throw std::out_of_range(AVL_INDEX_OUT_OF_RANGE_MESSAGE);

		//this->root = new Node<T>;		
		this->root = new Node<T>(array.get(first));
		this->length = 1;

		for (int i = first + 1; i < last + 1; ++i) {
			this->add(array.get(i));
		}
	}

	AVLTree(const DynamicArray<T>& array) :
		AVLTree(array, 0, array.getLength() - 1) {}

	int getLength()
	{
		return this->length;
	}
	T getData(Node<T>* ptr) { return ptr->getData(); }
	void* getLeft(Node<T>* ptr) { return (void*)ptr->pLeft; }
	void* getRight(Node<T>* ptr) { return (void*)ptr->pRight; }

	Node<T>* getRoot() { return this->root; }

	Node<T>* rrotate(Node<T>* ptr) // правый поворот вокруг ptr
	{
		Node<T>* lptr = ptr->pLeft; // запоминаем lptr - левый узел ptr
		ptr->pLeft = lptr->pRight; // переносим правую часть lptr на освободившееся место
		lptr->pRight = ptr; // переносим ptr в правую часть lptr
		ptr->setheight(); // пересчитываем высоту
		lptr->setheight(); // пересчитываем высоту
		return lptr; // возвращаем нужный узел
	}
	Node<T>* lrotate(Node<T>* ptr) // левый поворот вокруг ptr
	{
		Node<T>* rptr = ptr->pRight; // запоминаем rptr - правый узел ptr
		ptr->pRight = rptr->pLeft; // далее аналогично симметрично правому повороту
		rptr->pLeft = ptr;
		ptr->setheight();
		rptr->setheight();
		return rptr;
	}

	Node<T>* balance(Node<T>* ptr) // балансировка узла ptr
	// возвращает узел, который должен быть вместо заданного
	{
		ptr->setheight(); // cчитаем высоту 
		if (ptr->bf() == 2) // проверяем фактор балансировки
		{ // если балансировка нужна: 
			if (ptr->pRight->bf() < 0)
				ptr->pRight = rrotate(ptr->pRight);
			return lrotate(ptr);
		}
		if (ptr->bf() == -2)
		{
			if (ptr->pLeft->bf() > 0)
				ptr->pLeft = lrotate(ptr->pLeft);
			return rrotate(ptr);
		}
		return ptr; // балансировка не нужна
	}

	Node<T>* add(T data) { // вставка ключа data
		this->root = add(this->root, data);
		this->length++;
		return this->root;
	}
	Node<T>* add(Node<T>* ptr, T data) // вставка ключа data в дерево с корнем ptr
	{
		if (ptr == nullptr) return new Node<T>(data); //если корень пустой
		if (data < getData(ptr))
			ptr->pLeft = add(ptr->pLeft, data);
		else
			ptr->pRight = add(ptr->pRight, data);
		return balance(ptr); // балансировка данного узла 
	}

	Node<T>* findMin(Node<T>* ptr) // поиск узла с минимальным ключом в дереве ptr
	{
		return ptr->pLeft ? findMin(ptr->pLeft) : ptr;
	}
	Node<T>* findMin() {
		return findMin(this->root); // поиск узла с минимальным ключом
	}

	Node<T>* findMax(Node<T>* ptr) // поиск узла с максимальным ключом в дереве ptr
	{
		return ptr->pRight ? findMax(ptr->pRight) : ptr;
	}
	Node<T>* findMax() // поиск узла с максимальным ключом 
	{
		return findMax(this->root);
	}

	Node<T>* removeMin(Node<T>* ptr) // удаление узла с минимальным ключом из дерева ptr
	{ // вернуть указатель на правый узел
		if (ptr->pLeft == nullptr) // слева ничего нет 
			return ptr->pRight;
		ptr->pLeft = removeMin(ptr->pLeft); // слева что-то есть
		return balance(ptr);
	}
	Node<T>* removeMin() // удаление узла с минимальным ключом из дерева ptr
	{
		return removeMin(this->root);
	}

	Node<T>* remove(Node<T>* ptr, T data) // удаление ключа data из дерева ptr
	{
		if (ptr == nullptr) return nullptr; // если указатель на дерево нулевой
		// находим нужный узел 
		if (data < ptr->getData()) // меньше чем рассматриваемый
			ptr->pLeft = remove(ptr->pLeft, data); // уходим влево
		else if (data > ptr->getData())
			ptr->pRight = remove(ptr->pRight, data); // уходим вправо
		else //  data = ptr->getData()  нашли нужный узел
		{
			Node<T>* lptr = ptr->pLeft; // запомнили левый корень
			Node<T>* rptr = ptr->pRight; // запомнили правый корень
			delete ptr; // удаляем узел 
			this->length--;
			//правое поддерево пустое -> возвращаем указатель на левое поддерево
			if (rptr == nullptr) return lptr;
			// находим в правом поддереве минимальный элемент min
			Node<T>* min = findMin(rptr); // его извлекаем оттуда
			min->pRight = removeMin(rptr);
			min->pLeft = lptr; // подвешиваем слева запомненный нами левый корень
			return balance(min); // балансируем левый корень
		}
		return balance(ptr); // балансировка всего дерева при выходе из рекурсии
	}
	Node<T>* remove(T data) //  удаление ключа data
	{
		this->root = remove(this->root, data);
		return this->root;
	}

	bool find(T item) const
	{
		Node<T>* node = this->root;
		while (node)
		{
			if (node->getData() == item)
				return true;
			node = node->getData() > item ? node->pLeft : node->pRight;
		}
		return false;
	}


	T find(int (*func)(T, T), T a, int param) const // если элемента нет выбрасывает исключение
	{
		if (param < -1 || param > 1) throw std::logic_error(AVL_INCORRECT_PARAM_MESSAGE);
		Node<T>* node = this->root;
		try
		{
			return find(node, func, a, param);
		}
		catch (const std::exception& e)
		{
			throw std::logic_error(e.what());
		}
	}
	T find(Node<T>* node, int (*func)(T, T), T a, int param) const // если элемента нет выбрасывает исключение
	{
		if (param < -1 || param > 1) throw std::logic_error(AVL_INCORRECT_PARAM_MESSAGE);
		if (node != nullptr)
			try
		{
			if (func(node->getData(), a) == param)
				// функция удовлетворяет параметру 
				return node->getData();
			if (param < 0) // ищем меньшее значение 
				return find(node->pLeft, func, a, param);
			else if (param > 0)
				return find(node->pRight, func, a, param);
			else
				if (func(node->getData(), a) > 0) // если наше значение БОЛЬШЕ искомого
					return find(node->pLeft, func, a, param); // ищем в МЕНЬШИХ значениях 
				else // если наше значение МЕНЬШЕ искомого 
					return find(node->pRight, func, a, param); // ищем в БОЛЬШИХ значениях
		}
		catch (const std::exception& e)
		{
			throw std::logic_error(e.what());
		}
		throw std::logic_error(AVL_ABNSENSE_MESSAGE);
	}
			

	void deleteTree(Node<T>* ptr) {
		if (!ptr) return;
		deleteTree(ptr->pLeft);
		deleteTree(ptr->pRight);
		delete ptr;
	}

	void treeToDA(DynamicArray<T>* res, Node<T>* ptr) {
		if (ptr == nullptr) return;
		if (ptr->pLeft == nullptr) {
			res->append(ptr->getData());
			treeToDA(res,ptr->pRight);
			return;
		}
		else {
			treeToDA(res,ptr->pLeft);
			res->append(ptr->getData());
			treeToDA(res,ptr->pRight);
			return;
		}
	}
	DynamicArray<T>* treeToDA() {
		DynamicArray<T>* res = new DynamicArray<T>(this->length);
		treeToDA(res, this->root);
		return res;
	}

	void print() {
		print(this->root);
		std::cout << std::endl;
		return;
	}
	void print(Node<T>* ptr) { 
		if (ptr == nullptr) return;
		if (ptr->pLeft == nullptr) {
			std::cout << ptr->getData() << " ";
			print(ptr->pRight);
			return;
		}
		else {
			print(ptr->pLeft);
			std::cout << ptr->getData() << " ";
			print(ptr->pRight);
			return;
		}
	}	
	
};

template <typename T>
bool operator<(const T& p1,const T& p2) {
	if (typeid(T).name() == typeid(KeyValuePair<std::string*,int>).name())
		return p1.key < p2.key;
	//else if (typeid(T).name() == typeid(KeyValuePair<int, std::string>).name())
	//	return *(p1.key) < *(p2.key);
	else
		return p1 < p2;	
}
template <typename T>
bool operator>(const T& p1, const T& p2) {
	if (typeid(T).name() == typeid(KeyValuePair<std::string*,int>).name())
		return p1.key > p2.key;
	/*else if (typeid(T).name() == typeid(KeyValuePair<int, std::string>).name())
		return *(p1.key) > *(p2.key);*/
	else
		return p1 > p2;
}

template <typename T>
bool operator==(const T& p1, const T& p2) {
	if (typeid(T).name() == typeid(KeyValuePair<std::string*,int>).name())
		return (p1.key == p2.key) && (p1.value == p2.value);
	else
		return p1 == p2;
}




#endif //AVLTREE_H
