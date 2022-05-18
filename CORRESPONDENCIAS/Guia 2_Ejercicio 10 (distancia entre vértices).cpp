#include <iostream>
#include <list>
#include <map>
using namespace std;

bool pertenece(list<int> &L, int nodo){
	list<int>::iterator it = L.begin();
	while(it != L.end()){
		if(*it == nodo) return true;
		it++;
	}
	return false;
}

void genNivel(map<int,list<int>> &G, list<int> &L, list<int> &visitados,list<int> &L_aux){
	auto it = L.begin();
	while(it != L.end()){
		auto it_2 = G[*it].begin();
		while(it_2 != G[*it].end()){
			if(!pertenece(visitados,*it_2)){ 
				L_aux.push_back(*it_2);
				visitados.push_back(*it_2);
			}
			++it_2;
		}
		++it;
	}
}

map<int,list<int>> distancia(map<int,list<int>> &G, int x){
	map<int,list<int>> G_aux;
	if(G.empty() || G.find(x) == G.end()) return G_aux;
	
	list<int> L;
	L.push_back(x);
	G_aux[0]=L;	
	
	list<int> visitados;
	visitados.push_back(x);
	int i = 0;
	while(visitados.size() != G.size()){
		list<int> L_aux;
		genNivel(G,G_aux[i],visitados,L_aux);
		
		++i;
		G_aux[i] = L_aux;
	}
	return G_aux;
}

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
	
int main() {
	
	map<int,list<int>> G = {{1,{2,3,6}},{2,{3,4,1}},{3,{6,5,1}},{4,{2,6}},{5,{3,6}},{6,{1,3,4,5}}};
	map<int,list<int>> G_aux = distancia(G,1);
	
	print_map(G_aux);
	
	return 0;
}







