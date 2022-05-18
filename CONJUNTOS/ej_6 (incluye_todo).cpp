#include <iostream>
using namespace std;

int includes_all(vector<set<int>> &setv){
	int j = 0;
	for(int k = 0; k < setv.size(); k++){
		if(setv[k].size() > setv[j].size()) j = k;
	}
	
	set<int> &sj = setv[j];
	for(int k = 0; k<n; k++){
		set<int> &sk = setv[k];
		set<int>::iterator q = sj.begin();
		while(q != sj.end()){
			if(sk.find(*q) == sk.end()) return -1;
			q++;
		}
	}
	return j;
}

/// versión con operaciones binarias:
int includes_all(vector<set<int>> &setv){
	int j = 0;
	for(int k = 0; k < setv.size(); k++){
		if(setv[k].size() > setv[j].size()) j = k;
	}
	
	set<int> tmp;
	for(int k = 0; k < setv.size(); k++){
		set_difference(setv[k],setv[j],tmp);
		if(!tmp.empty()) return -1;
	}
	return j;
}

int main() {
	
	return 0;
}







