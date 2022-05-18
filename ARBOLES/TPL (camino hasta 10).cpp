#include <iostream>
#include <tree.hpp>
#include <list>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void d10s(tree<int> &T, tree<int>::iterator p,list<int> &L){
	if (p == T.end()) return;
	if (*p==10){
		L.push_back(10);
		return;
	}
	auto c = p.lchild();
	while(c != T.end()){
		d10s(T,c,L);
		if(!L.empty()){
			L.push_back(*p);
			return;
		}
		c++;
	}
}

list<int> d10s(tree<int> &T){
	list<int> L;
	
	if(T.begin() == T.end()) return L;
	d10s(T,T.begin(),L);
	list<int> L2;
	for(auto it = L.begin(); it != L.end(); it++){
		L2.push_front(*it);
	}
	return L2;
}
	
	void print_list(const list<int> &L){
		list<int>::const_iterator itB = L.cbegin();
		cout <<"[ ";
		while(itB != L.cend()){
			cout << *itB << " ";
			++itB;
		}
		cout <<"]"<<endl;
	}

int main() {
	tree<int> T;
	lisp2tree("(1 (3 4 (5 10)) 2)",T);
	list<int> L = d10s(T);
	
	print_list(L);
	
	return 0;
}







