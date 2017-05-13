#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {
	head = tail = NULL;
	size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const T& value) {
	node<T> *tmp = new node<T>;
	tmp->value = value;
	tmp->prev = tmp->next = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
	node<T> * tmp = other.head;
	size = 0;
	while (tmp) {
		this->push(tmp->value);
		tmp = tmp->next;
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
	node<T> *tmp;
	while (head && head->value != STATIC_NULL_VALUE) {
		tmp = head->next;
		delete head;
		head = tmp;
	} 
	tmp = other.head;
	size = 0;
	while (tmp) {
		this->push(tmp->value);
		tmp = tmp->next;
	}
	return *this;
}

template<class T>
ContainerIterator<T&>* LinkedList<T>::create_iterator() { return new LinkedContainerIterator<T, LinkedList<T>, node<T>>(this); }

template<class T>
ContainerIterator<T const&>* LinkedList<T>::create_iterator_const() const{ return new LinkedContainerIterator<T const, const LinkedList<T>, const node<T>>(this);}

template<class T>
int LinkedList<T>::get_size() const { return size; }

template<class T>
bool LinkedList<T>::is_empty() const { return !size; }

template<class T>
void LinkedList<T>::push(const T& value) {
	node<T> *tmp = new node<T>;
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = tail;
	if (is_empty())
		head = tmp;
	else
		tail->next = tmp;
	tail = tmp;
	size++;
}

template<class T>
T LinkedList<T>::pop() {
	if (is_empty())
		throw 1;
	node<T> *tmp_for_del = tail->prev;
	T tmp_value = tail->value;
	delete tail;
	tail = tmp_for_del;
	if (tail && tail->value != STATIC_NULL_VALUE)
		tail->next = NULL;
	else
		head = NULL;
	size--;
	return tmp_value;
}

template<class T>
T & LinkedList<T>::peek() { 
	if (tail) return tail->value;
	else throw 1;
}

template<class T>
T & LinkedList<T>::get(int index) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	node<T> *tmp = head;
	for (int i = 1; i <= index; i++)
		tmp = tmp->next;
	return tmp->value;
}

template<class T>
void LinkedList<T>::set(int index, const T& value) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	node<T> *tmp = head;
	for (int i = 1; i <= index; i++)
		tmp = tmp->next;
	tmp->value = value;
}

template<class T>
void LinkedList<T>::insert_at(int index, const T& value) {
	if (index > size || index < 0 || is_empty() && index)
		throw 2;
	T tmp_value;
	node<T> *tmp_node = new node<T>;
	tmp_node->value = value;
	tmp_node->next = head;
	tmp_node->prev = NULL;
	if (is_empty())
		tail = tmp_node;
	else
		head->prev = tmp_node;
	head = tmp_node;
	size++;
	for (int i = 0; i < index; i++) {
		tmp_value = get(i);
		set(i, get(i + 1));
		set(i + 1, tmp_value);
	}
}

template<class T>
void LinkedList<T>::remove_at(int index) {
	if (is_empty())
		throw 1;
	else if (index >= size || index < 0)
		throw 2;
	T tmp_head_val = head->value;
	node<T> *tmp_node = head->next;
	delete head;
	head = tmp_node;
	if (head && head->value != STATIC_NULL_VALUE)
		head->prev = NULL;
	else
		tail = NULL;
	size--;
	for (int i = index - 1; i > 0; i--)
		set(i, get(i - 1));
	if (index)
		set(0, tmp_head_val);
}

template<class T>
LinkedList<T>::~LinkedList() {
	node<T> *tmp;
	while (head && head->value != STATIC_NULL_VALUE) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
