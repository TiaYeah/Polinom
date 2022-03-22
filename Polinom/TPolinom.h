#pragma once
#include <string>
#include "THeadList.h"
#include "Monom.h"


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom()
	{
		TMonom m;
		pHead->Value = m;
	}

	TPolinom(TPolinom& p)
	{
		for (p.reset(); !(p.isEnd()); p.goNext())
		{
			insLast(p.pCurr->Value);
		}
	}

	void addMonom(TMonom& m)
	{
		{
			for (reset(); !isEnd(); goNext()) {
				if (m == pCurr->Value) {
					pCurr->Value.coef += m.coef;
					if (pCurr->Value.coef == 0) {
						delCurr();
					}
					break;
				}
				if (m > pCurr->Value) {
					insCurrent(m);
					break;
				}
			}
			if (isEnd()) {
				insLast(m);
			}
		}
	}

	TPolinom operator*(const int& c)
	{
		TPolinom res(*this);
		res.reset();
		while (!res.isEnd())
		{
			if (c != 0)
			{
				res.pCurr->Value.coef *= c;
				res.goNext();
			}
			else {
				res.delCurr();
			}
		}
		return res;
	}

	TPolinom operator*(const TMonom& m)
	{
		TPolinom res(*this);
		res.reset();
		while (!res.isEnd())
		{
			if (m.coef != 0)
			{
				res.pCurr->Value.coef *= m.coef;
				res.pCurr->Value.x += m.x;
				res.pCurr->Value.y += m.y;
				res.pCurr->Value.z += m.z;
				if (res.pCurr->Value.x >= 10 || res.pCurr->Value.y >= 10 || res.pCurr->Value.z >= 10)
				{
					throw("����� �� ������� �������");
					break;
				}
			}
			else {
				res.delCurr();
			}
			res.goNext();
		}
		return res;
	}

	TPolinom operator*(TPolinom& p)
	{
		TPolinom tmp1(*this);
		TPolinom res;
		p.reset();
		while (!p.isEnd())
		{
			tmp1.reset();
			res = res + tmp1 * p.pCurr->Value;
			p.goNext();
		}
		return res;
	}



	TPolinom& operator=(TPolinom& p)
	{
		p.reset();
		reset();
		while (!isEnd())
		{
			delCurr();
		}
		while (!p.isEnd())
		{
			addMonom(p.getCurrValue());
			p.goNext();
		}
		return *this;
	}

	TPolinom operator+(TPolinom& p)
	{
		TPolinom res(*this);
		p.reset();
		res.reset();
		while (!p.isEnd())
		{
			if (res.pCurr->Value > p.pCurr->Value)
				res.goNext();
			else if (res.pCurr->Value < p.pCurr->Value)
			{
				res.insCurrent(p.pCurr->Value);
				p.goNext();
			}
			else
			{
				res.pCurr->Value.coef += p.pCurr->Value.coef;
				if (res.pCurr->Value.coef != 0)
				{
					res.goNext();
					p.goNext();
				}
				else
				{
					res.delCurr();
					p.goNext();
				}
			}
		}
		return res;
	}

	TPolinom operator-(TPolinom& p)
	{
		TPolinom res(*this);
		p.reset();
		res.reset();
		while (!p.isEnd())
		{
			if (res.pCurr->Value > p.pCurr->Value)
				res.goNext();
			else if (res.pCurr->Value < p.pCurr->Value)
			{
				res.insCurrent(p.pCurr->Value);
				res.pCurr->Value.coef *= -1;
				p.goNext();
			}
			else
			{
				res.pCurr->Value.coef -= p.pCurr->Value.coef;
				if (res.pCurr->Value.coef != 0)
				{
					res.goNext();
					p.goNext();
				}
				else
				{
					res.delCurr();
					p.goNext();
				}
			}
		}
		return res;
	}

	string toString()
	{
		string res = "";
		for (reset(); !isEnd(); goNext()) {
			res += to_string((int)getCurrValue().coef) + "*x^" +  to_string(getCurrValue().x) + "*y^" + to_string(getCurrValue().y) + "*z^" + to_string(getCurrValue().z) + " ";
			if (pCurr->pNext != pStop)
			{
				res += "+ ";
			}
		}
		return res;
	}

	bool operator==(TPolinom& p)
	{
		if (getLen() != p.getLen())
			return false;
		while (!isEnd())
		{
			if (getCurrValue() == p.getCurrValue())
			{
				goNext();
			}
			else return false;
		}
		return true;
	}

	friend ostream& operator<<(ostream& os, TPolinom& p)
	{
		for (p.reset(); !p.isEnd(); p.goNext()) {
			os << p.getCurrValue();
			if (p.pCurr->pNext != p.pStop)
			{
				os << "+ ";
			}
		}
		os << "\n";
		return os;
	}
};

