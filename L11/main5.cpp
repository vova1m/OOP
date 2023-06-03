#include <C:\Users\vovam\source\repos\L11_OOP\L11_OOP\Pair.h>
#include <iostream> 
#include <list> 
#include <cstdlib> 
#include <string>
#include <Windows.h>
#include "Priority_queue.h"
using namespace std;

typedef PriorityQueue<double>PQ;	//���������� ��� ��� ������ �� �������

const char menu[] = " 1 - ������� ������� � ������������\n"
" 2 - ������� ������� � ������������\n"
" 3 - ��������� ������� �������������� � �������� ��� � ����� ������� � ������������\n"
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
		PriorityQueue<double> q;		//������
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
			case 1:	//������� ����� ������� � ������������
				cout << "\n������� ������ ������� � ������������: ";
				cin >> n;
				q.make_queue(n);
				break;
			case 2:	//������� ������� � ������������
				if (n > 0)
					q.print_queue();
				else
					cout << "\n������ ������� � ������������ ������";
				break;
			case 3:	//��������� ������� �������������� � �������� ��� � ����� ������� � ������������
				q.arithmetic_mean();
				break;
			case 4:	//������� �������� �� ��������� ��������� �� ������
				cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				cin >> start >> finish;
				q.delete_elem(start, finish);
				break;
				//case 5:	//������� �������� �� ��������� ��������� �� ��������
				//	cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				//	cin >> start >> finish;
				//	cout << "\n������� �������� ��������� ���������: ";
				//	cin >> k;
				//	l = delete_elem(l, start, finish, k);
				//	break;
			case 6:	//�������� �� ���� ��������� ����� ������������ � ������������� ��������
				q.sum_min_max();
				break;
			case 0:	//����� �� ���������
				cout << "\n������� ��� ������� ������ ���������!";
				return 0;
			default: //����������� ��������� �������
				cout << "\n������������ �������, ���������� ������";
			}
			cout << endl;
			/*system("pause");
			system("cls");*/
		}
	}
	catch (double)		//���� ��������� ������
	{
		cout << "������!";
	}
	return 0;
}
