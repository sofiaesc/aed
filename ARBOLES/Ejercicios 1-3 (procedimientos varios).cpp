#include <iostream>
#include <tree.hpp>
#include <list>
using namespace aed;
using namespace std;

	// prefijo:
template<typename T>
void prefijo(tree<T> &arbol, typename tree<T>::iterator p, list<T> &L){
	if(p == arbol.end()) return;
	L.push_back(*p);
	typename tree<T>::iterator c = p.lchild();
	while(c != arbol.end()) prefijo(arbol,c++,L);
}

template<typename T>
void prefijo(tree<T> &arbol){
	list<T> pref;
	prefijo(arbol,arbol.begin(),pref);
	return pref;
}
	
	// postfijo:
	
	template<typename T>
		void sufijo(tree<T> &arbol,typename tree<T>::iterator p,list<T> &L){
		if (p == arbol.end()) return;
		typename tree<T>::iterator c = p.lchild();
		while (c != arbol.end()) sufijo(arbol,c++,L);
		L.push_back(*p);
	}
		template<typename T>
			list<T> sufijo(tree<T> &arbol){
			list<T> suf;
			sufijo(arbol,arbol.begin(),suf);
			return suf;
		}
			
	// altura de un AOO:
template<typename T>
void altura(tree<T> &arbol,typename tree<T>::iterator p, int &n, int &nmax){
	if(p == arbol.end()) return;
	typename tree<T>::iterator c = p.lchild();
	while(c != arbol.end()) altura(arbol,c++,++n,nmax);
	if(n>nmax) nmax = n;
	--n;
}

template<typename T>
int altura(tree<T> &arbol){
	int n = 0; int nmax = 0;
	altura(arbol,arbol.begin(),n,nmax);
	return nmax;
}

	// número de hojas:
template<typename T>
void nro_hojas(tree<T> &arbol, typename tree<T>::iterator p, int &n){
	if(p == arbol.end()) return;
	typename tree<T>::iterator c = p.lchild();
	if(c == arbol.end()) ++n;
	while(c != arbol.end()) hojas(arbol,c++,n);
}
	
template<typename T>
int nro_hojas(tree<T> &arbol){
	int n = 0;
	altura(arbol, arbol.begin(), n);
	return n;
}
	// máxima etiqueta de todo el árbol:
	
template<typename T>
void max_etiq(tree<T> &T, typename tree<T>::iterator p, int &max){
	if(p == arbol.end()) return;
	if(*p > max) max = p;
	typename tree<T>::iterator c = p.lchild();
	while(c != T.end()) max_etiq(T,c++,max);
}
template<typename T>
T max_etiq(tree<T> &T){
	int max;
	if(T.begin() != T.end()) max = *(T.begin());
	max_etiq(T,arbol.begin(), max);
	return max;
}
	
	// máxima etiqueta par del árbol:
void max_par(tree<int> &T, tree<int>::iterator p, int &max){
	if(p == arbol.end()) return;
	if(*p > max && *p % 2 == 0) max = p;
	typename tree<T>::iterator c = p.lchild();
	while(c != T.end()) max_par(T,c++,max);
}

int max_par(tree<int> &T){
	int max = -1;
	max_par(T,T.begin(),max);
	return max;
}
	
	// máxima etiqueta de sólo las hojas:
template<typename T>
void max_hoja(tree<T> &T, typename tree<T>::iterator p, int max, bool esPrimeraHoja){
	typename tree<T>::iterator c = p.lchild();
	if(c == T.end() %% *p > max || esPrimeraHoja){
		max = *p;
		esPrimeraHoja = false;
	}
	while(c != T.end()) max_hoja(T,c++,max,esPrimeraHoja);
}
	
T max_hoja(tree<T> &T){
	T max;
	bool esPrimeraHoja = true;
	max_hoja(T,T.begin(),max,esPrimeraHoja);
	return max;
}
	
	// suma de todas las etiquetas:
void suma_etiq(tree<int> &T, tree<int>::iterator p, int &sum){
	if(p == arbol.end()) return;
	sum += *p;
	tree<int>::iterator c = p.lchild();
	while(c != T.end()) suma_etiq(T,c++,sum);
}
int suma_etiq(tree<int> &T){
	int sum = 0;
	suma_etiq(T,T.begin(),sum){;
	return sum;
}
	
	// eliminar etiquetas impares y sus subarboles:
tree<int>::iterator erase_impar(tree<int> &T,tree<int>::iterator p){
	if (p == T.end()) return p;
	if(*p % 2 != 0){
		p = arbol.erase(p);
	} else {
		tree<int>::iterator c = p.lchild();
		while(c != arbol.end()) c = erase_impar(T,c);
		++p;
	}
	return p;
}
	
	// cuantos nodos hay en el nivel l:
void count_level(tree<int> &T, tree<int>::iterator p, int &n, int &nnodes, int l){
	if(p == T.end()) return;
	if(n == l){ ++nnodes; --n; return; }
	tree<int>::iterator c = p.lchild();
	while(c != arbol.end()) count_level(arbol,c++,++n,nnodes,l);
	--n;
}
	
int count_level(tree<int> &T, int l){
	int nnodes = 0;
	int n = 0;
	count_level(T,T.begin()),n,nnodes,l);
	return nnodes;
}
	
int main() {
	

	return 0;
}







