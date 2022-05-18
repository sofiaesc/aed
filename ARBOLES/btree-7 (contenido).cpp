#include <iostream>
using namespace std;

bool contenido(btree<int> &A, btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB){
	if(itA == A.end()) return true;
	if(itB == B.end()) return false;
	
	if(*itB < itA) return false;
	
	if(!contenido(A,itA.left(),B,itB.left())) return false;
	if(!contenido(A,itA.right(),B,itB.right())) return false;
	
	return true;
}

bool contenido(btree<int> &A, btree<int> &B){
	return contenido(A, A.begin(), B, B.begin());
}

int main() {
	
	return 0;
}







