#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

bool func_prof(int x){
	return x==0;
}

int count_level(btree<int> &A, btree<int>::iterator itA, bool(*f)(int),int prof){
	if(itA == A.end()) return 0;
	return (f(prof) + count_level(A,itA.left(),f,prof-1) + count_level(A,itA.right(),f,prof-1));
	//profundidad o mayor:
	// return ((prof <= 0) + count_level(A,itA.left(),prof-1) + count_level(A,itA.right(),prof-1));
	
	//profundidad dada:
	//if(prof == 0) return 1;
	//return (count_level(A,itA.left(),prof-1) + count_level(A,itA.right(),prof-1));
	
	/// CON PROGRAMACIÓN FUNCIONAL:
}

int count_level(btree<int> &A,bool(*f)(int),int prof){
	if(A.begin() == A.end()) return 0;
	return count_level(A,A.begin(),f,prof);
}

void cant_nodos_prof(btree<int> &A, btree<int>::iterator itA, int prof, int n, int &count){
	if(itA == A.end()) return;
	if(n >= prof) ++count;
	
	cant_nodos_prof(A,itA.left(),prof,++n,count);
	cant_nodos_prof(A,itA.right(),prof,++n,count);
	
}
	
int cant_nodos_prof(btree<int> &A, int prof){
	if(A.begin() == A.end()) return 0;
	
	int count = 0;
	cant_nodos_prof(A,A.begin(),prof,0,count);
	return count;
}
	
int main() {
	btree<int> T1;
	lisp2btree("(1 (2 4 .) (6 (7 . 5) .))",T1);
	cout<<count_level(T1,func_prof,1)<<endl;
	cout<<cant_nodos_prof(T1,1);
	return 0;
}







