#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;


bool has_duplicates(list<int> L){
	L.sort();
	list<int>::iterator iT = L.begin();
	list<int>::iterator iT1 = L.begin(); ++iT1;
	while(iT1 != L.end()){
		if (*iT == *iT1) return true;
		iT = iT1++;
	}		return false;
} 
	bool es_camino(map<int,vector<int>> &G, list<int> &L){
		
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
bool isHamilt(map<int,vector<int>> &G, list<int>&L){
	list<int>::iterator it = L.begin();
	if(it == L.end() && G.empty()) return true;
	if(L.size() != G.size()) return false;
	if(has_duplicates(L)) return false;
	return es_camino(G,L);
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
typedef map<int,vector<int>> graph_t;
bool is_cycle(graph_t &G){
	auto it = G.begin();
	
	while(it != G.end()){
		if(it->second.size() != 1) return false;
		++it;
	}
	
	list<int> L;
	L.push_back(G.begin()->first);
	list<int>::iterator it1 = L.begin();
	
	for(int i=0;i<G.size();i++) { 
		auto it2 = G.find(*(it1));
		L.push_back(*(it2->second.begin()))
		++it1;
	}
	
	if(!isHamilt(G,L)) return false;
	
	return true;
}

int main() {
	graph_t G = {{0,{1}},{1,{2}},{2,{3}},{4,{5}},{5,{0}}};
	if(is_cycle(G)) cout<<"si";
	return 0;
}







