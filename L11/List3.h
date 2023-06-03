#pragma once
#include <iostream>
#include <list>
using namespace std;
//����� ������
template <typename T>
class List
{
private:
	list<T> lst;
	T SearchMidVal();
	int _size;
public:
	List() { _size = 0; }
	~List() {};
	void make_list(int n);
	void print_list();
	void arithmetic_mean();
	void delete_elem(int, int);
	int size() { return this->_size; }
	void sum_min_max();
};
//�������� ������
template<class T>
void List<T>::make_list(int n)
{
	T a;
	for (size_t i = 0; i < n; i++)
	{
		cout << "\n������� " << i + 1 << " ������� ������ : ";
		cin >> a;
		this->lst.push_back(a);
	}
	_size = n;
}
//����� ������
template<class T>
void List<T>::print_list()
{
	cout << "\n������ ������ �����: \n";
	copy(lst.begin(), lst.end(), ostream_iterator<T>(cout, "   "));
}

template<class T>
T List<T>::SearchMidVal()
{
	T mid = 0;
	for (auto& i : lst)
		mid = mid + i;
	return mid / lst.size();
}
//������� ��� �������� �������� ��������������� � ���������� ��� � ����� ������
template<typename T>
void List<T>::arithmetic_mean()
{
	lst.push_back(SearchMidVal());
	this->_size = lst.size();
}
//������� �������� ��������� �� ��������� ���������
template<typename T>
void List<T>::delete_elem(int start, int finish)
{
	auto it_start = lst.begin();
	auto it_finish = lst.begin();
	advance(it_start, start);	//�������� ��������� �� ��������� ����� �������
	advance(it_finish, finish);	//�������� �������� �� �������� ����� �������
	lst.erase(it_start, it_finish);
}
//������� ���������� ����� ������������ � ������������� ��������
template<typename T>
void List<T>::sum_min_max()
{
	list<double> copy_l;
	auto it = lst.begin();
	T max = lst.front(); //����� ����� ������������ �������� � ������
	//���� ���������� ������������� ��������
	for (it; it != lst.end(); ++it)
	{
		if (max < *it)
			max = *it;
	}
	T min = lst.front(); //����� ����� ����������� �������� � ������
	//���� ���������� ������������ ��������
	for (it; it != lst.end(); ++it)
	{
		if (min > *it)
			min = *it;
	}
	T s = min + max; //����� ������������ � ������������� ���������
	//���������� � ��������� s
	it = lst.begin();
	for (int i = 0; i < lst.size(); i++)
	{
		T a = *it + s;
		copy_l.push_back(a);
		it++;
	}
	lst = copy_l;
}
