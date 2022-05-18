#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef map<int,vector<int>> graph_t;
	
void map_graph(graph_t &Gin, map<int,int> &P, graph_t &Gout){
	Gout.clear();
	
	for(auto it = Gin.begin(); it != Gin.end(); it++){
		int j = it->first;
		
		for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
			int k = *it2;
			int Pj = P[j];
			int Pk = P[k];
			Gout[Pj].push_back(Pk);
		}
		
		for(auto it = Gout.begin(); it!=Gout.end(); it++){
			sort(it->second.begin(),it->second.end());
		}
		
	}
}


int main() {
	graph_t G = {{0,{1}},{1,{0,2,3}},{2,{1,4}},{3,{1,4}},{4,{2,3}}};
	map<int,int> P = {{0,1},{1,2},{2,3},{3,4},{4,0}};
	graph_t N;
	map_graph(G,P,N);

	return 0;
}







