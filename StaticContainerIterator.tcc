#include "StaticContainerIterator.h"

template<class T, class StaticContainer>
StaticContainerIterator<T, StaticContainer>::StaticContainerIterator(StaticContainer *container) {
	this->it_ptr = container->arr;
	count_of_iters = 0;
	container_size = container->size;
}

template<class T, class StaticContainer>
T& StaticContainerIterator<T, StaticContainer>::next() {
	count_of_iters++;
	return *it_ptr++;
}

template<class T, class StaticContainer>
bool StaticContainerIterator<T, StaticContainer>::has_next() {
	return count_of_iters < container_size - 1;
}