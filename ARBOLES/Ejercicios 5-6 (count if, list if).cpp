#include <iostream>
#include <tree.hpp>
using namespace aed;
using namespace std;

bool odd(int x){
	if(x%2 != 0) return true;
	return false;
}
	
void count_if(tree<int> &T, tree<int>::iterator p, bool (*pred)(int x), int n){
	if(p == T.end()) return;
	if(pred(*p)) ++n;
	tree<int>::iterator c = p.lchild();
	while(c != T.end()) count_if(T,c++,pred,n);
}
int count_if(tree<int> &T, bool (*pred)(int x)){
	int n = 0;
	if(T.begin() == T.end()) return n;
	count_if(T,T.begin(),(*pred),n);
	return n;
}
	
void list_if(tree<int> &T, tree<int>::iterator p, list<int> &L, bool (*pred)(int x)){
	if(p == T.end()) return;
	if(pred(*p)) L.push_back(*p);
	tree<int>::iteartor c = p.lchild();
	while(c != T.end()) list_if(T,c++,L,pred);
}
	
void list_if(tree<int> &T, list<int> &L, bool (*pred)(int x)){
	L.clear();
	if(T.begin() == T.end()) return;
	list_if(T,T.begin(),L,pred);
}
	

int main() {
	
	return 0;
}







