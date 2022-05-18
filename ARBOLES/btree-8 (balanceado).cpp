#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

bool is_balanced(btree<int> &T, btree<int>::iterator itT, int &n){
	n = -1;
	if(itT == T.end()) return true;
	btree<int>::iterator itL = itT.left();
	btree<int>::iterator itR = itT.right();
	int nL, nR;
	n = INT_MAX;
	if(!is_balanced(T,itL,nL)) return false;
	if(!is_balanced(T,itR,nR)) return false;
	n = (nL > nR ? nL : nR) +1;
	return abs(nL - nR) <= 1;
}

bool is_balanced(btree<int> &T){
	int n;
	return is_balanced(T,T.begin(),n);
}

int main() {
	btree<int> B;
	lisp2btree("(1 (2 4 (5 6 7)) 3)", B);
	if(is_balanced(B)) cout<<"si";
	return 0;
}







