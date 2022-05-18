#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*Ascendente1. Escribir una funci´on void ascendente1(list<int> &L, list<list<int>> &LL)
que, dada una lista L, genera una lista de listas LL de tal forma de que cada sublista es ascendente.
Esto es, dada la lista L = { 1, 2, 3, 1, 4, 5, 1, 6, 7 } retorno LL = { {1,2,3}, {1,4,5}, {1,6,7}}.
*/

void ascendente1(list<int> &L, list<list<int>> &LL){
	if(L.empty()) return;
	
	auto it = L.begin();
	auto itIni = it;
	it++;
	while(it!=L.end()){
		auto itprev = prev(it);
		if(*it>=*itprev){
			it++;
		}else{
			list<int>sublista(itIni,it);
			LL.push_back(sublista);
			itIni = it;
			it++;
		}
	}
	if(itIni!=it){
		list<int> sublista(itIni,it);
		LL.push_back(sublista);
	}
}

/*Ascendente2. Escribir una funci´on void ascendente2(list<int> &L, vector<list<int>> &VL)
que, dada una lista L, genera un vector de listas VL de tal forma de que cada sublista es ascendente
*/

void ascendente2(list<int> &L, vector<list<int>> &VL){
	if(L.empty()) return;
	
	auto it = L.begin();
	auto itIni = it;
	
	while(it != L.end()){
		auto itprev = prev(it);
		if(*it >= *itprev){
			it++;
		}else{
			list<int> sublista(itIni,it);
			VL.push_back(sublista);
			itIni = it;
			it++;
		}
	}
	if(itIni != it){
		list<int> sublista(itIni, it);
		VL.push_back(sublista);
	}
}

int main() {
	
	return 0;
}







