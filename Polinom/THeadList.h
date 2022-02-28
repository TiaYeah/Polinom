#pragma once

#include <cstddef>
#include <iostream>
#include "TList.h"


using namespace std;

template <class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList() 
	{
		pHead = new TNode<T>(NULL);
		/*pCurr = new TNode<T>;
		pFirst = new TNode<T>;
		pPrev = new TNode<T>;
		pLast = new TNode<T>;
		pStop = new TNode<T>;
		pHead = new TNode<T>;*/
		pHead->pNext = pHead;
		pCurr = pPrev = pLast = pFirst = pStop = pHead;
		len = 0;
	}

	~THeadList()
	{
		while (pFirst != pStop) {
			TNode<T>* node = pFirst;
			pFirst = pFirst->pNext;
			delete node;
		}
		delete pHead;
	}

	void insFirst(const T& val)
	{
		TList::insFirst(val);
		pHead->pNext = pFirst;
	}

	void delFirst()
	{
		TList::delFirst();
		pHead->pNext = pFirst;
	}

	friend ostream& operator <<(ostream& os, THeadList headList)
	{
		for (int i = 0; i < headList.getLen(); i++) {
			cout << headList.getCurrValue() << " ";
			headList.goNext();
		}
		return os;
	}
};

