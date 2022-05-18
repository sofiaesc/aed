#include <iostream>
#include <map>
#include <list>
using namespace std;

void genCompConexa(map<int,list<int>> &G, map<int,bool> &visitados, int label, list<int> &cc){
	visitados[label];
	cc.push_back(label);
	list<int> &adyacentes = G[label];
	for(auto vecino:adyacentes){
		if(visitados.find(vecino) == visitados.end()){
			genCompConexa(G,visitados,vecino,cc);
		}
	}
}

void comp_conexas(map<int,list<int>> &G, list<list<int>> &D){
	map<int,bool> visitados;
	while(visitados.size() < G.size()){
		int label;
		for(auto vertice:G){
			if(visitados.find(vertice.first) == visitados.end()){
				label = vertice.first;
				break;
			}
		}
		list<int> cc;
		genCompConexa(G, visitados, label, cc);
		D.push_back(cc);
	}
	
}

int main() {
	
	return 0;
}







