#include <iostream>
#include <list>
#include <map>
using namespace std;

typedef map<int,list<int>> graph_t;
bool is_shift(graph_t &G1, graph_t &G2, int m){
	auto it = G1.begin();
	if(G1.size() != G2.size()) return false;
	
	while(it != G1.end()){
		int n = (it->first) + m;
		auto it2 = G2.find(n);
		if(it2 == G2.end()) return false;
		
		auto it3 = it->second.begin();
		auto it4 = it2->second.begin();
		bool flag = true;
		while(flag){
			if(*it4 != (*it3 + m)) return false;
			++it3;
			++it4;
			if(it3 == it->second.end()) break;
		}
		
		if(flag == false) return false;
		++it;
	}
	return true;
}

int main() {
	graph_t G1 = {{1,{2,4}},{2,{1,3,4}},{3,{2,4}},{4,{1,2,3}}};
	graph_t G2 = {{4,{5,7}},{5,{4,6,7}},{6,{5,7}},{7,{4,5,6}}};
	if(is_shift(G1,G2,3)) cout<<"si";
	return 0;
}







