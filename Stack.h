#pragma once
#include "Interfaces.h"
#include "LinkedContainerIterator.h"
#include <string>

template<class T>
class Stack : 
	public PushPopContainer<T> {
private:
	node<T> *head , *tail;
	int size;
public:
	friend LinkedContainerIterator<T, Stack<T>, node<T>>;
	friend LinkedContainerIterator<T const, const Stack<T>, const node<T>>;
	Stack();
	Stack(const T& value);
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	ContainerIterator<T&> *create_iterator();
	ContainerIterator<T const&> *create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	void push(const T& value);
	T pop();
	T& peek();
	~Stack();
};

#include "Stack.tcc"