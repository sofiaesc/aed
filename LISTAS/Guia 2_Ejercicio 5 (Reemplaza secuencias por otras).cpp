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

	void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP){
		for(auto it = L.begin();it != L.end();it++){
			auto it2 = it;
			bool flag = false;
			for(auto it_seq=SEQ.begin();it_seq!=SEQ.end();it_seq++){
				if(*it2 == *it_seq && it2 != L.end()){
					flag = true;
					it2++;
				}else{
					flag = false; 
					
				}
			}
			if(flag){ 
				it =  L.erase(it, it2--);
				L.insert( it , REEMP.begin(), REEMP.end()); 	
				advance( it , REEMP.size()-2); 
			} 
		}
	}

/*
	void reemplaza(list<int> &L, list<int>& SEQ, list<int> &REEMP){
		list<int>::iterator it = L.begin();
		list<int>::iterator itSEQ = SEQ.begin();
		while(it!=L.end()){
			list<int>::iterator itIni = it;
			while(itSEQ != SEQ.end() && it!=L.end()){
				if(*it==*itSEQ){
					itSEQ++;
					it++;
				}else{
					itSEQ = SEQ.begin();
					it++;
					itIni = it;
				}	
			}
			if(itSEQ==SEQ.end()){
				it = L.erase(itIni,it);
				it = L.insert(it,REEMP.begin(), REEMP.end());
				advance(it,REEMP.size());
				itSEQ = SEQ.begin();
			}
		}	
	}
*/
	

int main(int argc, char *argv[]) {
	list<int>L = {1,2,3,4,5,6,2,3,4};
	list<int>S = {2,3,4};
	list<int>R = {9,10,11};
	reemplaza(L,S,R);
	print_list(L);
	return 0;
}

