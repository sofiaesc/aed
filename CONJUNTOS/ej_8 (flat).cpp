#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool flat(vector<set<int>> &sw,int n){
	for(int j=0; j<n-1; j++){
		for(int k=j+1; k<n; k++){
			bool flag = false;
			for(int l = 0; l<sw.size(); l++){
				if(sw[l].find(j) != sw[l].end() && sw[l].find(k) != sw[l].end()) flag = true;
			}
			if(!flag) return false;
		}
	}
	return true;
}

int main() {
	vector<set<int>> v;
	v.push_back({0,1,2,3,4});
	v.push_back({0,1,5,6,7});
	v.push_back({2,3,4,5,6,7});
	
	if(flat(v,8)) cout<<"si";
	
	return 0;
}







