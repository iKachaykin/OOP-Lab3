#include "StaticDeque.h"

template<class T>
StaticDeque<T>::StaticDeque(const StaticDeque<T>& other) {
	this->size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<class T>
StaticDeque<T>::StaticDeque(int size, const T& default_value) {
	if (size <= 0)
		throw 4;
	this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
StaticDeque<T>& StaticDeque<T>::operator=(const StaticDeque<T>& other) {
	delete[]arr;
	this->size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<class T>
ContainerIterator<T&>* StaticDeque<T>::create_iterator() { return new StaticContainerIterator<T, StaticDeque<T>>(this); }

template<class T>
ContainerIterator<T const&>* StaticDeque<T>::create_iterator_const() const { return new StaticContainerIterator<const T, const StaticDeque<T>>(this); }

template<class T>
int StaticDeque<T>::get_size() const { return size; }

template<class T>
bool StaticDeque<T>::is_empty() const { return !size; }


template<class T>
void StaticDeque<T>::push_front(const T& value) {
	T *tmp_arr = new T[size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i + 1] = arr[i];
	tmp_arr[0] = value;
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
void StaticDeque<T>::push_back(const T& value) {
	T *tmp_arr = new T[size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i] = arr[i];
	tmp_arr[size] = value;
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
T StaticDeque<T>::pop_front() {
	if (is_empty())
		throw 1;
	else if (size == 1)
		throw 3;
	T *tmp_arr = new T[size - 1], res_val = arr[0];
	for (int i = 0; i < size - 1; i++)
		tmp_arr[i] = arr[i + 1];
	delete[] arr;
	arr = tmp_arr;
	size--;
	return res_val;
}

template<class T>
T StaticDeque<T>::pop_back() {
	if (is_empty())
		throw 1;
	else if (size == 1)
		throw 3;
	T *tmp_arr = new T[size - 1], res_val = arr[size - 1];
	for (int i = 0; i < size - 1; i++)
		tmp_arr[i] = arr[i];
	delete[] arr;
	arr = tmp_arr;
	size--;
	return res_val;
}

template<class T>
T & StaticDeque<T>::peek_front() { return arr[0]; }

template<class T>
T & StaticDeque<T>::peek_back() { return arr[size - 1]; }

template<class T>
StaticDeque<T>::~StaticDeque() { delete[]arr; }