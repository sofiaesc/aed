#include <iostream>
using namespace std;

template<typename T>
bool cubre_todo(vector<set<T>> &v, set<T> &W){
	for(int i = 0; i < v.size(); i++){
		set<T> aux;
		set_intersection(v[i],W,aux);
		if(aux.size() != v[i].size()) return false;
	}
	return true;
}
	
/// versión sin intersection:
/* template<typename T>
bool cubre_todo(vector<set<T>>&V, set<T>& W){	auto itV = V.begin();	while( itV != V.end() ){		auto itS = (*itV).begin();		while( itS != (*itV).end() ){			if( W.find(*itS) == W.end() )				return false;			itS++;		}		itV++;	}		return true;
} */

int main() {
	
	return 0;
}







