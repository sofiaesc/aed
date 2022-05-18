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
	cout <<"]"<<endl;
}

bool es_camino(map<int,list<int>> &G, list<int> &L){
	
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
	
bool has_duplicates(list<int> L){
	L.sort();
	list<int>::iterator iT = L.begin();
	list<int>::iterator iT1 = L.begin(); ++iT1;
	while(iT1 != L.end()){
		if (*iT == *iT1) return true;
		iT = iT1++;
	}		return false;
} 
	
bool isHamilt(map<int,list<int>> &G, list<int>&L){
	list<int>::iterator it = L.begin();
	if(it == L.end() && G.empty()) return true;
	if(L.size() != G.size()) return false;
	if(has_duplicates(L)) return false;
	return es_camino(G,L);
}
	
	// VERSIÓN CON VISITADOS

bool pertenece(list<int> &L, int nodo){
	list<int>::iterator it = L.begin();
	while(it != L.end()){
		if(*it == nodo) return true;
		it++;
	}
	return false;
}
	
bool is_hamilt(map<int,list<int>> &G, list<int> &L){
	list<int>::iterator it = L.begin();
	
	if(it == L.end() && G.empty()) return true;
	
	while(it != L.end()){
		it(G.find(*it) == G.end()) return false;
		it++;
	}
	
	list<int> visitados;
	it = L.begin();
	list<int>::iterator itNext;
	
	bool continuar = true;
	while(continuar){
		if(pertenece(visitados, *it)) return false;
		visitados.push_back(*it);
		itNext = it;
		itNext++;
		
		if(itNext != L.end()){
			if(!pertenece(G[*it], *itNext)) return false;
			it = itNext;
		} else {
			continuar = false;
		}
	}
	
	return visitados.size() == G.size();
}

int main() {
	
	return 0;
}







