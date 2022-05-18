#include <iostream>
#include <tree.hpp>
#include <list>
using namespace aed;
using namespace std;

tree<int>::iterator list2tree(tree<int> &T, tree<int>::iterator itT, list<int> &L,list<int>::iterator itL){
	itT = T.insert(itT, *itL);
	++itL;
	int cantHijos = *itL;
	++itL;
	
	tree<int>::iterator hijoIzq = itT.lchild();
	for(int i = 0; i < cantHijos; i++){
		hijoIzq = list2tree(T,hijoIzq,L,itL);
		hijoIzq++;
	}
	return itT;
}
	
void list2tree(tree<int> &T, list<int> &L){
	list2tree(T,T.begin(),L,L.begin());
}
	
	
void tree2list(tree<int> &T, tree<int>::iterator itT, list<int> &L){
	if(itT == T.end()) return;
	L.push_back(*itT);
	tree<int>::iterator c = itT.lchild();
	int n = 0;
	while(c != T.end()){
		++n;
	}
	L.push_back(n);
	
	tree<int>::iterator d = itT.lchild();
	while(d != T.end()){
		tree2list(T,d++,L);
	}
}

void tree2list(tree<int> &T, list<int> &L){
	tree2list(T,T.begin(),L);
}

int main() {
	
	return 0;
}







