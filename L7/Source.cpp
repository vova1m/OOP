#include "List.h"
#include "Pair.h"

int main()
{
	system("chcp 1251 >> null");

	List<int> a, b, c;

	for (int i = 0; i < 5; i++)
	{
		a.push_back(i + 2);
	}

	for (int i = 0; i < 4; i++)
	{
		b.push_back(i - 1);
	}

	cout << "���� �:\n";
	a.show_list();

	cout << "\n���� b:\n";
	b.show_list();

	cout << "\n���� � = a*b :\n";
	c = a * b;
	c.show_list();
	cout << "\n������ ����� c: " << c() << endl << endl;
	cout << "\n��������� c[5] = 150" << endl; c[5] = 150;
	cout << "\n���� �:\n";
	c.show_list();

	List<Pair> p;
	Pair x;

	for (int i = 0; i < 3; i++)
	{
		cout << "\n������� ����:\n";
		cin >> x;
		p.push_back(x);
	}

	cout << "\n������ p: ";
	p.show_list();

	return 0;
}
