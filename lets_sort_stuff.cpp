#include <iostream>

using namespace std;

int SIZE = 6;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void print_array(int * array){
	for(int i = 0; i < SIZE; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int * insertion_sort(int array[]){
	for(int i = 1; i < SIZE; i++){
		//if ith is less than i-1th
		int index = i;
		while(array[index - 1] > array[index]){
			swap(array[index - 1], array[index]);
			index--;
		}
	}
	return array;
}

int * selection_sort(int array[]){
	for(int i = 0; i < SIZE; i++){
		//find the mindex in the rest of the array
		int mindex = i;
		for(int j = i; j < SIZE; j++){
			if(array[mindex] > array[j]){
				mindex = j;
			}
		}
		swap(array[mindex], array[i]);
	}
	return array;
}

int * shell_sort(int array[]){
	for(int k = SIZE / 2; k > 0; k = k / 2){
		for(int i = k; i < SIZE / k; i++){
			int index = i;
			while(array[index - k] > array[index]){
				swap(array[index - k], array[index]);
				index = index - k;
			}
		}
	}
	return array;
}


int main(){
	
	cout << "Insertion Sort" << endl;
	int array[6] = {9, 24, 27, 13, 50, 42};
	print_array(insertion_sort(array));

	cout << "Selection Sort" << endl;
	int array2[6] = {24, 27, 9, 13, 50, 42};
	print_array(selection_sort(array2));

	cout << "Shell Sort" << endl;
	int array3[6] = {9, 24, 27, 13, 50, 42};
	print_array(shell_sort(array3));


}