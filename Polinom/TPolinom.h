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
		}
		if (m > pLast->Value) {
			if (isEnd()) { insLast(m); }
		}
	}
};

