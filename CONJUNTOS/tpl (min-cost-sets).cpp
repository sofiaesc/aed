#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

int minCostSets(set<int> &U, vector<set<int>> S, map<set<int>,int> &costos, list<set<int>> &L, int pos){
	if(U.size() == 0){
		int sum = 0;
		auto itL = L.begin();
		while(itL != L.end()){
			sum += costos[*itL];
			++itL;
		}
		return sum;
	}
	
	if(pos < 0) return INT_MAX;
	
	set<int> U_aux = U;
	list<set<int>> L_aux = L;
	L.push_back(S[pos]);
	for(int elem: S[pos]){
		U.erase(elem);
	}
	
	int cost1 = minCostSets(U, S, costos, L, pos-1);
	int cost2 = minCostSets(U_aux, S, costos, L_aux,pos-1);
	
	return min(cost1, cost2);
}

int minCostSets(set<int> &U, vector<set<int>> &S, map<set<int>,int> &costos){
	list<set<int>> L;
	return minCostSets(U,S,costos,L,S.size()-1);
}

int main() {
	
	return 0;
}







