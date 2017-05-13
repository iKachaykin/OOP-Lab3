#pragma once
#include "Interfaces.h"
#include "LinkedContainerIterator.h"

template<class T>
class Queue : 
	public PushPopContainer<T> {
private:
	node<T> *head, *tail;
	int size;
public:
	friend LinkedContainerIterator<T, Queue<T>, node<T>>;
	friend LinkedContainerIterator<T const, const Queue<T>, const node<T>>;
	Queue();
	Queue(const T& value);
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	ContainerIterator<T&> * create_iterator();
	ContainerIterator<T const&> * create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	void push(const T& value);
	T pop();
	T& peek();
	~Queue();
};

#include "Queue.tcc"