#include <iostream>
#include <list>
#include <map>
using namespace std;

void apply_map(list<int> &L, map<int,int> &M, list<int> &ML){
	for(auto it = L.begin(); it != L.end(); it++){
		if(M.find(*it) != M.end()){
			ML.push_back(M[*it]);
		}
	}
}

int main() {
	
	return 0;
}







