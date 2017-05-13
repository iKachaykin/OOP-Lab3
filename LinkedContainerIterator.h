#pragma once
#include "IteratorInterface.h"
#include "Node.h"

template<class T, class LinkedContainer, class node>
class LinkedContainerIterator :
	public ContainerIterator<T&> {
private: node *it_ptr;
public:
	LinkedContainerIterator(LinkedContainer*);
	T& next();
	bool has_next();
	~LinkedContainerIterator() {};
};

#include "LinkedContainerIterator.tcc"