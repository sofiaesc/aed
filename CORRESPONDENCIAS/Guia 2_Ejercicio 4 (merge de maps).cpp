#include <iostream>
#include <map>
#include <list>
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

void merge_map(map<int,list<int>> &A, map<int,list<int>> &B,map<int,list<int>> &C){
	auto itA = A.begin();
	auto itB = B.begin();
	list<int> aux;
	
	while(itA != A.end() || itB != B.end()){ 
		
		if(itB != B.end()){
			merge(A[it->first],B[it->first],aux);
			it++;
		} else {
			merge(A[it->first],aux,A[it->first]);
		}
		C[it->first]=aux;
		
		if(itA != A.end()){
			
		}
	}
	
}

int main() {
	
	map<int,list<int>> M1 ={{1,{4,2,3}},{4,{6,7}},{5,{7}}};
	map<int,list<int>> M2 ={{1,{1,2,3}},{4,{5}},{7,{5}}};
	map<int,list<int>> M3;
	
	//merge_map(M1,M2,M3);
	print_map(M2);
	
	return 0;
}







