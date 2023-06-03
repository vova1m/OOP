#include <iostream> 
#include <list> 
#include <cstdlib> 
#include <string>
#include <Windows.h>
#include "LinkedList.h"
using namespace std;

typedef List<double>LinkedList;	//���������� ��� ��� ������ �� �������

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
		List<double> l;		//������
		int n;	//������ ������
		for (;;)
		{
			cout << menu;
			int start, finish;
			int cmd;	//�������
			cout << "\n������� �������: ";
			cin >> cmd;
			switch (cmd)
			{
			case 1:	//������� ����� ������
				cout << "\n������� ������ ������: ";
				cin >> n;
				l.make_list(n);
				break;
			case 2:	//������� ������
				if (n > 0)
					l.print_list();
				else
					cout << "\n������ ������ ����";
				break;
			case 3:	//��������� ������� �������������� � �������� ��� � ����� ������
				l.arithmetic_mean();
				break;
			case 4:	//������� �������� �� ��������� ��������� �� ������
				cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				cin >> start >> finish;
				l.delete_elem(start, finish);
				break;
				//case 5:	//������� �������� �� ��������� ��������� �� ��������
				//	cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				//	cin >> start >> finish;
				//	cout << "\n������� �������� ��������� ���������: ";
				//	cin >> k;
				//	l = delete_elem(l, start, finish, k);
				//	break;
			case 6:	//�������� �� ���� ��������� ����� ������������ � ������������� ��������
				l.sum_min_max();
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
