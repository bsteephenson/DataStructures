#include <iostream>
using namespace std;

//This one uses linear probing to deal with collisions

int size = 16;

struct Cell{
	int key;
	string value;
	bool is_empty;
	bool deleted;
	Cell(){
		is_empty = true;
		deleted = false;
	}
	void populate(int key, string value){
		this->key = key;
		this->value = value;
		this->is_empty = false;
		this->deleted = false;
	}
};

Cell hashtable[16];

int hash_function(int key){
	int a = 1;
	int b = 2;
	int p = 29;
	int n = size;
	int index =  (a * key + b) % p % n;
	if(index < 0){
		index = index * (0-1);
	}
	return index;
}

void insert(int key, string value){
	int index = hash_function(key);
	if(hashtable[index].is_empty){
		hashtable[index].populate(key, value);
	}
	else{
		cout << "Collision at key " << key << endl;
		index++;
		while(index < size){
			if(hashtable[index].is_empty){
				hashtable[index].populate(key, value);
				return;
			}
			index++;
		}
	}
}

string find(int key){
	int index = hash_function(key);
	while(index <  size){
		if(hashtable[index].is_empty){
			return "";
		}
		else{
			if(hashtable[index].key == key){
				return hashtable[index].value;
			}
		}
		index++;
	}
	return "";
}

void print_table(){
	for(int i = 0; i < size; i++){
		cout << i << ": " << hashtable[i].value << endl;
	}
}

int main(){

	for(int i = 10; i < 100; i = i + 9){
		insert(i, "Hello World" + to_string(i));
	}

	print_table();
	cout << "Finding" << endl;
	for(int i = 10; i < 100; i = i + 9){
		cout << i << ": " << find(i) << endl;
	}
}