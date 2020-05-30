#include "Date.h"
template <class T>														//template func declarations
void SelectionSort(T Array[], int size);
template <class T>
void swap(T Array [], int index1, int index2);
template <class T>
void Print(T Array [] , int size);
int main() {												//main intilaize 2 array (int,date) and sorting them with template func
	int ArraySize,*array1,tempday,tempmount,tempyear;
	cout << "enter int array size" << endl;
	cin >> ArraySize;
	array1 = new int[ArraySize];
	for (int i = 0; i < ArraySize; i++) {
		cout << "enter int array number " << i + 1 << " :" << endl;
		cin >> array1[i];
	}
	cout << "array before change: " << endl;
	Print(array1, ArraySize);
	cout << "array after change: " << endl;
	SelectionSort(array1, ArraySize);
	Print(array1, ArraySize);
	srand(time(NULL));
	Date array2[5];						//intiliazie date array with ctor randomly in size = 5.. if you want to change only change size
	cout << "array before change: " << endl;
	Print(array2, 5);
	cout << "array after change: " << endl;
	SelectionSort(array2, 5);
	Print(array2, 5);
	
	return 0;
}
template <class T>
void SelectionSort(T Array[] , int size) {													//template func that sorting array with selction sort method
	int i,j,min_index;
	for (i = 0; i < size; i++) {
		min_index = i;
		for (j = i + 1; j < size; j++) {
			if (Array[j] < Array[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(Array, i, min_index);
		}
	}
}
template <class T>
void swap(T Array [] , int index1,int index2) {                           //template func to swap to arrays values with given array and index
	T temp;
	temp = Array[index1];
	Array[index1] = Array[index2];
	Array[index2] = temp;
}
template <class T>
void Print(T Array[], int size) {					//template func to print arrays
	cout << "{";
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << Array[i];
		}
		else {
			cout << Array[i] << ", ";

		}
	}
	cout << "}" << endl;
}