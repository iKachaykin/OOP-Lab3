#include "LinkedDeque.h"


template<class T>
LinkedDeque<T>::LinkedDeque() {
	head = tail = NULL;
	size = 0;
}

template<class T>
LinkedDeque<T>::LinkedDeque(const T& value) {
	node<T> *tmp = new node<T>;
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
LinkedDeque<T>::LinkedDeque(const LinkedDeque<T>& other) {
	node<T> * tmp = other.head;
	size = 0;
	while (tmp){
		this->push_back(tmp->value);
		tmp = tmp->next;
	}
}

template<class T>
LinkedDeque<T>& LinkedDeque<T>::operator=(const LinkedDeque<T>& other) {
	node<T> * tmp;
	while (head && head->value != STATIC_NULL_VALUE) {
		tmp = head->next;
		delete head;
		head = tmp;
	}	
	tmp = other.head;
	size = 0;
	while (tmp) {
		push_back(tmp->value);
		tmp = tmp->next;
	}
	return *this;
}

template<class T>
ContainerIterator<T&>* LinkedDeque<T>::create_iterator() { return new LinkedContainerIterator<T, LinkedDeque<T>, node<T>>(this); }

template<class T>
ContainerIterator<T const&>* LinkedDeque<T>::create_iterator_const() const {	return new LinkedContainerIterator<T const, const LinkedDeque<T>, const node<T>>(this); }

template<class T>
int LinkedDeque<T>::get_size() const { return size; }

template<class T>
bool LinkedDeque<T>::is_empty() const { return !size; }

template<class T>
void LinkedDeque<T>::push_front(const T& value) {
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = head;
	if (is_empty())
		tail = tmp;
	else
		head->prev = tmp;
	head = tmp;
	size++;
}

template<class T>
void LinkedDeque<T>::push_back(const T& value) {
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
T LinkedDeque<T>::pop_front() {
	if (is_empty())
		throw 1;
	node<T> *tmp_for_del = head->next;
	T tmp_value = head->value;
	delete head;
	head = tmp_for_del;
	if (head && head->value != STATIC_NULL_VALUE)
		head->prev = NULL;
	else
		tail = NULL;
	size--;
	return tmp_value;
}

template<class T>
T LinkedDeque<T>::pop_back() {
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
T & LinkedDeque<T>::peek_front() {
	if (head) return head->value; 
	else throw 1;
}

template<class T>
T & LinkedDeque<T>::peek_back() { 
	if (tail) return tail->value; 
	else throw 1;
}

template<class T>
LinkedDeque<T>::~LinkedDeque() {
	node<T> * tmp;
	while (head && head->value != STATIC_NULL_VALUE) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
