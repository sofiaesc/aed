#include <iostream>
#include <list>
#include <set>
using namespace std;

template <typename T>
void set_union(set<T> &A, set<T> &B, set<T> &C){
	C = A;
	C.insert(B.begin(),B.end());
}
	
template<typename T>
void set_difference(set<T> &A, set<T> &B, set<T> &C){ // A - B:
	C.clear();
	set<int>::iterator itA = A.begin();

	while(itA != A.end()){
		if(B.find(*itA) == B.end()) C.insert(*itA);
		++itA;
	}
}
	
void diffsym(list<set<int>> &L, set<int> &ad){
	ad.clear();
	list<set<int>>::iterator it = L.begin();
	
	ad = *it;
	++it;
	
	while(it != L.end()){
		set<int> difBA, difAB;
		
		set_difference(ad, *it, difAB);
		set_difference(*it, ad, difBA);
		
		set_union(difAB, difBA, ad);
		++it;
	}
}

int main() {
	
	return 0;
}







