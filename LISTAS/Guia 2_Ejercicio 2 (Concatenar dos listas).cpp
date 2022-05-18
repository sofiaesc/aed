#include <iostream>
#include <list>
using namespace std;

/* función para imprimir la lista: */

void print_list(const list<int> &L){
	list<int>::const_iterator itB = L.cbegin();
	cout <<"[ ";
	while(itB != L.cend()){
		cout << *itB << " ";
		++itB;
	}
	cout <<"]"<<endl;
}

/* concatenar dos listas L1 y L2 usando insert: */

	/// para hacer la función void:
	/* una lista más en el argumento y con un iterador voy recorriendo,
	llenando los lugares con los nuevos elementos de la lista. */
	
list<int> concatenar_a(list<int> &L1, list<int> &L2){
	list<int> L_aux = L1;
	
	/// versión simple: insert por elementos
/* list<int>::iterator L2 = L2.begin();
	while(itL2 != L2.end()){
		L.insert(L.end(),*itL2);
		itL2++;
	}
*/
	/// versión compacta: insert por rangos
	L_aux.insert(L_aux.end(),L2.begin(),L2.end());
	return L_aux;
}

/* concatenar una lista LL de n sublistas usando insert: */

void concatenar_b(list<list<int>> &LL, list<int>& L){
	list<list<int>>::iterator itLL = LL.begin();
	
	while(itLL != LL.end()){
		list<int> &aux = *itLL;
		L.insert(L.end(), aux.begin(), aux.end());
		itLL++;
	}
	
	/// forma alternativa de resolver, desreferenciando:
	/* L.clear();
	list<list<int>>::iterator itB = LL.begin();
	while(itB != LL.end()){
	L.insert(L.end(), itB->begin(), itB->end());
	++itB; */
}
	
/* concatenar una lista LL de n sublistas usando splice: */

void concatenar_c(list<list<int>> &LL, list<int> &L){
	
	for(list<int> &Laux : LL){
	L.splice(L.end(), Laux);
	/// L.splice(L.end(), Laux, Laux.begin(), Laux.end());
	}
}
	
int main(int argc, char *argv[]) {
	list<int> L = { 1, 3, 2, 5 };
	list<int> L_aux = concatenar_a(L,L);
	print_list(L_aux);
	return 0;
}

