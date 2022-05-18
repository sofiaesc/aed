#include <iostream>
#include <list>
using namespace std;

list<string> josephus(list<string>& nombres, int n){
	if(n <= 1) return nombres;
	
	auto it = nombres.begin();
	int cont = 0;
	list<string> L_aux;
	
	while(!nombres.empty()){
		cont++;
		if(it==nombres.end()){
			it=nombres.begin();
		}
		if(cont==n){
			L_aux.push_back(*it);
			it=nombres.erase(it);
			cont=0;
		}else{
			it++;
		}
	}
	return L_aux;
}	
	
	void show_list(list<string>& L) {
		cout<<"(";
		for(list<string>::iterator it=L.begin();it!=L.end();it++) {
			cout<<*it<<" ";
		}
		cout<<")";
	}
	

int main() {
	list<string> nombres = {"rolando", "jp", "nelson", "victoria", "maria", "pepe","pedro"};
	list<string> resultado = josephus(nombres,2);
	show_list(resultado);
	return 0;
}







