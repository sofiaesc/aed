#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;

void listar_ABB(btree<int> &BT, btree<int>::iterator itB){
	if(itB == BT.end()) return;
	listar_ABB(BT,itB.left());
	cout<<*itB<<" ";
	listar_ABB(BT,itB.right());
}

void listar_ABB(btree<int> &BT){
	listar_ABB(BT,BT.begin());
}
	
btree<int>::iterator findABB(btree<int> &BT, int v){
	btree<int>::iterator it = BT.begin();
	while(true){
		if(it == BT.end()) return it;
		if(v < *it) it = it.left();
		else if(v > *it) it = it.right();
		else return it;
	}
}
void inserta_ABB(btree<int> &BT, int v){
	btree<int>::iterator pos = findABB(BT,v);
	if(pos == BT.end()) BT.insert(pos,v);
}

void elimina_ABB(btree<int> &BT, int v){
	btree<int>::iterator pos = findABB(BT,v);
	if(pos != BT.end()){
		if(pos.left() == BT.end() && pos.right() == BT.end()) BT.erase(pos);
		else if(pos.right() == BT.end()){
			btree<int> temp;
			temp.splice(temp.begin(), pos.left());
			pos = BT.erase(pos);
			BT.splice(pos, temp.begin());
		} else if(pos.left() == BT.end()){
			btree<int> temp;
			temp.splice(temp.begin(), pos.right());
			pos = BT.erase(pos);
			BT.splice(pos,temp.begin());
		} else {
			btree<int>::iterator minR = pos.right();
			while(minR.left() != BT.end()){
				minR = minR.left();
			}
			int valorTemp = *minR;
			BT.splice(minR,minR.right());
			*pos = valorTemp;
		}
	}
}
	
int main() {
	
	return 0;
}







