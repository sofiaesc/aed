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
	
	void junta(list<int> &L, int c){
		auto it = L.begin();
		list<int> L_aux;
		int sum = 0;
		int cont = 0;
		
		while(it != L.end()){
			sum += *it;	
			it = L.erase(it); // borra ese puntero y adelanta una posición el iterador.
			++cont;
			
			if(cont==c){
				L_aux.push_back(sum);
				sum =0;
				cont=0;
			}
		}
		
		if(cont!= 0){ L_aux.push_back(sum);}
		L.swap(L_aux);
	}
		
/*
void junta(list<int> &L, int c){
	list<int>::iterator it = L.begin();
	// mientras el primer elemento no sea igual al último:
	while(it != L.end()){
		// iterador que siempre va a estar uno más adelante del primero:
		list<int>::iterator it2 = it++;
		// for que se encarga de la suma, mientras no se llegue al end o a c:
		for(int i=1; (it!=L.end() and i<c); i++){
			// sumo los dos primeros en el lugar del segundo
			*it2 += *it;
			// el primero pasa a tomar el lugar del segundo, por lo que
			// su valor es la suma de los dos primeros
			it++;
			// el segundo va a adelantarse una posición y así se suma el
			// tercer número con los dos anteriores. así sucesivamente.
		}
		// cuando se termina el for de la suma de c elementos, se
		// borran los elementos sumados y se guarda la posición en it
		// desde donde se borró para volver al while.
		it = L.erase(++it2,it);
	}
}
*/

int main(int argc, char *argv[]) {
	list<int> L = {1,2,7,3,4,6,2,3};
	junta(L,3);
	print_list(L);
	return 0;
}

