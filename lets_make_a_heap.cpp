#include <iostream>

using namespace std;

int heap[16] = {INT_MIN, 24, 27, 9, 13, 50, 42, INT_MIN};
int size = 7; //blank + 6 + blank

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//returns the index of the parent of the ith element
int parent(int i){
	return i / 2;
}

//returns the index of the left child of the ith element
int left_child(int i){
	return 2 * i;
}

//returns the index of the right child of the ith element
int right_child(int i){
	return 2 * i + 1;
}

//turns plain old array into a heap
void heapify(){
	//from last element to second to first element
	for(int i = size - 1; i > 1; i--){
	//replace with parent if parent is bigger
		if(heap[i] < heap[parent(i)]){
			swap(heap[i], heap[parent(i)]);
		}
	}
}

int min_value(){
	return heap[1];
}

void remove_min(){
	//replace min with rightmost element at the bottom (last element)
	heap[1] = heap[size - 1];
	size--;
	//trickle this down
	int i = 1;
	while(size > left_child(i)){
		//if one child
		if(size <= right_child(i)){
			//replace with the left child if greater than
			if(heap[i] > heap[left_child(i)]){
				swap(heap[i], heap[left_child(i)]);
				i = left_child(i);
			}
			else{
				break;
			}
		}
		//if two children
		else{
			//replace with the smaller child
			int mindex;
			if(heap[left_child(i)] < heap[right_child(i)]){
				mindex = left_child(i);
			}
			else{
				mindex = right_child(i);
			}
			if(heap[i] > heap[mindex]){
				swap(heap[i], heap[mindex]);
				i = mindex;
			}
			else{
				break;
			}
		}
	}
}

void insert(int value){
	//insert into last spot
	heap[size] = value;

	//trickle up
	int i = size;
	while(parent(i) > 0){
		//if parent is bigger replace
		if(heap[parent(i)] > heap[i]){
			swap(heap[parent(i)], heap[i]);
			i = parent(i);
		}
		else{
			break;
		}
	}

	size++;
}

void print_heap(){
	for(int i = 1; i < size; i++){
		cout << i << ":\t" << heap[i] << endl;
	}	
}

int main(){
	
	//Let's turn this into a min heap array
	heapify();
	cout << "Heaify" << endl;
	print_heap();

	cout << "Get Min" << endl;
	cout << min_value() << endl;

	cout << "Remove Min" << endl;
	remove_min();
	print_heap();

	cout << "Insert 2" << endl;
	insert(2);
	print_heap();

	cout << "Insert 15" << endl;
	insert(15);
	print_heap();

	cout << "Heap Sort!" << endl;
	while(size > 1){
		cout <<  min_value() << endl;
		remove_min();
	}

}