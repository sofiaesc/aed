#include <iostream>
#include <list>
using namespace std;

/* BasicSort. Escribir una funci´on void basic_sort(list<int> &L), que ordena los elementos de L
de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vac´ia.
Luego insertar los elementos de L2 en L. */
/*
void basic_sort(list<int> &L){
	list<int> L_aux;
	
	while(!L.empty()){
		list<int>::iterator itB = L.begin();
		int min = *itB;
		
		list<int>::iterator it = itB;
		
		++itB;
		
		while(itB != L.end()){
			int tmp = *itB;
			if(min > tmp){
				min = tmp;
				it = itB;
			}
			++itB;
		}
		L.erase(it);
		L_aux.push_back(min);
	}
	L.swap(L_aux);
}*/

/// versión mía:

void basic_sort(list<int> &L){
	list<int> L2;
	
	while(!L.empty()){
		auto itB = L.begin();
		for(auto it = L.begin(); it != L.end(); it++){
			if(*it < *itB){
				itB = it;
			}
		}
		L2.push_back(*itB);
		L.erase(itB);
	}
	L.swap(L2);
}
	
	
/* Función para imprimir la lista: */
	
void print_list(const list<int> &L){
	list<int>::const_iterator itB = L.cbegin();
	cout <<"[ ";
	while(itB != L.cend()){
		cout << *itB << " ";
		++itB;
	}
	cout <<"]"<<endl;
}

/* SelectionSort. Escribir una función void selection_sort(list<int> &L), que ordena los
elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo
(swap) con el primer elemento de la lista. Luego intercambiar el menor elemento de la lista
restante, con el segundo elemento, y así sucesivamente. Esta función debe ser IN PLACE.*/
/*
void selection_sort(list<int> &L){
	
	list<int>::iterator itB = L.begin();
	list<int>::iterator itE = L.end();
	--itE;
	
	for(itB = L.begin(); itB != L.end(); ++itB){
		
		for(list<int>::iterator itB2 = itB; itB2 != L.end(); ++itB2){
			if(*itB > *itB2){
				int min = *itB2;
				*itB2 = *itB;
				*itB = min;
			}
		}
	}
}*/
	
	void selection_sort(list<int> &L){
		for(auto it = L.begin(); it != L.end(); it++){
			for(auto it2 = L.begin(); it2 != L.end(); it2++){
				if(*it2 > *it){
					swap(*it,*it2);
				}
			}
		}
	}
	
int main(int argc, char *argv[]) {
	
	list<int> L = {1,2,4,3,200,50};
	basic_sort(L);
	print_list(L);
	
	return 0;
}

