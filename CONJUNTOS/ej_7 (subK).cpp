#include <iostream>
#include <list>
#include <set>
using namespace std;

void show_set(set<int> A) {
	cout<<"{ ";
	for(auto i:A) {
		cout<<i<<" ";
	}
	cout<<"}"<<endl;
}

void subk(set<int> S, int k, list<set<int>> &L,set<int> Sk){
	if(k==0){
		L.push_back(Sk);
		return;
	}
	if(S.empty()) return;
	int elem = *S.begin();
	S.erase(S.begin());
	subk(S,k,L,Sk);
	Sk.insert(elem);
	subk(S,k-1,L,Sk);
}

list<set<int>> subk(set<int> S, int k){
	list<set<int>> L;
	set<int> Sk = {};
	subk(S,k,L,Sk);
	return L;
}

int main() {
	set<int> S = {1, 2, 3, 4};
	list<set<int>> L = subk(S,2);
	list<set<int>>::iterator it = L.begin();
	while(it != L.end()){
		show_set(*it);
		++it;
	}
	
	return 0;
}







