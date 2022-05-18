#include <iostream>
#include <stack>
using namespace std;

void funcion_a(stack<int> &p,int i){
	p.pop(); p.pop();
	p.push(i);
}

int main() {
	
	stack<int> P;
	P.push(1);
	P.push(2);
	P.push(3);
	P.push(4);
	P.push(5);
	P.push(6);
	
	int num = 7;
	// a:
	P.pop(); P.pop();
	P.push(num);
	
	// b:
	int num_f = P.top();
	P.pop(); P.pop();
	P.push(num_f);
	P.push(num);

	// c:
	int n = 1;
	if(P.size()>=n){
		for(int i=0;i<n;i++) { 
			P.pop();
		}
		P.push(num);
	}
	
	// d:
	while(!P.empty()){
		P.pop();
	}
	P.push(num);
	
	// e:
	stack<int> P_aux;
	
	while(!P.empty()) { 
		P_aux.push(P.top());
		P.pop();
	}
	P.push(num);
	
	while(!P_aux.empty()){
		P.push(P_aux.top());
		P_aux.pop();
	}
	
	// mostrar la pila:
	while(!P.empty()){
		cout<<P.top()<<" ";
		P.pop();
	}
	
	return 0;
}







