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

void cutoffmap(map<int, list<int>> &M, int p, int q){
	
	for(auto it = M.begin(); it != M.end(); it++){
		if(it->first < p || it->first >= q){
			it = M.erase(it);
			++it;
		}
	}
}

int main() {
	
	map<int,list<int>> M = { {1,{2,3,4}}, {2,{3,4,5}}, {4,{3,2,1}}, {3,{1,7,5}}, {7,{3,2,1}}};
	cutoffmap(M,2,8);
	print_map(M);
	
	return 0;
}







