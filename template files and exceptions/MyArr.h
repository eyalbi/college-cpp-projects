#include "Student.h"


template <class T>	
class MyArr {															//template class witch reperesent an array
private:
	T* Arr;
	int size;
public:
	MyArr() : Arr(NULL), size(0) {};															//ctor's default for student type and parametrs for float type
	MyArr(T* arr, int size) {
		this->size = size;
		Arr = new T[size];
		for (int i = 0; i < size; i++) {
			Arr[i] = arr[i];
		}
	}
	void isType() {																//prints type name
		cout << "class name: " << typeid(T).name() << endl;;
	}
	T& operator [](int index) {													//index operator
		if (index < 0 || index > size) {
			throw "invalid array index";
		}
		return Arr[index];
	}
	MyArr& operator +=(const T& Temp) {					//+= operator deleting old memory and builds new one with an additional data
		if (size == 0) {
			Arr = new T(Temp);
			size++;
		}
		else {
			T* temp = Arr;
			size++;
			int i;
			Arr = new T[size];
			for (i = 0; i < size - 1; i++) {
				Arr[i] = temp[i];
			}
			Arr[i] = Temp;
			if (size - 1 == 1) {
				delete temp;
			}
			else {
				delete[] temp;

			}
		}
		return *this;
	}
	MyArr& operator -=(const T& Temp) {               //-= operator gets data and deleting it from the array
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (Arr[i] == Temp) {
				index = i;
			}
		}
		if (index == -1) {
			throw "this object doesn't exists in the array";
		}
		else {
			int k = 0;
			size--;
			T* temp;
			temp = Arr;
			Arr = new T[size];
			for (int i = 0; i < size + 1; i++) {
				if (i != index) {
					Arr[k++] = temp[i];
				}
			}
			if (size + 1 == 1) {
				delete temp;
			}
			else {
				delete[] temp;

			}
		}
		return *this;
	}
	friend ostream& operator <<  (ostream& out, MyArr& print) {       //prints the object
		print.isType();
		out << "Array size is: " << print.size << endl;
		for (int i = 0; i < print.size; i++) {
			out << print.Arr[i] << endl;
		}
		return out;
	};
	bool is_sorted() {                        //check if the array is sorted
		if (size == 0 || size == 1) {
			return true;
		}
		for (int i = 0; i < size - 1; i++) {
			if (Arr[i] > Arr[i + 1]) {
				return false;
			}
		}
		return true;
	}
	T* findmax() {                       //return max value pointer from array
		if (size == 0) {
			return NULL;
		}
		T max = Arr[0];
		int index = 0;
		int i;
		for (i = 1; i < size; i++) {
			if (Arr[i] > max) {
				max = Arr[i];
				index = i;
			}
		}
		return &(Arr[index]);
	}
	T* findmin() {														//return min value pointer from array
		if (size == 0) {
			return NULL;
		}
		T min = Arr[0];
		int index = 0;
		int i;
		for (i = 1; i < size; i++) {
			if (min > Arr[i]) {
				min = Arr[i];
				index = i;
			}
		}
		return &(Arr[index]);
	}
};

