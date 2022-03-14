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
		return ((x == m.x) && (y == m.y) & (z == m.z));
	}

	bool operator>(const TMonom& m)
	{
		if (x > m.x) {
			return true;
		}
		else if (y > m.y) {
			return true;
		}
		else if (z > m.z) {
			return true;
		}
		else return false;
	}

	bool operator<(const TMonom& m)
	{
		if (x < m.x) {
			return true;
		}
		else if (y < m.y) {
			return true;
		}
		else if (z < m.z) {
			return true;
		}
		else return false;
	}

	friend ostream& operator<<(ostream& os, const TMonom& m)
	{
		os << m.coef << "*x^" << m.x << "*y^" << m.y << "*z^" << m.z << " ";
		return os;
	}

	friend istream& operator>>(istream& is, TMonom& m)
	{
		cout << "Введите коэффициент\n";
		is >> m.coef;
		cout << "Введите степени x, y, z \n";
		is >> m.x >> m.y >> m.z;
		return is;
	}
};