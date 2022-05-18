#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void evpath(tree<int> &T, tree<int>::iterator p, int n, int &nmax){
	if(p == T.end()){
		--n;
		return;
	}
	if(*p % 2 != 0) return;
	
	auto c = p.lchild();
	while(c != T.end()) evpath(T,c++,n++,nmax);
	if(n > nmax) nmax = n;
	--n;
	
}

int evpath(tree<int> &T){
	if(T.begin() == T.end()) return 0;
	int n = -1, nmax = 0;
	evpath(T,T.begin(),n,nmax);
	return nmax;
}

int main() {
	tree<int> T;
	lisp2tree("(0 (1 2 3) (2 (4 5 7) 3))",T);
	int x = evpath(T);
	cout<<x;
	return 0;
}







