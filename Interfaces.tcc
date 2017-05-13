#include "Interfaces.h"


template<class T>
bool Container<T>::is_empty() const { return !get_size(); }

template <class T>
string Container<T>::to_string() {
	string res = "[";
	if (!is_empty()) {
		ContainerIterator<T const&> *iter = this->create_iterator_const();
		while (iter->has_next())
			res += std::to_string(iter->next()) + ", ";
		res += std::to_string(iter->next());
	}
	res += "]";
	return res;
}

template <class T>
bool Container<T>::operator==(Container<T> const& other) const {
	if (this->get_size() != other.get_size())
		return false;
	bool flag = true;
	ContainerIterator<T const&> * this_iter = this->create_iterator_const();
	ContainerIterator<T const&> * other_iter = other.create_iterator_const();
	while (flag) {
		if (!this_iter->has_next())
			flag = false;
		if (this_iter->next() != other_iter->next())
			return false;
	}
	return true;
}

template<class T>
T IndexedContainer<T>::operator[](int index) { return this->get(index); }

template<class T>
void IndexedContainer<T>::selection_sort() {
	T tmp;
	for (int i = 0, min_index; i < get_size(); i++) {
		min_index = i;
		for (int j = i + 1; j < get_size(); j++)
			if (get(min_index) > get(j))
				min_index = j;
		if (min_index != i) {
			tmp = get(min_index);
			set(min_index, get(i));
			set(i, tmp);
		}
	}
}

template <class T>
ostream& operator<<(ostream& os, Container<T>& container) {
	os << container.to_string();
	return os;
}
