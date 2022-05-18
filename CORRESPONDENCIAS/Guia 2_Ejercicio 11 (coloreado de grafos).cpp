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

list<list<int>> coloreadoGrafos(map<int,list<int>> &G){
	list<list<int>> LL;
	if(G.empty()) return LL;
	
	list<int> visitados;
	list<int> L;
	
	auto it = G.begin();
	
	while(visitados.size() != G.size()){
		L.push_back(it->first);
		visitados.push_back(it->first);
		++it;
		auto it_3 = it;
		
		if(!pertenece(visitados,it_3->first)){
			while(it_3 != G.end()){
				
				bool flag = true;
				auto it_2 = L.begin();
				while(it_2 != L.end()){
					if(pertenece(G[*it_2],it_3->first)){
						flag = false;
					}
					++it_2;
				}
				
				auto it_4 = LL.begin();
				while(it_4 != LL.end()){
					if(pertenece(*it_4,it_3->first)) flag = false;
					++it_4;
				}
				
				if(flag){
					L.push_back(it_3->first);
					visitados.push_back(it_3->first);
				}
				
				++it_3;
			}
			
			LL.push_back(L);
			L.clear();
		}
	}
	
	if(L.size() != 0) LL.push_back(L);
	
	return LL;
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
		
int main() {
	
	map<int,list<int>> G = {{1,{2,3,6}},{2,{3,4,1}},{3,{2,6,5,1}},{4,{2,6}},{5,{3,6}},{6,{1,3,4,5}}};
	list<list<int>> L = coloreadoGrafos(G);
	for(auto it = L.begin(); it != L.end(); it++){
		print_list(*it);
	}

	return 0;
}







