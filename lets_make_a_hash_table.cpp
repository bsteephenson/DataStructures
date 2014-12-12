#include <iostream>
using namespace std;

//A hash table that uses Chaining


int size = 16;

struct Node{
	int key;
	string value;
	Node *next;
	Node(int key, string value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
};

Node *hashtable[16];

int hash_function(int key){
	int a = 100;
	int b = 37;
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
	Node *current = hashtable[index];
	if(current == NULL){
		hashtable[index] = new Node(key, value);
	}
	else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = new Node(key, value);
	}
}

void print_table(){
	for(int i = 0; i < size; i++){
		cout << i << ": ";
		Node * current = hashtable[i];
		while(current != NULL){
			cout << current->value << " . ";
			current = current->next;
		}
		cout << endl;
	}
}

string find(int key){
	int index = hash_function(key);
	Node * current = hashtable[index];
	if(current == NULL){
		return "";
	}
	else{
		while(current != NULL){
			if(current->key == key){
				return current->value;
				break;
			}
			else{
				current = current->next;
			}
		}
		return "";
	}
}

int main(){
	for(int i = 0; i < size; i++){
		hashtable[i] = NULL;
	}
	for(int i = 1; i < 200; i++){
		insert(i, "Hello World" + to_string(i));
	}
	print_table();

	cout << "Value at key 100: " << find(100) << endl;
}