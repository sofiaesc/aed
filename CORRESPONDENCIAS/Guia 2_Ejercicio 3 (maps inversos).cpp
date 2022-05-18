#include <iostream>
#include <map>
using namespace std;

bool areinverse(map<int,int> &M1, map<int,int> &M2){
	if(M1.size() != M2.size()) return false;

	for(auto it = M1.begin(); it != M1.end(); it++){
		if(M2[it->second] != it->first) return false;
	}
	for(auto it = M2.begin(); it != M2.end(); it++){
		if(M1[it->second] != it->first) return false;
	}
	
	return true;
}

int main() {
	map<int,int> M1 ={{1,2},{3,4},{5,7},{9,6}};
	map<int,int> M2 ={{2,1},{4,3},{7,5},{6,9}};
	
	if(areinverse(M1,M2)){
		cout<<"si";
	} else { 
		cout<<"no"; 
	}
	
	return 0;
}







