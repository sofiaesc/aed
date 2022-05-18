#include <iostream>
#include <map>
#include <list>
using namespace std;

typedef map<int,list<int>> graph_t;
bool checksz(graph_t &G1, graph_t &G2){
	
	if(G1.size() != G2.size()) return false;
	
	auto it1 = G1.begin();
	
	while(it1 != G1.end()){
		auto it = G2.find(it1->first);
		if(it == G2.end()) return false;
		
		if(it1->second.size() != it->second.size()) return false;
		
		++it1;
	}
	
	return true;
}

int main() {
	graph_t G1 = {{1,{2,4}},{2,{1,3,4}}};
	graph_t G2 = {{1,{3,4}},{2,{5,6,7}},{3,{0}}};
	
	if(checksz(G1,G2)) cout<<"si";
	
	return 0;
}







