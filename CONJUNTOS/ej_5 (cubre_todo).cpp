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
	
/// versi�n sin intersection:
/* template<typename T>
bool cubre_todo(vector<set<T>>&V, set<T>& W){
} */

int main() {
	
	return 0;
}






