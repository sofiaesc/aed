#include <iostream>
#include <list>
using namespace std;

bool menor(int x, int y){
	return x<y;
}

bool mayor(int x, int y){
	return x>y;
}

bool dist(int x, int y){
	return abs(x)<abs(y);
}

void ordena(list<int> &L, bool (*f)(int,int)){
	
	for(auto it=L.begin();it!=L.end();it++){
		for(auto it_2=it;it_2!=L.end();it_2++){
		if(!(*f)(*it,*it_2)){
			swap(*it,*it_2);
		}
		}
	}
}
	
	void print_list(const list<int> &L){
		list<int>::const_iterator itB = L.cbegin();
		cout <<"[ ";
		while(itB != L.cend()){
			cout << *itB << " ";
			++itB;
		}
		cout <<"]"<<endl;
	}

int main() {
	list<int> L = {1,6,-3,8,-2,-100};
	ordena(L,mayor);
	print_list(L);
	ordena(L,dist);
	print_list(L);
	ordena(L,menor);
	print_list(L);
	return 0;
}







