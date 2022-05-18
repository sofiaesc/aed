#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

/// suma de todos los elementos de un árbol:
	// recursiva:
typedef tree<int>::iterator node_t;
int suma(tree<int> &T, node_t n){
	if(n == T.end()) return 0;
	auto c = n.lchild();
	int sum = *n;
	while(c != T.end()){
		sum += suma(T,c);
		c++;
	}
	return sum;
}

	// wrapper: 
int suma(tree<int> &T){
	if(T.begin() == T.end()) return 0;
	return suma(T,T.begin());
}
	
/// contar los nodos pares de un árbol:
	// recursiva:
int pares(tree<int> &T, node_t n){
	if(n == T.end()) return 0;
	int count = (*n%2 == 0? 1 : 0);
	auto c = n.lchild();
	while(c != T.end()) count += pares(T,c++);
	return count;
}

int pares(tree<int> &T){
	return pares(T,T.begin());
}

/// suma pares:
int suma_pares(tree<int> &T, node_t n){
	if(n == T.end()) return 0;
	int suma = (*n%2 == 0? *n : 0); // operador ternario "hook operator"
	auto c = n.lchild();
	while(c != T.end()) suma += suma_pares(T,c++);
	return suma;
}
	
int suma_pares(tree<int> &T){
	if(T.begin() == T.end()) return 0;
	return suma_pares(T,T.begin());
}
	
/// find preorder:
node_t find(tree<int> &T, node_t n, int x){
	if(*n == x) return n;
	auto c = n.lchild();
	while(c != T.end()){
		node_t z = find(T,c,x);
		if(z != T.end()) return z;
		c++;
	}
	return T.end();
}

node_t find(tree<int> &T, int x){
	if(T.begin() == T.end()) return T.end();
	return find(T,T.begin(),x);
}
	
/// find postorder:
node_t find_post(tree<int> &T, node_t n, int x){
	auto c = n.lchild();
	while(c != T.end()){
		node_t z = find_post(T,c,x);
		if(z != T.end()) return z;
		c++;
	}
	if(*n == x) return n;
	return T.end();
}
node_t find_post(tree<int> &T, int x){
	if(T.begin() == T.end()) return T.end();
	return find_post(T,T.begin(),x);
}

/// count level:
int count_level(tree<int> &T, node_t n, int level){
	if(level < 0 || n == T.end()) return 0;
	if(level == 0) return 1;
	int count = 0;
	auto c = n.lchild();
	while(c != T.end()){
		count += count_level(T,c,level-1);
		c++;
	}
	return count;
}
	
int count_level(tree<int> &T, int level){
	if(T.begin() == T.end()) return 0;
	return count_level(T, T.begin(),level);
}
	
/// GET_PATH
void get_path(tree<int> &T, tree<int>::iterator n, int x, list<int> &L){
	if (n == T.end()) return;
	if (*n==x){
		L.push_back(x);
		return;
	}
	auto c = n.lchild();
	while(c != T.end()){
		get_path(T,c,x,L);
		if(!L.empty()){
			L.push_back(*n);
			return;
		}
		c++;
	}
}

void get_path(tree<int> &T, int x, list<int> &L){
	if(T.begin() == T.end()) return;
	return get_path(T,T.begin(),x,L);
}

/// CLASSIFY_RELATIVE
void classify_relative(tree<int> &T, int n1, int n2, int &m1, int &m2){
	list<int> L1, L2;
	get_path(T,n1,L1);
	get_path(T,n2,L2);
	
	int cont1 = 0, cont2 = 0;
	if(L1.size() <= L2.size()){
		auto it1 = L1.begin();
		while(it1 != L1.end()){
			auto it2 = L2.begin();
			cont2 = 0;
			while(it2 != L2.end()){
				if(*it1 == *it2){
					m1=cont1;
					m2=cont2;
					return;
				}
				++cont2;
				++it2;
			}
			++cont1;
			++it1;
		}
	} else {
		auto it2 = L2.begin();
		while(it2 != L2.end()){
			auto it1 = L1.begin();
			cont1 = 0;
			while(it1 != L1.end()){
				if(*it1 == *it2){
					m1=cont1;
					m2=cont2;
					return;
				}
				++cont1;
				++it1;
			}
			++cont2;
			++it2;
		}
	}
	
}
/// MAKE_MIRROR
	
void make_mirror(tree<int> &T, node_t n){
	if(n == T.end()) return;
	tree<int> Q;
	node_t q = Q.insert(Q.begin(), 324);
	auto c = n.lchild();
	auto qc = q.lchild();
	
	while(c != T.end()){
		qc = Q.splice(qc,c); // el splice aumenta el c sólo, no hace falta c++.
		// el qc queda en el subarbol que acabo de insertar.
		qc++;
	}
	
	c = n.lchild();
	qc = q.lchild();
	while(qc != T.end()){
		c = T.splice(c,qc); //no anda por la clase implementada, tiene un back.
		make_mirror(T,c);
	}
}
	
void make_mirror(tree<int> &T){
	if(T.begin() == T.end()) return;
	make_mirror(T,T.begin());
}
	
	
	
int main() {
	tree<int> T;
	lisp2tree("(0 3 (8 3) (9 3) (2 (2 3 1))(4 (8 7) 7))", T);
	/* sólo la recursiva, sin wrapper*/ cout<<suma(T,T.begin())<<endl;
	/* con wrapper*/ cout<<suma(T,T.begin())<<endl;
	
	cout<<pares(T)<<endl;
	cout<<suma_pares(T)<<endl;
	
	node_t z = find(T,4);
	cout<<*z<<endl;
	
	cout<<count_level(T,2)<<endl;
	
	list<int> L;
	get_path(T,1,L);
	
	for(auto it = L.begin(); it != L.end(); it++){
		cout<<*it<<" "; 
	}
	cout<<endl;
	int m1 = 0,m2 = 0;
	classify_relative(T,9,8,m1,m2);
	cout<<m1<<" "<<m2;
	
	return 0;
}







