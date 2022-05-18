#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &L){
	list<int>::const_iterator itB = L.cbegin();
	cout <<"[ ";
	while(itB != L.cend()){
		cout << *itB << " ";
		++itB;
	}
	cout <<"]"<<endl;
}

void merge(list<int> &L1, list<int> &L2, list<int> &L){
	L = L1;
	for(auto it = L2.begin(); it != L2.end(); it++){
		L.push_back(*it);
	}
	
	list<int> L_aux;
	auto itB = L.begin();
	
	while(!L.empty()){
		for(auto it = L.begin(); it != L.end(); it++){
			if(*it <= *itB){
				itB = it;
			}
		}
		L_aux.push_back(*itB);
		L.erase(itB);
		++itB;
	}
	L.swap(L_aux);
}
	
// T(n) = 2T(n/2) + O(n)
void mergesort(list<int> &L){
	
	if(L.size()<=1){
		return;
	} 
	
	int medio = L.size()/2;
	list<int> L1, L2;
	auto it_medio = L.begin();
	for(int i=0;i<medio;i++) { ++it_medio; }
	L1.splice(L1.begin(),L,L.begin(),it_medio);
	L2.splice(L2.begin(),L,it_medio,L.end());
	
	mergesort(L1);
	mergesort(L2);
	merge(L1,L2,L);
	
}

int main() {
	list<int> L1 = {1,4,2,7,2};
	list<int> L2 = {1,8,3,6,11};
	list<int> L3;
	mergesort(L1);
	print_list(L1);
	
	return 0;
}







