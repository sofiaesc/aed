#include <iostream>
#include <list>
#include <map>
using namespace std;

void print_list(const list<int> &L){
	list<int>::const_iterator itB = L.cbegin();
	cout <<"[ ";
	while(itB != L.cend()){
		cout << *itB << " ";
		++itB;
	}
	cout <<"]";
}
	
	void print_map(map<int,list<int>> &M){
		cout<<"M = { ";
		for(auto it = M.begin(); it != M.end(); it++){
			cout<<"["<<(*it).first<<"] = ";
			print_list(it->second);
			cout<<", ";
		}
		cout<<"}";
	}

void odd2even(list<int> &L, map<int,list<int>> &M){
	M.clear();
	list<int> aux;
	auto it = L.begin();
	
	int n = *it;
	++it;
	while(it != L.end()){
		if((*it)%2 == 0) M[n].push_back(*it);
		if((*it) % 2 == 1){
			n = *it;
			M[n];
		}
		++it;
	}
}
	
int main() {
	list<int> L = {1,2,4,3,2,5,2,7,1,6,9,2,14};
	map<int,list<int>> M;
	odd2even(L,M);
	print_map(M);
	return 0;
}







