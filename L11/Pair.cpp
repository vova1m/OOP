#include "Pair.h"
#include <iostream>
using namespace std;

//���������� �������� ������������
Pair& Pair::operator = (const Pair& p)
{
	//�������� �� ����������������
	if (&p == this)
		return *this;
	else
		first = p.first;
	second = p.second;
	return *this;
}
//���������� �������� ��������
Pair Pair::operator+(const Pair& p) const
{
	Pair temp(this->first + p.first, this->second + p.second);
	return temp;
}
//���������� ����������
Pair& Pair::operator++()
{
	++this->first;
	++this->second;
	return *this;
}

Pair Pair::operator++(int)
{
	Pair temp(*this);
	++this->first;
	++this->second;
	return temp;
}
//���������� �������� ���������
Pair Pair::operator-(const Pair& p)
{
	return Pair(this->first - p.first, this->second - p.second);
}

const Pair operator+(const Pair& left, const int& right)
{
	return Pair(left.first + right, left.second);
}

const Pair operator+(const int& left, const Pair& right)
{
	return right + left;
}

const Pair operator+(const Pair& left, const double& right)
{
	return Pair(left.first, left.second + right);
}

const Pair operator+(const double& left, const Pair& right)
{
	return right + left;
}
//���������� �������� �������
Pair Pair::operator/(const Pair& p)
{
	return Pair(this->first / p.first, this->second / p.second);
}

Pair Pair::operator/(const int p)
{
	return Pair(this->first / p, this->second / p);
}
//���������� �������� �����������
bool Pair::operator<(const Pair& p) const
{
	double thiss = this->first + this->second, otherr = p.first + p.second;
	if (thiss < otherr) return true;
	else return false;
}

bool Pair::operator>(const Pair& p)
{
	return !(*this < p);
}

//���������� ���������� �������-�������� �����
istream& operator >> (istream& in, Pair& p)
{
	cout << "\n������ �����: ";
	in >> p.first;
	cout << "\n������ �����: ";
	in >> p.second;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator << (ostream& out, const Pair& p)
{
	return (out << p.first << " : " << p.second);
}
