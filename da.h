#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <string>

#include "kvp.h"

const std::string DA_INDEX_OUT_OF_RANGE_MESSAGE = "QuackDA! Index out of range.";
const std::string DA_NEGATIVE_SIZE_MESSAGE = "QuackDA! Size < 0.";
const std::string DA_ZERO_SIZE_MESSAGE = "QuackDA! Size = 0";


template <typename T> class DynamicArray {
private:
	T* data = nullptr; // указатель на первые данные 
	int size = 0; // по умолчанию массив пустой
	int length = 0;
public:
	// пустой конструктор, size = 0
	DynamicArray() : size(0), length(0) {}

	// пустой конструктор определЄнного размера 
	DynamicArray(int size) : size(size) {
		if (size < 0) throw std::length_error(DA_NEGATIVE_SIZE_MESSAGE);
		this->data = new T[size];
		this->length = 0;
	}

	//  опировать элементы из переданного массива
	DynamicArray(T* data, int length) : DynamicArray(length) {
		for (int i = 0; i < length; i++)
			this->data[i] = data[i];
		this->length = length;
	}

	//  опирующий конструктор (определЄнной длины)
	DynamicArray(const DynamicArray<T>& array, int length) : DynamicArray(length) {
		if (length > array.length) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

		for (int i = 0; i < length; i++)
			this->data[i] = array.data[i];

		this->length = length;
	}

	//  опирующий конструктор
	DynamicArray(const DynamicArray<T>& array) :
		DynamicArray(array.data, array.length) {}

	// ƒеструктор
	virtual ~DynamicArray() {
		delete[] this->data;
		this->size = 0;
		this->length = 0;
	}


	T get(int index) const {
		if (index < 0 || index >= this->length) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

		return this->data[index];
	}

	// ƒекомпозици€

	// ѕолчуить размер массива 
	int getSize() const { return this->size; }

	int getLength() const { return this->length; }

	// изменить значение по индексу 
	void set(const T& value, int index) {
		if (index < 0 || index >= this->length) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

		this->data[index] = value;
	}

	// добавить в конец 
	void append(T elem) {
		int o_size = this->size;
		int o_length = this->length;

		if (o_length < o_size) {
			this->data[o_length] = elem;
			this->length++;
		}
		else {
			if (size == 0) {
				this->resize(5);
			}
			else {
				this->resize(o_size + ceil(0.2 * o_size));
			}
			this->data[o_length] = elem;
			this->length++;
		}
	}

	// изменить размер
	void resize(int size) {
		if (size < 0) throw std::length_error(DA_NEGATIVE_SIZE_MESSAGE);

		T* newData = new T[size]; //создаЄм новый массив нужного размера

		// если переданный больше данного, то переданный, иначе данный
		for (int i = 0; i < (this->size > size ? size : this->size); i++)
			newData[i] = data[i]; // перемещаем данные 

		int length = (this->length > size ? size : this->length);

		delete[] data; //удал€ем старый массив
		this->data = newData; //замен€ем новым

		this->length = length;
		this->size = size; // не забываем мен€ть размер!!
	}
	
	int indexOf(T data) {
		return indexOf(data, 0, this->length-1);
	}
	int indexOf(T data,int first,int last){
		int mid = (first + (last - first) / 2);
		if (data == this->get(mid))
			return mid;
		else if (first == last) return -1;
		if (data < this->get(mid))
			return indexOf(data, first, mid);
		else return indexOf(data, mid+1, last);
	}	

	// сравнение массивов на равенство
	bool operator==(const DynamicArray<T>& arr) const {
		if (this->length != arr.length) return false;

		for (int i = 0; i < this->length; i++)
			if (this->get(i) != arr.get(i)) return false;

		return true;
	} 
	
	bool isEqual(T* data, int length) {
		if (this->length != length) return false;

		for (int i = 0; i < this->length; i++)
			if (this->get(i) != data[i]) return false;

		return true;
	}

	// приравниваем массив к другому
	DynamicArray<T>& operator=(const DynamicArray& array) {
		delete[] this->data;

		this->size = array.size;
		this->length = array.length;
		this->data = new T[this->size];

		for (int i = 0; i < length; i++)
			this->data[i] = array.data[i];

		return *this;
	}

	void print() {
		for (int i = 0; i < length; i++)
			std::cout << this->data[i] << ' ';
		std::cout << std::endl;
	}

};

#endif // DYNAMIC_ARRAY_H