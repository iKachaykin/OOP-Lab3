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

template<class T>
void Container<T>::selection_sort() {
		int min_value_index = 0;
		ContainerIterator<T&> *iter = this->create_iterator(), *to_min_iter;
		T tmp, hyp_min;
		for (int i = 0; i < get_size(); i++) {
			iter = this->create_iterator();
			for (int j = 0; j < i; j++)
				iter->next();
			T& to_ins_ref = iter->next();
			min_value_index = i;
			for (int j = i + 1; j < get_size(); j++) {
				to_min_iter = this->create_iterator();
				for (int min_i = 0; min_i < min_value_index; min_i++)
					to_min_iter->next();
				hyp_min = to_min_iter->next();
				tmp = iter->next();
				if (hyp_min > tmp)
					min_value_index = j;
			}
			to_min_iter = this->create_iterator();
			for (int min_i = 0; min_i < min_value_index; min_i++)
				to_min_iter->next();
			T& min_value_ref = to_min_iter->next();
			if (min_value_ref != to_ins_ref)
				swap(min_value_ref, to_ins_ref);
		}
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

template <class T>
ostream& operator<<(ostream& os, Container<T>& container) {
	os << container.to_string();
	return os;
}
