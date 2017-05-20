#include "Stack.h"

template<class T>
Stack<T>::Stack() {
	tail = head = NULL;
	size = 0;
}

template<class T>
Stack<T>::Stack(const T& value) {
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) {
	node<T> * tmp = other.tail;
	size = 0;
	while (tmp) {
		this->push(tmp->value);
		tmp = tmp->prev;
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	node<T> * tmp;
	while (head && head->value != STATIC_NULL_VALUE) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
	tmp = other.tail;
	size = 0;
	while (tmp) {
		this->push(tmp->value);
		tmp = tmp->prev;
	}
	return *this;
}

template<class T>
ContainerIterator<T&>* Stack<T>::create_iterator() { return new LinkedContainerIterator<T, Stack<T>, node<T>>(this);}

template<class T>
ContainerIterator<T const&>* Stack<T>::create_iterator_const() const { return new LinkedContainerIterator<T const, const Stack<T>, const node<T>>(this);}

template<class T>
bool Stack<T>::is_empty() const { return !size; }

template<class T>
int Stack<T>::get_size() const { return size; }

template<class T>
void Stack<T>::push(const T& value){
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = head;
	if (!is_empty())
		head->prev = tmp;
	else
		tail = tmp;
	head = tmp;
	size++;
}

template<class T>
T Stack<T>::pop() {
	if (is_empty())
		throw 1;
	node<T> *tmp_for_del = head->next;
	T tmp_value = head->value;
	delete head;
	head = tmp_for_del;
	if (head)
		head->prev = NULL;
	else
		tail = 0;
	size--;
	return tmp_value;
}

template<class T>
T & Stack<T>::peek() { 
	if(head) return head->value;
	else throw 1;
}

template<class T>
Stack<T>::~Stack() {
	node<T> * tmp;
	for (int i = 0; head && i < get_size(); i++) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}