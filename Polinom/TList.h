#pragma once
#include <cstddef>

template <class T>
struct TNode
{
	T Value;
	TNode* pNext;
	TNode(T val, TNode* p = NULL)
	{
		Value = val;
		pNext = p;
	}
};


template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pCur, * pPrev, * pStop;
	int len;
public:
	TList()
	{
		pFirst = pLast = pCur = pPrev = pStop = NULL;
		len = 0;
	}
	~TListQueue()
	{
		TNode<T>* temp = pFirst;
		while (temp != NULL)
		{
			TNode<T>* temp1 = temp;
			temp = temp->pNext;
			delete temp1;
		}
	}
	T getCurrValue()
	{
		if (pCur != pStop)
			return pCur->Value;
		else
			throw ("Список пустой");
	}
	void setCurrValue(const T& val)
	{
		pCur->Value = val;
	}
	void insFirst(const T& el)
	{
		TNode<T>* newFirst = new TNode<T>(el);
		newFirst->pNext = pFirst;
		pFirst = newFirst;
		len++;
		if (len == 1)
		{
			pLast = newFirst;
		}
	}

	bool isEmpty()
	{
		if (len == 0)
			return true;
		else return false;
	}
	void insLast(const T& el)
	{
		TNode<T>* newLast = new TNode<T>(el);
		newLast->pNext = pStop;
		if (pLast != pStop)
		{
			pLast->pNext = newLast;
		}
		else
		{
			pFirst = newLast;
			pLast = newLast;
		}
		len++;
	}

	void insCurrent(TNode<T>* cur, T el)
	{
		TNode<T>* newEl = new TNode<T>;
		newEl->Value = el;
		newEl->pNext = cur->pNext;
		cur->pNext = newEl;
	}

	void delFirst()
	{
		if (pFirst != NULL)
		{
			TNode<T>* FirstEl = pFirst;
			pFirst = pFirst->pNext;
			delete FirstEl;
		}
	}

	void delLast()
	{
		TNode<T>* cur = pFirst;
		TNode<T>* prev = pFirst;
		while (cur->pNext != NULL)
		{
			prev = cur;
			cur = cur->pNext;
		}
		prev->pNext = NULL;
		delete cur;
	}
	int ListLength(TNode<T>* first)
	{
		TNode<T>* cur = first;
		int len = 0;
		while (cur != NULL)
		{
			len++;
			cur = cur->pNext;
		}
		return len;
	}

};
