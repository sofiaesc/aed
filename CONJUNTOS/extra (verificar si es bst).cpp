#include <iostream>
using namespace std;

int max(btree<int> &T, btree<int>::iterator n){
	if(n == T.end()) return INT_MIN;
	auto c = n;
	while(c != T.end()){
		auto cc = c.right();
		if(cc = T.end()) break;
		c = cc;
	}
	return *c;
}
	
int max(btree<int> &T, btree<int>::iterator n){
	if(T.begin() == T.end()) return INT_MIN;
	return max(T,T.begin());
}
	
int min(btree<int> &T, btree<int>::iterator n){
	if(n == T.end()) return INT_MAX;
	auto c = n;
	while(c != T.end()){
		auto cc = c.left();
		if(cc = T.end()) break;
		c = cc;
	}
	return *c;
}
	
int min(btree<int> &T, btree<int>::iterator n){
	if(T.begin() == T.end()) return INT_MAX;
	return max(T,T.begin());
}

bool isbst(btree<int> &T, btree<int>::iterator n){
	if(n == T.end()) return true;
	if(!isbst(T,n.left()) return false;
	if(!isbst(T,n.right()) return false;
	if(*n <= max(T,n.left())) return false;
	if(*n >= min(T,n.right())) return false;
	return true;
}

bool isbst(btree<int> &T){
	if(T.begin() == T.end()) return true;
	isbst(T,T.begin());
}

int main() {
	
	return 0;
}







