#include <iostream>
#include <set>
#include <list>
using namespace std;

void show_set(set<int> A) {
	cout<<"{ ";
	for(auto i:A) {
		cout<<i<<" ";
	}
	cout<<"}"<<endl;
}

void congrClasses(set<int> &S, int m, list<set<int>> &L){
	set<int>::iterator itS = S.begin();
	L.clear();
	L.resize(m);
	set<int> aux;
	while(itS != S.end()){
		int r = *itS % m;
		list<set<int>>::iterator itL = L.begin();
		advance(itL,r);
		(*itL).insert(*itS);
		++itS;
	}
}

int main() {
	set<int> S = {1, 2, 3, 4, 5, 6, 7};
	list<set<int>> L;
	congrClasses(S,3,L);
	
	list<set<int>>::iterator it = L.begin();
	while(it != L.end()){
		show_set(*it);
		++it;
	}
	
	return 0;
}







