#pragma once
#include <iostream>
#include "Node.h"
#include "IteratorInterface.h"
#include <algorithm>

using namespace std;

template<class T> class Container;

template<class T> 
ostream& operator<<(ostream&, const Container<T>&);

template<class T>
class Container {
public:
	virtual ContainerIterator<T&> *create_iterator() = 0;
	virtual ContainerIterator<T const&> *create_iterator_const() const = 0;
	bool operator==(Container<T> const&) const;
	virtual int get_size() const = 0;
	virtual bool is_empty() const;
	virtual string to_string();
	void selection_sort();
	virtual ~Container() {}
};

template<class T>
class PushPopContainer : 
	public virtual Container<T> {
public:
	virtual void push(T const&) = 0;
	virtual T pop() = 0;
	virtual T& peek() = 0;
};

template<class T>
class Deque : 
	public virtual Container<T> {
public:
	virtual void push_front(T const&) = 0;
	virtual void push_back(T const&) = 0;
	virtual T pop_front() = 0;
	virtual T pop_back() = 0;
	virtual T& peek_front() = 0;
	virtual T& peek_back() = 0;
};

template<class T>
class IndexedContainer : 
	public virtual Container<T> {
public:
	virtual T& get(int) = 0;
	virtual void set(int, T const&) = 0;
	T operator[](int);
};

template<class T>
class InsertableContainer :	
	public IndexedContainer<T> {
public:
	virtual void insert_at(int, T const&) = 0;
	virtual void remove_at(int) = 0;
};

template<class cont>
void sort(cont &for_sort_container){
	int min_value_index = 0;
	cont::iterator *tmp_iter = for_sort_container.create_iterator(), *to_min_iter, *to_ins_iter;
	for (int i = 0; i < for_sort_container.get_size(); i++) {
		to_ins_iter = for_sort_container.create_iterator();
		tmp_iter = for_sort_container.create_iterator();
		for (int j = 0; j < i; j++) {
			to_ins_iter->next();
			tmp_iter->next();
		}
		tmp_iter->next();
		min_value_index = i;
		for (int j = i + 1; j < for_sort_container.get_size(); j++) {
			to_min_iter = for_sort_container.create_iterator();
			for (int min_i = 0; min_i < min_value_index; min_i++)
				to_min_iter->next();
			if (to_min_iter->next() > tmp_iter->next())
				min_value_index = j;
		}
		to_min_iter = for_sort_container.create_iterator();
		for (int min_i = 0; min_i < min_value_index; min_i++)
			to_min_iter->next();
		swap(to_min_iter->next(), to_ins_iter->next());
	}
}

#include "Interfaces.tcc"