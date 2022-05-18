#include <iostream>
#include <btree.hpp>
#include <tree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void bin2ord(btree<int> &B, btree<int>::iterator itB, tree<int> &T, tree<int>::iterator itT){
	auto lc = itB.left(), rc = itB.right();
	auto c = itT.lchild();
	
	if(lc == B.end() && rc == B.end()) return;
	if(lc != B.end()){
		c = T.insert(c,*lc);
		bin2ord(B,lc,T,c);
	} else {
		c = T.insert(c,-1);
	}
	
	++c;
	
	if(rc != B.end()){
		c = T.insert(c,*rc);
		bin2ord(B,rc,T,c);
	} else {
		c = T.insert(c,-1);
	}
}
	
	void bin2ord(btree<int> &B, tree<int> &T){
		if(B.begin() == B.end()) return;
		T.clear();
		T.insert(T.begin(),*B.begin()); 
		bin2ord(B,B.begin(),T,T.begin());
	}

void ord2bin(tree<int> &T, tree<int>::iterator itT, btree<int> &B, btree<int>::iterator itB){
	auto c = itT.lchild();
	if(c == T.end()) return;
	
	if(*c != -1){
		auto itL = itB.left();
		itL = B.insert(itL,*c);
		ord2bin(T,c,B,itL);
	}
	++c;
	if(*c != -1){
		auto itR = itB.right();
		itR = B.insert(itR,*c);
		ord2bin(T,c,B,itR);
	}
}
	
void ord2bin(tree<int> &T, btree<int> &B){
	B.clear();
	if(T.begin() == T.end()) return;
	B.insert(B.begin(),*(T.begin()));
	
	ord2bin(T,T.begin(),B,B.begin());
}
	
int main() {
	tree<int> T;
	btree<int> B;
	lisp2btree("(1 (2 4 .) (6 (7 . 5) .))",B);
	bin2ord(B,T);
	btree<int> B2;
	ord2bin(T,B2);
	if(B == B2) cout<<"si";
	
	return 0;
}







