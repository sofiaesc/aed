#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &L){
	list<int>::const_iterator itB = L.cbegin();
	cout <<"[ ";
	while(itB != L.cend()){
		cout << *itB << " ";
		++itB;
	}
	cout <<"]"<<endl;
}
/*
void invert(list<int> &L){
	if(!L.empty()){
		if(L.begin() != L.end()){
			list<int>::iterator itB = L.begin();
			list<int>::iterator itE = L.end();
			// el iterador en L.end no apunta al último
			// elemento de la lista, por eso resto uno.
			--itE;
			
			// mientras los iteradores sean distintos:
			while(itB != itE){
				// cambio el primero y el último
				swap(*itB, *itE);
				// el primero pasa a ser el segundo.
				itB++;
				// si no son iguales tras esa suma, el
				// último pasa a ser el penúltimo.
				if(itB != itE){
					--itE;
				}
			}
		}
	}
}*/
	void invert(list<int> &L){
		
		if(!L.empty()){
			if (L.begin() != L.end()){
				auto itB = L.begin();
				auto itE = L.end();
				itE--;
				
				while(itB != itE){
					swap(*itB,*itE);
					itB++;
					
					if(itB != itE){
						itE--;
					}
				}
			}
		}
		
	}
	
	/// con itComp, que está siempre a una dirección
	/// de memoria del itB. Cuando el itComp sea igual
	/// al itEnd es porque se llegó al último par en
	/// el medio y se deja de iterar. Cuando son impares,
	/// cuando se llega al elemento del medio se corta
	/// el while(itB != itE) y que itB = itE.
	
/* void invert(list<int>& L){
	list<int>::iterator itB = L.begin();
	list<int>::iterator itE = L.end();
	--itE;
	
	list<int>::iterator itComp = itB;
	++itComp;
	
	while(itB != itE){
		swap(*itB, *itE);
	
		if(itComp == itE){
			break;
		}
	
		++itB;
		--itE;
		++itComp;
	} */

int main(int argc, char *argv[]) {
	
	list<int> L = {0,6,9,8,8,2};
	invert(L);
	print_list(L);
	
	return 0;
}

