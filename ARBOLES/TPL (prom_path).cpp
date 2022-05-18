#include <iostream>
#include <tree.hpp>
#include <list>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void prom_path(tree<int> &T, tree<int>::iterator p, list<int> &L, int n){
	if(p == T.end()) return;

	++n;
	auto c = p.lchild();
	if(c==T.end()){
		L.push_back(n);
		return;
	}
	
	while(c != T.end()){
		prom_path(T,c,L,n);
		++c;
	}
}

float prom_path(tree<int> &T){
	if(T.begin() == T.end()) return 0;
	int n = -1;
	list<int> L;
	prom_path(T,T.begin(),L,n);
	
	float sum = 0;
	for(auto it = L.begin(); it != L.end(); it++){
		sum += *it;
	}
	float prom = sum/L.size();
	return prom;
}

int main() {
	tree<int> T;
	lisp2tree("(1 (2 3 4 (5 6)) 7 8)", T);
	float i = prom_path(T);
	cout<<i;
	return 0;
}







