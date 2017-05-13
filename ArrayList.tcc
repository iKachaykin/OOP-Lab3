#include "ArrayList.h"


template<class T>
ArrayList<T>::ArrayList(const T& default_value) {
	size = DEFAULT_ARRAY_SIZE;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
ArrayList<T>::ArrayList(int size, const T& default_value) {
	if (size <= 0)
		throw 4;
	this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value;
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
	this->size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
	delete[] this->arr;
	this->size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
	return *this;
}

template<class T>
ContainerIterator<T&>* ArrayList<T>::create_iterator() { return new StaticContainerIterator<T, ArrayList<T>>(this); }

template<class T>
ContainerIterator<const T&>* ArrayList<T>::create_iterator_const() const { return new StaticContainerIterator<T const, const ArrayList<T>>(this); }

template<class T>
int ArrayList<T>::get_size() const { return size; }

template<class T>
bool ArrayList<T>::is_empty() const { return !size; }

template<class T>
void ArrayList<T>::push(const T& value) {
	T *tmp_arr = new T[size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i] = arr[i];
	tmp_arr[size] = value;
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
T ArrayList<T>::pop() {
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
T & ArrayList<T>::peek() { 
	if(size != 0) return arr[size - 1];
	else throw 1;
}

template<class T>
T & ArrayList<T>::get(int index) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	return arr[index];
}

template<class T>
void ArrayList<T>::set(int index, const T& value) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	arr[index] = value;
}

template<class T>
void ArrayList<T>::insert_at(int index, const T& value) {
	if (index > size || index < 0)
		throw 2;
	T *tmp_arr = new T[size + 1], tmp_val;
	tmp_arr[0] = value;
	for (int i = 0; i < size; i++)
		tmp_arr[i + 1] = arr[i];
	for (int i = 0; i < index; i++) {
		tmp_val = tmp_arr[i];
		tmp_arr[i] = tmp_arr[i + 1];
		tmp_arr[i + 1] = tmp_val;
	}
	delete[] arr;
	arr = tmp_arr;
	size++;
}

template<class T>
void ArrayList<T>::remove_at(int index) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	else if (size == 1)
		throw 3;
	T *tmp_arr = new T[size - 1];
	for (int i = 0; i < index; i++)
		tmp_arr[i] = arr[i];
	for (int i = index + 1; i < size; i++)
		tmp_arr[i - 1] = arr[i];
	delete[] arr;
	arr = tmp_arr;
	size--;
}

template<class T>
ArrayList<T>::~ArrayList() { delete[] arr; }