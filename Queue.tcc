#include "Queue.h"

template<class T>
ContainerIterator<T&>* Queue<T>::create_iterator() { return new LinkedContainerIterator<T, Queue<T>, node<T>>(this);}

template<class T>
ContainerIterator<T const&>* Queue<T>::create_iterator_const() const { return new LinkedContainerIterator<T const, const Queue<T>, const node<T>>(this);}

template<class T>
Queue<T>::Queue() {
	head = tail = NULL;
	size = 0;
}

template<class T>
Queue<T>::Queue(const T& value) {
	node<T> * tmp = new node<T>;
	tmp->value = value;
	tmp->next = tmp->prev = NULL;
	head = tail = tmp;
	size = 1;
}

template<class T>
Queue<T>::Queue(const Queue<T>& other) {
	node<T> * tmp = other.head;
	size = 0;
	while (tmp) {
		this->push(tmp->value);
		tmp = tmp->next;
	}
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	node<T> * tmp;
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
int Queue<T>::get_size() const { return size; }

template<class T>
bool Queue<T>::is_empty() const { return !size; }

template<class T>
void Queue<T>::push(const T& value) {
	node<T> * tmp = new node<T>;
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
T Queue<T>::pop() {
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
T & Queue<T>::peek() { 
	if (head) return head->value;
	else throw 1;
}

template<class T>
Queue<T>::~Queue(){
	node<T> * tmp;
	while (head && head->value != STATIC_NULL_VALUE) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}