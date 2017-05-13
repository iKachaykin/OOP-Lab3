#include "StaticArray.h"

template<class T>
StaticArray<T>::StaticArray(int size, const T& default_value) {
	if (size <= 0)
		throw 4;
	this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
StaticArray<T>::StaticArray(const StaticArray<T>& other) {
	this->size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<class T>
StaticArray<T>& StaticArray<T>::operator=(const StaticArray<T>& other) {
	delete[] arr;
	this->size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<class T>
ContainerIterator<T&>* StaticArray<T>::create_iterator() { return new StaticContainerIterator<T, StaticArray<T>>(this); }

template<class T>
ContainerIterator<T const&>* StaticArray<T>::create_iterator_const() const { return new StaticContainerIterator<const T, const StaticArray<T>>(this); }

template<class T>
int StaticArray<T>::get_size() const { return size; }

template<class T>
bool StaticArray<T>::is_empty() const { return !size; }

template<class T>
T & StaticArray<T>::get(int index) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	return arr[index];
}

template<class T>
void StaticArray<T>::set(int index, const T& value) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	arr[index] = value;
}

template<class T>
StaticArray<T>::~StaticArray() { delete[] arr; }