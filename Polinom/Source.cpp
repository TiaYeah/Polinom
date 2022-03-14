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
	THeadList<int> headList;
	TMonom mon;
	TPolinom polinom, polinom2;




	for (int i = 1; i < 3; i++) {
		//list.insFirst(i);
		cin >> mon;
		polinom.addMonom(mon);
		//headList.insFirst(i);
	}
	for (int i = 1; i < 3; i++) {
		//list.insFirst(i);
		//cin >> mon;
		//polinom2.addMonom(mon);
		//headList.insFirst(i);
	}
	//TList<int> listCopy(list);
	for (int i = 0; i < 3; i++)
	{
		//list.goNext();
	}
	
	for (int i = 0;  i < 6; i++){
		//list.insLast(i);
		//headList.insLast(i);
	}

	//list.goNext();
	//headList.goNext();

	//list.goNext();
	//headList.goNext();
	for (int i = 0; i < 3; i++)
	{
	//	list.insCurrent(8);
		//headList.insCurrent(8);
	}
	//cout << list;
	//cout << headList;
	//list.goNext();
	//headList.goNext();
	//headList.goNext();
	for (int i = 0; i < 3; i++) {
		//list.delCurr();
		//headList.delCurr();
	}
	//list.insCurrent(11);
	//list.delFirst();
	//list.delFirst();
	TPolinom res;
	cout << polinom;
	res = polinom * 2;
	cout << res;
	//cout << list;
	//cout << headList;
}