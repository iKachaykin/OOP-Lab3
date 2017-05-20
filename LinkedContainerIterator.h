#pragma once
#include "IteratorInterface.h"

template<class T, class LinkedContainer, class node>
class LinkedContainerIterator :
	public ContainerIterator<T&> {
private: node *it_ptr;
public:
	LinkedContainerIterator(LinkedContainer*);
	//LinkedContainerIterator(const LinkedContainerIterator<T, LinkedContainer, node>&);
	//LinkedLinkedContainerIterator<T, LinkedContainer, node>& operator=(const LinkedContainerIterator<T, LinkedContainer, node>&);
	T& next();
	bool has_next();
	void set_value(const T&);
	~LinkedContainerIterator() {};
};

#include "LinkedContainerIterator.tcc"