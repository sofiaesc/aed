#include <iostream>
#include <map>
#include <tree.hpp>
#include <list>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void prom_nivel(tree<int> &T, tree<int>::iterator p, map<int,int> &suma, map<int,int> &nodos, int n){
	if(p == T.end()) return;

	tree<int>::iterator c = p.lchild();
	
	
	map<int,int>::iterator it2;
	
	while(c != T.end()){
		nodos[n]++;
		suma[n] += *c;
		
		prom_nivel(T,c,suma,nodos,n+1);
		
		it2 = suma.find(n);
		it2->second += *c;
		
		it2 = nodos.find(n);
		it2->second = it2->second + 1;
		
		++c;
	}
}

void prom_nivel(tree<int> &T, list<float> &P){
	P.clear();
	if(T.begin() == T.end()) return;
	
	int n = 1;
	map<int,int> suma, nodos;
	suma[0] = *(T.begin());
	nodos[0] = 1;
	
	prom_nivel(T,T.begin(),suma,nodos,n);
	
	for(int i=0; i<suma.size(); i++){
		P.push_back(float(suma[i]) / nodos[i]);
	}
	
	for(auto it=P.begin();it!=P.end();it++) { 
		cout<<*it<<" ";
	}
}


int main() {
	tree<int> T;
	lisp2tree("(5 (10 8 9) (7 3))", T);
	list<float> L;
	prom_nivel(T,L);
	
	
	return 0;
}







