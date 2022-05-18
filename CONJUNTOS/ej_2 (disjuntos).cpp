#include <iostream>
using namespace std;

template<typename T>
void set_intersection(set<T> &A,set<T> &B,set<T> &C){ 
	C.clear();
	set<int>::iterator itA = A.begin();
	
	while(itA != A.end()){
		if(B.find(*itA) != B.end()) C.insert(*itA);
		++itA;
	}
}

bool disjuntos(vector<set<T>> &v){
	int n = v.size();
	
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j<n; j++){
			set<int> tmp;
			set_intersection(v[i],v[j],tmp);
			if(!tmp.empty()) return false;
		}
	}
	
	return true;
}

	
int main() {
	set<int> s1 = {0,1,2,3};
	set<int> s2 = {3,4,5,6};
	set<int> s1 = {0,1,2,3};
	set<int> s2 = {3,4,5,6};
	vector<set<int>> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s);
	return 0;
}







