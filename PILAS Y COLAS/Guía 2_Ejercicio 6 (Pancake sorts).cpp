#include <iostream>
using namespace std;

void show_stack(stack<int> S){
	while(!S.empty()){
		cout<<S.top()<<endl;
		S.pop();
	}
}

void get_max(stack<int> &S){
	
}

void invertir(stack<int> &S, int n){
	queue<int> Q;
	for(int i = 0; i<n; i++){
		Q.push(S.top());
		S.pop();
	}
	
	for(int i=0;i<n;i++){
		S.push(Q.front());
		Q.pop();
	}
}

void pancake_sort(stack<int> &S){
	
}

void burntpancake_sort(stack<int> &S){
	
}

int main() {
	
	return 0;
}







