#pragma once

#include <iostream>

using namespace std;

struct TMonom
{
	double coef;
	int x, y, z;

	TMonom(double _coef = 0, int _x = -1, int _y = 0, int _z = 0)
	{
		if (_x >= 10 || _x < -1 || _y >= 10 || _y < 0 || _z >= 10 || _z < 0)
		{
			throw("Выход за границу степени");
		}
		else {
			coef = _coef;
			x = _x;
			y = _y;
			z = _z;
		}
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
		int inputx, inputy, inputz;
		cout << "Введите коэффициент\n";
		is >> m.coef;
		cout << "Введите степени x, y, z \n";
		is >> inputx >> inputy >> inputz;

		if (inputx >= 10 || inputx < 0 || inputy >= 10 || inputy < 0 || inputz >= 10 || inputz < 0)
		{
			throw("Выход за границу степени");
		}
		else {
			m.x = inputx;
			m.y = inputy;
			m.z = inputz;
		}

		return is;
	}
};