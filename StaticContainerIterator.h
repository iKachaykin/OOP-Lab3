#pragma once
#include "IteratorInterface.h"
template<class T, class StaticContainer>
class StaticContainerIterator :
	public ContainerIterator<T&> {
private: 
	T* it_ptr;
	int container_size, count_of_iters;
public:
	StaticContainerIterator(StaticContainer *);
	T& next();
	bool has_next();
	~StaticContainerIterator() {};
};

#include "StaticContainerIterator.tcc"