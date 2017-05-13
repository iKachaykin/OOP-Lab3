#pragma once
#include "Interfaces.h"
#include "LinkedContainerIterator.h"

template<class T>
class LinkedList :
	public PushPopContainer<T>, public InsertableContainer<T> {
private:
	node<T> *head, *tail;
	int size;
public:
	friend LinkedContainerIterator<T, LinkedList<T>, node<T>>;
	friend LinkedContainerIterator<T const, const LinkedList<T>, const node<T>>;
	LinkedList();
	LinkedList(const T& value);
	LinkedList(const LinkedList<T>&);
	LinkedList<T>& operator=(const LinkedList<T>&);
	ContainerIterator<T&> * create_iterator();
	ContainerIterator<T const&> * create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	void push(const T& value);
	T pop();
	T& peek();
	T& get(int index);
	void set(int index, const T& value);
	void insert_at(int index, const T& value);
	void remove_at(int index);
	~LinkedList();
};

#include "LinkedList.tcc"