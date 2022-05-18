#include <iostream>
#include <stack>
using namespace std;

bool chequeo(stack<char> x){
	int cont = 0;
	
	while(!x.empty()){
		char a = x.top();
		if (a == ')'){
			++cont;
		}
		if(a == '('){
			if(cont > 0){
				--cont;
			} else {
				return false;
			}
		}
		x.pop();
	}
	
	if(cont == 0){
		return true;
	} else {
		return false;
	}
}

int main() {
	
	stack<char> s;
	s.push('('); s.push('a'); s.push('+'); s.push('b'); s.push(')'); s.push('.');
	bool rta = chequeo(s);
	if(rta) cout<<"si";
	if(!rta) cout<<"no";
	
	return 0;
}







