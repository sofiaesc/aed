#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

bool inverso(list<char> &z){
	stack<char> p;
	queue<char> c;
	
	for(auto it = z.begin();it != z.end(); it++){
		p.push(*it);
		c.push(*it);
	}
	
	int n = p.size();
	bool resultado= true;
	for(int i=0;i<n;i++) { 
		if(p.top() != c.front()){
			resultado = false;
		}
	}
	
	return resultado;
}

int main() {
	
	list<char> z = {'a','b','c','d','a'};
	if(inverso(z)) cout<<"si";
	
	return 0;
}







