#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &L){
	list<int>::const_iterator itB = L.cbegin();
	cout <<"[ ";
	while(itB != L.cend()){
		cout << *itB << " ";
		++itB;
	}
	cout <<"]"<<endl;
}

void compacta(list<int> &L, list<int>&S){
	auto itL = L.begin();
	auto itS = S.begin();
	list<int> L_aux;
	
	while(itS != S.end()){
		int n = *itS;
		int sum = 0;
		
		for(int i = 0; (i < n && itL != L.end()); i++){
			sum+= *itL;
			++itL;
		}
		
		L_aux.push_back(sum);
		++itS;
	}
	
	while(itL != L.end()){
		L_aux.push_back(*itL);
		++itL;
	}
	
	L = L_aux;
}

int main() {
	list<int> L = {1,2,3,4,5,6};
	list<int> S = {1,2,6};
	compacta(L,S);
	print_list(L);
	return 0;
}







