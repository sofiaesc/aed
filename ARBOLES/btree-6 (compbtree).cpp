#include <iostream>
using namespace std;

bool es_menor(btree<int> &A, btree<int>::iterator itA, btree<int> &B, btree<int>::iterator itB){
	if(itA == A.end() && itB == B.end()) return false;
	
	if(itA == A.end()) return true;
	if(itB == B.end()) return false;
	
	if(*itA < *itB) return true;
	if(*itB < *itA) return false;
	
	if(es_menor(A, itA.left(), B, itB.left())) return true;
	if(es_menor(B, itB.left(), A, itA.left())) return false;
	
	return es_menor(A, itA.right, B, itB.right());
}

bool es_menor(btree<int> &A, btree<int> &B){
	return es_menor(A, A.begin(), B, B.begin());
}

int main() {
	
	return 0;
}







