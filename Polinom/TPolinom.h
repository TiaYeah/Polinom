#pragma once
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

	TPolinom(const TPolinom& pol)
	{

	}

	void addMonom(TMonom m)
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

			if (m > pCurr->Value) {
				insCurrent(m);
				break;
			}
		}
		if (isEnd()) { 
			insLast(m); 
		}
	}
};

