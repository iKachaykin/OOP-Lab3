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
	cout << "���������� ���������� PushPopContainer.\n";
	for (int i = 0; i < container_num; i++) {
		PushPopContainer<int> *p_p_cont = dynamic_cast<PushPopContainer<int> *>(container_arr[i]);
		if (p_p_cont) {
			cout << "���������: " << container_names[i] << "\n"
				<< "��������� ����� push(), ������� ����������, ��������� � ���� " << elems_num << " ��������� ���������:\n";
			for (int j = 0; j < elems_num; j++) {
				cout << *p_p_cont << "\n";
				p_p_cont->push(rand() % 101);
			}
			cout << "\n����������� �������� ����������, ��� ������ ���������:\n��� ������ ���������:\n";
			ContainerIterator<const int&> * p_p_cont_iter = p_p_cont->create_iterator_const();
			while (p_p_cont_iter->has_next())
					cout << p_p_cont_iter->next() << " ";
			cout << p_p_cont_iter->next() << "\n��� ������ ������ to_string():\n" << *p_p_cont 
				<< "\n�������, ������� ����� ������ �� ����������, ��� ������ ������ pop(): " << p_p_cont->peek() << "\n";
			cout << "��������� ����� pop() ��� ������� ����������, ������ ������ ��� ��������, �� ����������� ���������� � ����������� �����������.\n";
			for (int j = 0; j < elems_num; j++)
				cout << p_p_cont->pop() << " ";
			cout << "\n\n";
		}
	}
	cout << "���������� ���������� Deque.\n";
	for (int i = 0; i < container_num; i++) {
		Deque<int> *deque_cont = dynamic_cast<Deque<int> *>(container_arr[i]);
		if (deque_cont) {
			cout << "���������: " << container_names[i] << "\n"
				<< "��������� ����� push_back(), ������� ����������, ��������� � ��� ����� " << elems_num << " ��������� ���������:\n";
			for (int j = 0; j < elems_num; j++) {
				cout << *deque_cont << "\n";
				deque_cont->push_back(rand() % 101);
			}
			cout << *deque_cont << "\n";
			cout << "��������� ����� push_front(), ������� ����������, ��������� � ��� ������ " << elems_num << " ��������� ���������:\n";
			for (int j = 0; j < elems_num; j++) {
				cout << *deque_cont << "\n";
				deque_cont->push_front(rand() % 101);
			}
			cout << *deque_cont << "\n����������� �������� ����������, ��� ������ ���������:\n";
			ContainerIterator<const int&> * p_p_cont_iter = deque_cont->create_iterator_const();
			while (p_p_cont_iter->has_next())
				cout << p_p_cont_iter->next() << " ";
			cout << p_p_cont_iter->next() << "\n��� ������ ������ to_string():\n" << *deque_cont 
				<< "\n�������, ������� ����� ������ �� ����������, ��� ������ ������ pop_front(): " << deque_cont->peek_front()
				<< "\n�������, ������� ����� ������ �� ����������, ��� ������ ������ pop_back(): " << deque_cont->peek_back() << "\n";
			cout << "��������� ����� pop_back() ��� ������� ����������, ������ �� ��� ����� ��� ��������, ������� ���� ���������.\n";
			for (int j = 0; j < elems_num; j++)
				cout << deque_cont->pop_back() << " ";
			cout << "��������� ����� pop_front() ��� ������� ����������, ������ �� ��� ������ ��� ��������, ������� ���� ���������.\n";
			for (int j = 0; j < elems_num; j++)
				cout << deque_cont->pop_front() << " ";
			cout << "\n\n";
		}
	}
	cout << "������� �� ������� ���������� LinkedList, ��� ��������� ������ ���������� ���������.\n";
	LinkedList<int> l_lst(rand() % 101);
	for (int j = 0; j < elems_num - 1; j++)
		l_lst.push(rand() % 101);
	cout << "�������� ������ ��������� �������:\n" << l_lst << "\n";
	LinkedList<int> l_lst_tmp(l_lst);
	cout << "��������� ����������� �����������, �������� ��������������� ������, ������� ����� ���������� �����������.\n"
		<< "���������:\n" << l_lst << "\n���������������:\n" << l_lst_tmp << "\n�� ���������: " << ((l_lst == l_lst_tmp) ? "�������." : "�����.") << "\n����������� ��������������� ������:\n";
	l_lst_tmp.selection_sort();
	cout << l_lst_tmp << "\n��������� �� �������:\n";
	for (int i = 0; i < l_lst.get_size(); i++)
		cout << l_lst_tmp[i] << " ";
	cout << "\n������� ������� 21, � ������� 5, � 16 - � 11. ����� ����� ������ � �������� 7.\n";
	l_lst_tmp.insert_at(5, 21);
	l_lst_tmp.insert_at(11, 16);
	cout << l_lst_tmp << "\n";
	l_lst_tmp.remove_at(7);
	cout << l_lst_tmp << "\n��������� ��� ����:\n" << l_lst << "\n��������� ���������� ������ � ����������������: " << ((l_lst == l_lst_tmp) ? "�������." : "�����.") 
		<< "\n����������� �� ��������������� ������ ���������:\n";
	l_lst_tmp = l_lst;
	cout << "���������:\n" << l_lst << "\n���������������:\n" << l_lst_tmp << "\n�� ���������: " << ((l_lst == l_lst_tmp) ? "�������." : "�����.")
		<< "\n������ ��� �������� �� ���������������� ������.\n";
	for (int i = 0, lst_size = l_lst_tmp.get_size(); i < lst_size; i++)
		l_lst_tmp.pop();
	cout << "���������:\n" << l_lst << "\n���������������:\n" << l_lst_tmp << "\n�� ���������: " << ((l_lst == l_lst_tmp) ? "�������." : "�����.") << "\n";
	delete container_arr[0];
	system("pause");
}