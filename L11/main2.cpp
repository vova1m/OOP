#include <iostream> 
#include <list> 
#include <cstdlib> 
#include <string>
#include <Windows.h>
#include "Pair.h"
using namespace std;

typedef list<Pair>LinkedList;	//���������� ��� ��� ������ �� �������
//������� ��� ������������ ������
LinkedList make_list(LinkedList l, int n)
{
	for (int i = 0; i < n; i++)
	{
		Pair a;
		cout << "\n������� " << i + 1 << " ������� ������ : ";
		cin >> a;
		l.push_back(a); //���������� a � ����� ������
	}
	return l;
}
//������� ��� ������ ������ 
void print_list(LinkedList l)
{
	cout << "\n������ ������ �����: \n";
	copy(l.begin(), l.end(), ostream_iterator<Pair>(cout, "   "));
}
//������� ��� �������� �������� ��������������� � ���������� ��� � ����� ������
LinkedList arithmetic_mean(LinkedList l)
{
	list<Pair>::iterator it = l.begin();
	Pair s;
	//������� ������
	for (int i = 0; i < l.size(); i++)
	{
		s = s + *it;
		it++;
	}
	int n = l.size();	//���������� ��������� � ������� 
	l.push_back(s / n);
	return l;
}
//������� �������� ��������� �� ��������� ��������� �� ������
LinkedList delete_elem(LinkedList l, int start, int finish)
{
	list<Pair>::iterator it_start = l.begin();
	list<Pair>::iterator it_finish = l.begin();
	advance(it_start, start);	//�������� ��������� �� ��������� ����� �������
	advance(it_finish, finish);	//�������� �������� �� �������� ����� �������
	l.erase(it_start, it_finish);
	return l;
}
//������� �������� ��������� �� ��������� ��������� �� ���������
//LinkedList delete_elem(LinkedList l, int start, int finish, Pair k)
//{
//	list<Pair>::iterator it_start = l.begin();
//	list<Pair>::iterator it_finish = l.begin();
//	advance(it_start, start);	//�������� ��������� �� ������ �� ��������� ����� �������
//	advance(it_finish, finish);	//�������� �������� �� ����� �� �������� ����� �������
//	for (it_start; it_start != it_finish; ++it_start)
//	{
//		l.remove(k);	//�������� ��������� �� ��������
//	}
//	return l;
//}

//������� ���������� ����� ������������ � ������������� ��������
LinkedList sum_min_max(LinkedList l)
{
	list<Pair> copy_l;
	list<Pair>::iterator it = l.begin();
	Pair max = l.front(); //����� ����� ������������ �������� � ������
	//���� ���������� ������������� ��������
	for (it; it != l.end(); ++it)
	{
		if (max < *it)
			max = *it;
	}
	Pair min = l.front(); //����� ����� ����������� �������� � ������
	//���� ���������� ������������ ��������
	for (it; it != l.end(); ++it)
	{
		if (min > *it)
			min = *it;
	}
	Pair s = min + max; //����� ������������ � ������������� ���������
	//���������� � ��������� s
	it = l.begin();
	for (int i = 0; i < l.size(); i++)
	{
		Pair a = *it + s;
		copy_l.push_back(a);
		it++;
	}
	return copy_l;
}

const char menu[] = " 1 - ������� ������\n"
" 2 - ������� ������\n"
" 3 - ��������� ������� �������������� � �������� ��� � ����� ������\n"
" 4 - ������� �������� �� ��������� ��������� �� ������\n"
" 6 - �������� �� ���� ��������� ����� ������������ � ������������� ��������\n"
" 0 - ����� �� ���������\n";
//�������� ������� 
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		list<Pair> l;		//������
		int n = 0;	//������ ������
		for (;;)
		{
			cout << menu;
			int start, finish;
			/*Pair k;*/
			int cmd;	//�������
			cout << "\n������� �������: ";
			cin >> cmd;
			switch (cmd)
			{
			case 1:	//������� ����� ������
				l.clear();
				cout << "\n������� ������ ������: ";
				cin >> n;
				l = make_list(l, n);
				break;
			case 2:	//������� ������
				if (n > 0)
					print_list(l);
				else
					cout << "\n������ ������ ����";
				break;
			case 3:	//��������� ������� �������������� � �������� ��� � ����� ������
				l = arithmetic_mean(l);
				break;
			case 4:	//������� �������� �� ��������� ��������� �� ������
				cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				cin >> start >> finish;
				l = delete_elem(l, start, finish);
				break;
				//case 5:	//������� �������� �� ��������� ��������� �� ��������
				//	cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				//	cin >> start >> finish;
				//	cout << "\n������� �������� ��������� ���������: ";
				//	cin >> k;
				//	l = delete_elem(l, start, finish, k);
				//	break;
			case 6:	//�������� �� ���� ��������� ����� ������������ � ������������� ��������
				l = sum_min_max(l);
				break;
			case 0:	//����� �� ���������
				cout << "\n������� ��� ������� ������ ���������!";
				return 0;
			default: //����������� ��������� �������
				cout << "\n������������ �������, ���������� ������";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
	}
	catch (double)		//���� ��������� ������
	{
		cout << "������!";
	}
	return 0;
}
