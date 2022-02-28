#include<iostream>
#include<locale>
#include "TList.h"
#include "THeadList.h"
#include "Monom.h"
#include "TPolinom.h"

using namespace std;

void main() {
	setlocale(LC_ALL, "Russian");
	TList<int> list;
	//THeadList<int> headList;
	TMonom mon;
	TPolinom polinom;



	for (int i = 1; i < 3; i++) {
		list.insFirst(i);
		cin >> mon;
		polinom.addMonom(mon);
		//headList.insFirst(i);
	}
	//TList<int> listCopy(list);
	for (int i = 0; i < 3; i++)
	{
		//list.goNext();
	}
	for (int i = 0;  i < 5; i++){
		//list.delCurr();
		//list.insLast(i);
	}
	//list.insCurrent(11);
	//list.delFirst();
	//list.delFirst();
	//cout << list;
	//cout << headList;
	//cout << listCopy;
}