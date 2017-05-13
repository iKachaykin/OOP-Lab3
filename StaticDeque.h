#pragma once
#include "Interfaces.h"
#include "StaticContainerIterator.h"
template<class T>
class StaticDeque :
	public Deque<T> {
private:
	T *arr;
	int size;
public:
	friend StaticContainerIterator<T, StaticDeque<T>>;
	friend StaticContainerIterator<const T, const StaticDeque<T>>;
	StaticDeque(const StaticDeque<T>&);
	StaticDeque(int size, const T& default_value);
	StaticDeque<T>& operator=(const StaticDeque<T>&);
	ContainerIterator<T&> * create_iterator();
	ContainerIterator<T const&> * create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	void push_front(const T& value);
	void push_back(const T& value);
	T pop_front();
	T pop_back();
	T& peek_front();
	T& peek_back();
	~StaticDeque();
};

#include "StaticDeque.tcc"