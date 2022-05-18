#include <iostream>
#include <map>
#include <list>
using namespace std;

void print_map(map<int,int> &M){
	cout<<"M = { ";
	for(auto it = M.begin(); it != M.end(); it++){
		cout<<"["<<(*it).first<<"]="<<(*it).second<<" ";
	}
	cout<<"}";
}

template<typename T, typename Q>
void map2list(map<T,Q> &M, list<T> &keys, list<Q> &vals){
	auto it = M.begin();
	keys.clear(); vals.clear();
	
	while(it != M.end()){
		keys.push_back(it->first);
		vals.push_back(it->second);
		++it;
	}
}

void list2map(map<int,int> &M, list<int> &keys, list<int> &vals){
	auto it_k = keys.begin();
	auto it_v = vals.begin();
	
	while(it_k != keys.end()){
		if(it_v != vals.end()){
			M[*it_k] = *it_v;
			++it_v;
		}else{
			M[*it_k] = 0;
		}
		++it_k;
	}
}

int main() {
	map<int,int> M; /* ={{1,2},{2,4},{3,7},{4,5}};*/
	list<int> L = {1,2,3};
	list<int> K = {1,2,3,4,5};
	list2map(M,K,L);
	print_map(M);
	return 0;
}







