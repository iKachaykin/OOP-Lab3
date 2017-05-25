#pragma once
#include "Interfaces.h"
#include "StaticContainerIterator.h"
template<class T>
class ArrayList :
	public PushPopContainer<T>, public InsertableContainer<T> {
private:
	const int DEFAULT_ARRAY_SIZE = 16;
	int size;
	T *arr;
public:
	typedef ContainerIterator<T&> iterator;
	friend StaticContainerIterator<T, ArrayList<T>>;
	friend StaticContainerIterator<T const, const ArrayList<T>>;
	ArrayList(const T& default_value);
	ArrayList(int array_size, const T& default_value);
	ArrayList(const ArrayList<T>&);
	ArrayList<T>& operator=(const ArrayList<T>&);
	ContainerIterator<T&> * create_iterator();
	ContainerIterator<T const&> * create_iterator_const() const;
	int get_size() const;
	bool is_empty() const;
	void push(const T& value);
	T pop(); 
	T& peek();
	T& get(int index);
	void set(int index, const T& value);
	void insert_at(int index, const T& value);
	void remove_at(int index);
	~ArrayList();
};

#include "ArrayList.tcc"