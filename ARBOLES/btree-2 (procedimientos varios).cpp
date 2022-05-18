#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

bool same_structure(btree<int> &A, btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB){
	bool valorIzq, valorDer;
	
	if((itA == A.end()) xor (itB == B.end())){
		return false;
 	} else {
		if(itA == A.end()){
			return true;
		} else {
			valorIzq = same_structure(A, itA.left(), B, itB.left());
			valorDer = same_structure(A, itA.right(), B, itB.right());
			return (valorIzq && valorDer);
		}
	} 
}

bool same_structure(btree<int> &A, btree<int> &B){
	return same_structure(A,A.begin(),B,B.begin());
}

bool espejado(btree<int> &A, btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB){
	bool valorIzq, valorDer;
	
	if((itA == A.end()) xor (itB == B.end())){
		return false;
	} else {
		if(itA == A.end()){
			return true;
		} else {
			valorIzq = same_structure(A, itA.left(), B, itB.right());
			valorDer = same_structure(A, itA.right(), B, itB.left());
			return (valorIzq && valorDer);
		}
	}
}

bool espejado(btree<int> &A, btree<int> &B){
	return espejado(A,A.begin(),B,B.begin());
}

bool iguales(btree<int> &A, btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB){
	bool valorIzq, valorDer;
	
	if((itA == A.end()) xor (itB == B.end())){
		return false;
	} else {
		if(itA == A.end()){
			return true;
		} else {
			if(*itA != *itB){
				return false; 
			} else {
			valorIzq = iguales(A, itA.left(), B, itB.left());
			valorDer = iguales(A, itA.right(), B, itB.right());
			return (valorIzq && valorDer);
		}
	} 
	}
}
	
bool iguales(btree<int> &A, btree<int> &B){
	return iguales(A,A.begin(),B,B.begin());
}
	
	// versión in-place:
	
void copia_espejada(btree<int> &A, btree<int>::iterator itA){
	btree<int> T;
	if(itA == A.end()){
		return;
	} else {
		T.splice(T.begin(), itA.left());
		A.splice(itA.left(), itA.right());
		A.splice(itA.right(), T.begin());
		copia_espejada(A, itA.left());
		copia_espejada(A, itA.right());
	}
}
	
void copia_espejada(btree<int> &A){
	copia_espejada(A,A.begin());
}
	
	// versión con árbol que se le pasa como argumento:

void copia_espejada(btree<int> &A, btree<int>::iterator itA,btree<int> &B, btree<int>::iterator itB){
	
	if(itA.left() != A.end()){
		B.insert(itB.right(), *(itA.left()));
		copia_espejada(A,itA.left(),B,itB.right());
	}
	
	if(itA.right() != A.end()){
		B.insert(itB.left(), *(itA.right()));
		copia_espejada(A,itA.right(),B,itB.left());
	}
}
	
void copia_espejada(btree<int> &A,btree<int> &B){
	B.clear();
	if(A.begin() == A.end()) return;
	B.insert(B.begin(),*(A.begin()));
	
	copia_espejada(A,A.begin(),B,B.begin());
}	

int main() {
	btree<int> T;
	lisp2btree("(1 (2 4 .) (6 (7 . 5) .))",T);
	btree<int> T2, T3;
	copia_espejada(T,T2);
	copia_espejada(T2,T3);
	if(T == T3) cout<<"si";
	
	return 0;
}







