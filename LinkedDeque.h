#pragma once
#include "Interfaces.h"
#include "LinkedContainerIterator.h"

template<class T>
class LinkedDeque :
	public Deque<T> {
private:
	node<T> *head, *tail;
	int size;
public:
	friend LinkedContainerIterator<T, LinkedDeque<T>, node<T>>;
	friend LinkedContainerIterator<T const, const LinkedDeque<T>, const node<T>>;
	LinkedDeque();
	LinkedDeque(const T& value);
	LinkedDeque(const LinkedDeque<T>&);
	LinkedDeque<T>& operator=(const LinkedDeque<T>&);
	ContainerIterator<T&> *create_iterator();
	ContainerIterator<T const&> *create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	void push_front(const T& value);
	void push_back(const T& value);
	T pop_front();
	T pop_back();
	T& peek_front();
	T& peek_back();
	~LinkedDeque();
};

#include "LinkedDeque.tcc"