#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

void sort_stack(list<int> &L){
	stack<int> P;
	
	while(!L.empty()){
		auto itB = L.begin();
		for(auto it = L.begin(); it != L.end(); it++){
			if(*it < *itB){
				itB = it;
			}
		}
		P.push(*itB);
		L.erase(itB);
	}
	
	while(!P.empty()){
		L.push_back(P.top());
		P.pop();
	}
}

void sort_queue(list<int> &L){
	queue<int> C;
	
	while(!L.empty()){
		auto itB = L.begin();
		for(auto it = L.begin(); it != L.end(); it++){
			if(*it < *itB){
				itB = it;
			}
		}
		C.push(*itB);
		L.erase(itB);
	}
	
	while(!C.empty()){
		L.push_back(C.front());
		C.pop();
	}
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
	
	list<int>L = {3,2,5,6,1,2,7,4};
	sort_stack(L);
	print_list(L);
	sort_queue(L);
	print_list(L);
	
	return 0;
}







