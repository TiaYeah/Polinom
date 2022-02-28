#pragma once

#include <iostream>

using namespace std;

struct TMonom
{
	double coef;
	int x, y, z;

	TMonom(double _coef = 0, int _x = -1, int _y = 0, int _z = 0)
	{
		coef = _coef;
		x = _x;
		y = _y;
		z = _z;
	}

	bool operator==(const TMonom& m)
	{
		return ((x = m.x) && (y = m.y) & (z = m.z));
	}

	bool operator>(const TMonom& m)
	{
		if (*this == m) {
			return(coef > m.coef);
		}
		else throw("������ ��������");
	}

	friend ostream& operator<<(ostream& os, const TMonom& m)
	{
		os << m.coef << "x^" << m.x << "y^" << m.y << "z^" << m.z << "\n";
		return os;
	}

	friend istream& operator>>(istream& is, TMonom m)
	{
		cout << "������� �����������\n";
		is >> m.coef;
		cout << "������� ������� x, y, z \n";
		is >> m.x >> m.y >> m.z;
		return is;
	}
};