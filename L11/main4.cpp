#include <C:\Users\vovam\source\repos\L11_OOP\L11_OOP\Pair.h>
#include <list> 
#include <queue> 
#include <cstdlib> 
#include <Windows.h>

typedef priority_queue<Pair>PQ;		//������� � ������������
typedef list<Pair>LinkedList;		//������

//������� ��� �������� ������� � ������������
PQ make_queue(PQ s, int n)
{
	for (int i = 1; i <= n; i++)
	{
		Pair a;
		cout << "\n������� " << i + 1 << " ������� ������� : ";
		cin >> a;
		s.push(a); //���������� a � ����� �������
	}
	return s;
}
//������� ��� ������ ������� � ������������
void print_queue(PQ q)
{
	int j = 0;
	cout << "\n������ ������ �����: \n";
	//priority_queue<Pair> temp(q);
	while (!q.empty())
	{
		cout << j++ << ". " << q.top() << endl;
		q.pop();
	}
}
//������� ��� �������� �������� ��������������� � ���������� ��� � ����� �������
PQ arithmetic_mean(PQ q)
{
	priority_queue<Pair> temp(q);
	Pair s;
	while (!temp.empty())
	{
		s = s + temp.top();
		temp.pop();
	}
	q.push(s / q.size());
	return q;
}
//������� �������� ��������� �� ��������� ��������� �� ������
PQ delete_elem(PQ q, int start, int finish)
{
	priority_queue<Pair> temp;
	Pair t;
	int n = 1;
	for (n; n <= start; n++)
	{
		t = q.top();
		q.pop();
		temp.push(t);
	}
	for (n; n <= finish; n++)
	{
		q.pop();
	}
	for (n; n <= q.size(); n++)
	{
		t = q.top();
		q.pop();
		temp.push(t);
	}
	return temp;
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
PQ sum_min_max(PQ q)
{
	priority_queue<Pair> temp;
	Pair t;
	Pair max = q.top(); //����� ����� ������������ �������� � ������
	//���� ���������� ������������� ��������
	for (int i = 1; i <= q.size(); i++)
	{
		if (max < q.top())
			max = q.top();
	}
	Pair min = q.top(); //����� ����� ����������� �������� � �������
	//���� ���������� ������������ ��������
	for (int i = 1; i <= q.size(); i++)
	{
		if (min > q.top())
			min = q.top();
	}
	Pair s = min + max; //����� ������������ � ������������� ���������
	//���������� � ��������� s
	for (int i = 1; i <= q.size(); i++)
	{
		Pair a = q.top() + s;
		temp.push(a);
	}
	return temp;
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
		priority_queue<Pair> s;		//������� � ����������� 
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
				cout << "\n������� ������ ������� � �����������: ";
				cin >> n;
				s = make_queue(s, n);
				break;
			case 2:	//������� ������
				if (n > 0)
					print_queue(s);
				else
					cout << "\n������ ������� � ����������� ������";
				break;
			case 3:	//��������� ������� �������������� � �������� ��� � ����� �������
				s = arithmetic_mean(s);
				break;
			case 4:	//������� �������� �� ��������� ��������� �� ������
				cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				cin >> start >> finish;
				s = delete_elem(s, start, finish);
				break;
				//case 5:	//������� �������� �� ��������� ��������� �� ��������
				//	cout << "\n������� � ������ �� ����� ������� ����� �������: ";
				//	cin >> start >> finish;
				//	cout << "\n������� �������� ��������� ���������: ";
				//	cin >> k;
				//	l = delete_elem(l, start, finish, k);
				//	break;
			case 6:	//�������� �� ���� ��������� ����� ������������ � ������������� ��������
				s = sum_min_max(s);
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
