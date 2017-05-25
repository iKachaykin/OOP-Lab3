#pragma once
#include "Interfaces.h"
#include "StaticContainerIterator.h"
template<class T>
class StaticArray :
	public IndexedContainer<T> {
private:
	T *arr;
	int size;
public:
	typedef ContainerIterator<T&> iterator;
	friend StaticContainerIterator<T, StaticArray<T>>;
	friend StaticContainerIterator<const T, const StaticArray<T>>;
	StaticArray(int size, const T& default_value);
	StaticArray(const StaticArray<T>&);
	StaticArray<T>& operator=(const StaticArray<T>&);
	ContainerIterator<T&> * create_iterator();
	ContainerIterator<T const&> * create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	T& get(int index);
	void set(int index, const T& value);
	~StaticArray();
};

#include "StaticArray.tcc"