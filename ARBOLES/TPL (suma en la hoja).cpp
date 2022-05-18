#include <iostream>
#include <tree.hpp>
#include <list>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void suma_en_la_hoja(tree<int> &T, tree<int>::iterator p, int suma){
	if(p == T.end()) return;
	
	suma += *p;
	auto c = p.lchild();
	if(c == T.end()){
		T.insert(c,suma);
		return;
	}
	while(c != T.end()){
		suma_en_la_hoja(T,c,suma);
		++c;
	} 
}

void suma_en_la_hoja(tree<int> &T){
	if(T.begin() == T.end()) return;
	int suma = 0;
	suma_en_la_hoja(T,T.begin(),suma);
}
	template<typename T>
		void prefijo(tree<T> &arbol,typename tree<T>::iterator p,list<T> &L){
		if (p == arbol.end()) return;
		L.push_back(*p);
		typename tree<T>::iterator c = p.lchild();
		while (c != arbol.end()) prefijo(arbol,c++,L);
	}
		template<typename T>
			list<T> prefijo(tree<T> &arbol){
			list<T> pref;
			prefijo(arbol,arbol.begin(),pref);
			return pref;
		}
		void show_list(list<int> L) {
			cout<<"( ";
			for(auto i:L) {
				cout<<i<<" ";
			}
			cout<<")"<<endl;
		}
	
int main() {
	tree<int> T;
	lisp2tree("(5 (2 1 3) 7)", T);
	suma_en_la_hoja(T);
	list<int> L = prefijo(T);
	show_list(L);
	return 0;
}







