#include <iostream>
#include <set>
using namespace std;

template<typename T>void print_set(const set<T> &A) {	cout<<"[ ";
	for(T x:A) cout << x << " ";
	cout<<"]";}

template <typename T>
void set_union(set<T> &A, set<T> &B, set<T> &C){
	C = A;
	C.insert(B.begin(),B.end());
}
	
template<typename T>
void set_intersection(set<T> &A,set<T> &B,set<T> &C){ 
	C.clear();
	set<int>::iterator itA = A.begin();
	
	while(itA != A.end()){
		if(B.find(*itA) != B.end()) C.insert(*itA);
		++itA;
	}
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
	
int main() {
	
	set<int> s1 = {0,1,2,3};
	set<int> s2 = {3,4,5,6};
	set<int> s3;
	set_union(s1,s2,s3);
	print_set(s3);
	cout<<endl;
	set_intersection(s1,s2,s3);
	print_set(s3);
	cout<<endl;
	set_difference(s1,s2,s3);
	print_set(s3);
	return 0;
}







