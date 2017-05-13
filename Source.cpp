#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "LinkedDeque.h"
#include "StaticArray.h"
#include "StaticDeque.h"
#include <ctime>

using namespace std;

void main() {
	srand(time(0));
	setlocale(LC_ALL, "ru");
	const int container_num = 7, ind_container_num = 3, ins_container_num = 2, p_p_container_num = 4, deque_container_num = 2;
	const string container_names[container_num]{
		"ArrayList",
		"LinkedDeque",
		"LinkedList",
		"Queue",
		"Stack",
		"StaticArray",
		"StaticDeque"
	};
	int elems_num = 10;
	Container<int> *container_arr[container_num] {
		new ArrayList<int>(1, 0),
		new LinkedDeque<int>(),
		new LinkedList<int>(),
		new Queue<int>(),
		new Stack<int>(),
		new StaticArray<int>(1, 0),
		new StaticDeque<int>(1, 0),
	};
	cout << "Контейнеры интерфейса PushPopContainer.\n";
	for (int i = 0; i < container_num; i++) {
		PushPopContainer<int> *p_p_cont = dynamic_cast<PushPopContainer<int> *>(container_arr[i]);
		if (p_p_cont) {
			cout << "Контейнер: " << container_names[i] << "\n"
				<< "Используя метод push(), данного контейнера, добавляем в него " << elems_num << " случайных элементов:\n";
			for (int j = 0; j < elems_num; j++) {
				cout << *p_p_cont << "\n";
				p_p_cont->push(rand() % 101);
			}
			cout << "\nРаспечатаем элементы контейнера, при помощи итератора:\nПри помощи итератора:\n";
			ContainerIterator<const int&> * p_p_cont_iter = p_p_cont->create_iterator_const();
			while (p_p_cont_iter->has_next())
					cout << p_p_cont_iter->next() << " ";
			cout << p_p_cont_iter->next() << "\nПри помощи метода to_string():\n" << *p_p_cont 
				<< "\nЭлемент, который будет удален из контейнера, при вызове метода pop(): " << p_p_cont->peek() << "\n";
			cout << "Используя метод pop() для данного контейнера, удалим оттуда все элементы, за исключением начального в статических контейнерах.\n";
			for (int j = 0; j < elems_num; j++)
				cout << p_p_cont->pop() << " ";
			cout << "\n\n";
		}
	}
	cout << "Контейнеры интерфейса Deque.\n";
	for (int i = 0; i < container_num; i++) {
		Deque<int> *deque_cont = dynamic_cast<Deque<int> *>(container_arr[i]);
		if (deque_cont) {
			cout << "Контейнер: " << container_names[i] << "\n"
				<< "Используя метод push_back(), данного контейнера, добавляем в его конец " << elems_num << " случайных элементов:\n";
			for (int j = 0; j < elems_num; j++) {
				cout << *deque_cont << "\n";
				deque_cont->push_back(rand() % 101);
			}
			cout << *deque_cont << "\n";
			cout << "Используя метод push_front(), данного контейнера, добавляем в его начало " << elems_num << " случайных элементов:\n";
			for (int j = 0; j < elems_num; j++) {
				cout << *deque_cont << "\n";
				deque_cont->push_front(rand() % 101);
			}
			cout << *deque_cont << "\nРаспечатаем элементы контейнера, при помощи итератора:\n";
			ContainerIterator<const int&> * p_p_cont_iter = deque_cont->create_iterator_const();
			while (p_p_cont_iter->has_next())
				cout << p_p_cont_iter->next() << " ";
			cout << p_p_cont_iter->next() << "\nПри помощи метода to_string():\n" << *deque_cont 
				<< "\nЭлемент, который будет удален из контейнера, при вызове метода pop_front(): " << deque_cont->peek_front()
				<< "\nЭлемент, который будет удален из контейнера, при вызове метода pop_back(): " << deque_cont->peek_back() << "\n";
			cout << "Используя метод pop_back() для данного контейнера, удалим из его конца все элементы, которые были добавлены.\n";
			for (int j = 0; j < elems_num; j++)
				cout << deque_cont->pop_back() << " ";
			cout << "Используя метод pop_front() для данного контейнера, удалим из его начала все элементы, которые были добавлены.\n";
			for (int j = 0; j < elems_num; j++)
				cout << deque_cont->pop_front() << " ";
			cout << "\n\n";
		}
	}
	cout << "Покажем на примере контейнера LinkedList, что остальные методы определены правильно.\n";
	LinkedList<int> l_lst(rand() % 101);
	for (int j = 0; j < elems_num - 1; j++)
		l_lst.push(rand() % 101);
	cout << "Заполним список случаными числами:\n" << l_lst << "\n";
	LinkedList<int> l_lst_tmp(l_lst);
	cout << "Используя конструктор копирования, создадим вспомогательный список, который будет копировать изначальный.\n"
		<< "Начальный:\n" << l_lst << "\nВспомогательный:\n" << l_lst_tmp << "\nИх равенство: " << ((l_lst == l_lst_tmp) ? "истинно." : "ложно.") << "\nОтсортируем вспомогательный список:\n";
	l_lst_tmp.selection_sort();
	cout << l_lst_tmp << "\nОбратимся по индексу:\n";
	for (int i = 0; i < l_lst.get_size(); i++)
		cout << l_lst_tmp[i] << " ";
	cout << "\nВставим элемент 21, в позицию 5, и 16 - в 11. После этого удалим с индексом 7.\n";
	l_lst_tmp.insert_at(5, 21);
	l_lst_tmp.insert_at(11, 16);
	cout << l_lst_tmp << "\n";
	l_lst_tmp.remove_at(7);
	cout << l_lst_tmp << "\nНачальный при этом:\n" << l_lst << "\nРавенство начального списка и вспомогательного: " << ((l_lst == l_lst_tmp) ? "истинно." : "ложно.") 
		<< "\nПрисваиваем во вспомогательный список начальный:\n";
	l_lst_tmp = l_lst;
	cout << "Начальный:\n" << l_lst << "\nВспомогательный:\n" << l_lst_tmp << "\nИх равенство: " << ((l_lst == l_lst_tmp) ? "истинно." : "ложно.")
		<< "\nУдалим все элементы из вспомогательного списка.\n";
	for (int i = 0, lst_size = l_lst_tmp.get_size(); i < lst_size; i++)
		l_lst_tmp.pop();
	cout << "Начальный:\n" << l_lst << "\nВспомогательный:\n" << l_lst_tmp << "\nИх равенство: " << ((l_lst == l_lst_tmp) ? "истинно." : "ложно.") << "\n";
	delete container_arr[0];
	system("pause");
}