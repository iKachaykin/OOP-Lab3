#pragma once
template <class T>
class ContainerIterator {
public:
	virtual T next() = 0;
	virtual bool has_next() = 0;
	virtual ~ContainerIterator(){}
};