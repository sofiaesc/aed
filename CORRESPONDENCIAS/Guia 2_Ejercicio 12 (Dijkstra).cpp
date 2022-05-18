#include <iostream>
#include <map>
#include <list>
#include <limits>
using namespace std;

typedef map<int,map<int,float>> graphW;
float Dijkstra(graphW &G, int u, int v, list<int> &path){
	map<int,float> acum;
	
	auto it = G.begin();
	while(it != G.end()){
		acum[it->first] = numeric_limits<float>::infinity();
	}
	
	return 9999;
}

int main() {
	
	return 0;
}







