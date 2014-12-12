#include <iostream>

using namespace std;

bool array[3];


bool hash1(int value){
	return value % 17 > 8;
}

bool hash2(int value){
	return value % 23 > 11;
}

bool hash3(int value){
	return value % 7 > 3;
}

void insert(int value){
	if(hash1(356)) array[0] += true;	
	if(hash2(356)) array[1] += true;	
	if(hash3(356)) array[2] += true;	
}

bool is_here(int value){
	return 
	(
		hash1(value) == array[0]
		&&
		hash2(value) == array[1]
		&&
		hash3(value) == array[2]
	);
}

int main(){
	for(int i = 0; i < 16; i++){
		array[i] = false;
	}

	//insert number 365;
	insert(356);
	int count_not_here = 0;
	int count_here = 0;
	for(int i = 0; i < 356; i++){
		if(is_here(i)){
			count_here++;
		}
		else{
			count_not_here++;
		}
	}

	cout << "Here: " << count_here << endl;
	cout << "Not Here: " << count_not_here << endl;


}