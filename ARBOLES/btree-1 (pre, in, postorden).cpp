#include <iostream>
using namespace std;

void orden_prev(btree<int>& T, btree<int>::iterator it) {
	if(it == T.end()) return;
	
	cout<<*it<<" ";
	orden_prev(T, it.left());
	orden_prev(T, it.right());
}

void orden_post(btree<int>& T, btree<int>::iterator it) {
	if(it == T.end()) return;
	
	orden_post(T, it.left());
	orden_post(T, it.right());
	cout<<*it<<" ";
}

void orden_sim(btree<int>& T, btree<int>::iterator it) {
	if(it == T.end()) return;
	
	orden_sim(T, it.left());
	cout<<*it<<" ";
	orden_sim(T, it.right());
}

int main() {
	
	return 0;
}







