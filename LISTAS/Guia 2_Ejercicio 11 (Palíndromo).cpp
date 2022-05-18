#include <iostream>
#include <list>
#include <cstring>
using namespace std;

bool is_palindromo(char* S){
	list<char>L;
	int f = strlen(S);
	for(int i=0;i<f;i++) { 
		if (S[i] != ' '){
			L.push_back(S[i]);
		}
	}
	
	auto itB = L.begin();
	auto itE = L.end();
	--itE;
	
	while(itE != itB){
		if(*itE != *itB) return false;
		if(*itE == *itB){
			++itB;
			--itE;
		}
	}
	
	return true;
}

int main() {
	
	if(is_palindromo((char*)"rar")){
		cout<<"es palindromo";
	}else{
		cout<<"no es palindromo";
	}
	return 0;
}







