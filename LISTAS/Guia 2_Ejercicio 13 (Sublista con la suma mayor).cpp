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
	
list<int> max_sublist(list<int> &L){
	int sum_final = 0;
	list<int> L_final;
	
	for(auto it = L.begin(); it != L.end(); it++){
		auto it_2 = it;
		++it_2;
		int sum = *it;
		
		while(it_2 != L.end()){
			sum += *it_2;
			
			if(sum > sum_final){
				sum_final = sum;
				auto it_3 = it_2;
				++it_3; // porque el insert no toma el último iterador dado.
				L_final.clear();
				L_final.insert(L_final.begin(),it,it_3); 
				
			}
			++it_2;
		}
	}
	return L_final;
}

int main() {
	list<int>L = {-1,1,2,-3,3};
	list<int>L_aux = max_sublist(L);
	print_list(L_aux);
	return 0;
}







