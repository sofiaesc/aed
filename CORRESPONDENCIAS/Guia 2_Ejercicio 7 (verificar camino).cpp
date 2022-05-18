#include <iostream>
#include <list>
#include <map>
using namespace std;

typedef map<int,list<int>> Graph;

template<typename T>
void show_list(const list<T> &L){
	cout<<"[ ";
	for_each(L.begin(),L.end(),[](T v){ cout<<v<<" "; });
	cout<<"] \n";
}
	
bool es_camino(Graph &G, list<int> &L){
	
	if(L.empty()) return false;
	
	auto itL = L.begin();
	auto itL2 = ++L.begin();
	
	if(L.size() == 1){
		if(G.find(*itL) != G.end()) return true;
		else return false;
	}
	
	while(itL2 != L.end()){
		auto itG = G.find(*itL);
		if(itG == G.end()) return false;
		
		auto it3 = itG->second.begin();
		while(it3 != itG->second.end()){
			if(*it3 == *itL2) break;
			++it3;
		}
		if(it3 == itG->second.end()) return false;
		
		++itL;
		++itL2;
	}
	return true;
}

int main() {
	
	Graph g = {{1,{2,3,4,5}}, {2,{1}}, {3,{1,4}},{4,{1,3,5}},{5,{4,1}}};
	list<int> L = {1,2,3};
	if(es_camino(g,L)) cout<<"si";
	else cout<<"no";
	
	return 0;
}







