#include "LinkedContainerIterator.h"

template<class T, class LinkedContainer, class node>
LinkedContainerIterator<T, LinkedContainer, node>::LinkedContainerIterator(LinkedContainer *container) { it_ptr = container->head; }

template<class T, class LinkedContainer, class node>
T& LinkedContainerIterator<T, LinkedContainer, node>::next() {
	if (it_ptr) {
		T& res_val = it_ptr->value;
		it_ptr = it_ptr->next;
		return res_val;
	}
	else
		throw 5;
}

template<class T, class LinkedContainer, class node>
bool LinkedContainerIterator<T, LinkedContainer, node>::has_next() { return (it_ptr) ? it_ptr->next : false; }

template<class T, class LinkedContainer, class node>
void LinkedContainerIterator<T, LinkedContainer, node>::set_value(const T& value) {	it_ptr->value = value; }