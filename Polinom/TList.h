#pragma once

#include <cstddef>
#include <iostream>


using namespace std;

template <class T>
struct TNode
{
	T Value;
	TNode* pNext;	TNode(T val, TNode* _pNext = NULL)
	{
		Value = val;
		pNext = _pNext;
	}
};


template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pCurr, * pPrev, * pStop;
	int len;
public:
	TList()
	{
		pCurr = new TNode<T>(NULL);
		pFirst = new TNode<T>(NULL);
		pPrev = new TNode<T>(NULL);
		pLast = new TNode<T>(NULL);
		pStop = new TNode<T>(NULL);
		pFirst = pLast = pCurr = pPrev = pStop;
		len = 0;
	}
	TList(const TList<T>& list)
	{
		cout << "Конструктор копирования \n";
		TNode<T>* node = list.pFirst;
		TNode<T>* p, * prev = NULL;
		pFirst = NULL;
		while (node ->pNext != list.pStop) {
			p = new TNode<T>(node->Value, NULL);
			if (pFirst == NULL) {
				pFirst = p;
				prev = p;
			}
			else {
				prev->pNext = p;
				prev = pFirst;
			}
			node = node->pNext;
		}
		prev->pNext = node;
		pLast = node;
		pStop = node->pNext;
		pPrev = list.pPrev;
		pCurr = pPrev->pNext;
		len = list.len;
	}


	~TList()
	{
		cout << "Деструктор \n";
		while (pFirst!= pStop)
		{
			TNode<T>* del = pFirst;
		    pFirst = pFirst->pNext;
			delete del;
		}
		delete pFirst;
	}

	int getLen() { return len; }

	T getCurrValue()
	{
		if (pCurr != pStop)
			return pCurr->Value;
		else
			throw ("Список пустой");
	}

	void setCurrValue(const T& value)
	{
		pCurr->Value = value;
	}



	void insFirst(const T& value)
	{
		TNode<T>* newFirst = new TNode<T>(value, pFirst);
		pCurr = newFirst;
		pFirst = newFirst;
		len++;
		if (len == 1)
		{
			pLast = newFirst;
			pLast->pNext = pStop;
		}
	}

	void insCurrent(const T& value)
	{
		if (pCurr == pFirst) {
			insFirst(value);
		}
		else if (pPrev == pLast){
			insLast(value);
		}
		else {
			TNode<T>* node = new TNode<T>(value,pCurr);
			pPrev->pNext = node;
			pCurr = node;
			len++;
		}

	}
	void insLast(const T& value)
	{
		TNode<T>* node = new TNode<T>(value, pStop);
		if (pLast != pStop) {
			pLast->pNext = node;
			pLast = node;
		}
		else {
			pFirst = node;
			pLast = node;
		}
		len++;
	}

	void delFirst()
	{
		if (pFirst != pStop){
			TNode<T>* delNode = pFirst;
			pFirst = pFirst->pNext;
			delete delNode;
			len--;
			if (len == 0) {
				pLast = pStop;
			}
		}
	}
	void delCurr()
	{
		if (pCurr != pStop)
			if (pCurr == pFirst) {
				delFirst();
			} else {
				TNode<T>* delNode = pCurr;
				pCurr = pCurr->pNext;
				pPrev->pNext = pCurr;
				delete delNode;
				len--;
			}
	}

	bool isEmpty()
	{
		return (len == 0);
	}

	void reset()
	{
		pCurr = pFirst;
		pPrev = pStop;
	}

	void goNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}


	bool isEnd()
	{
		return pCurr == pStop;
	}

	friend ostream& operator<<(ostream& os, TList<T> list)
	{
		for (list.reset(); !list.isEnd(); list.goNext())
		{
			//os << list.check();
			os << list.getCurrValue() << " ";
		}
		os << "\n";
		return os;
	}
};
