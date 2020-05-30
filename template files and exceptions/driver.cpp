#include "MyArr.h"
#include <typeinfo>
void Buildarr(float** arr, int& size,float value);     //a function that builds an array to send to ctor
int main() {
	try {
		MyArr<Student> studentArr;								//initalize student and floats arrays from files
		MyArr<Student> studentArr2;
		ifstream input("arrstud1.txt");
		ifstream input2("arrstud2.txt");
		ifstream input3("arrfloat1.txt");
		ifstream input4("arrfloat2.txt");
		if (!input || !input2 || !input3 || !input4) {
			throw "can't open file";
		}
		string fname, lname, id;
		int day, month, year, grades;
		float average;
		while (input >> fname >> lname >> day >> month >> year >> id >> grades >> average) {
			Student temp(fname, lname, id, day, month, year, grades, average);
			studentArr += temp;
		}
		while (input2 >> fname >> lname >> day >> month >> year >> id >> grades >> average) {
			Student temp(fname, lname, id, day, month, year, grades, average);
			studentArr2 += temp;
		}
		float * arr = NULL,value;
		int size = 0;
		while (input3 >> value) {
			Buildarr(&arr, size, value);
		}
		MyArr<float> floatarr1(arr, size);
		size = 0;
		while (input4 >> value) {
			Buildarr(&arr, size, value);
		}
		MyArr<float> floatarr2(arr, size);
		float ftemp;																				//adds data to each array using += operator
		cout << "float array 1: " << endl;
		cout << floatarr1;
		cout << "enter a value to add to the first float array" << endl;
		cin >> ftemp;
		floatarr1 += ftemp;
		cout << "float array 1 after change: " << endl;
		cout << floatarr1;
		cout << "float array 2: " << endl;
		cout << floatarr2;
		cout << "enter a value to add to the second float array" << endl;
		cin >> ftemp;
		floatarr2 += ftemp;
		cout << "float array 2 after change: " << endl;
		cout << floatarr2;
		cout << "************************************" << endl;
		cout << "student array 1 before change: " << endl;
		cout << studentArr;
		cout << "enter student data to add to the array 1" << endl;
		cout << "enter first name" << endl;
		cin >> fname;
		cout << "enter last name" << endl;
		cin >> lname;
		cout << "enter student id(9 digit)" << endl;
		cin >> id;
		cout << "enter date of birth (day month year)" << endl;
		cin >> day >> month >> year;
		cout << "enter grade amount" << endl;
		cin >> grades;
		cout << "enter average" << endl;
		cin >> average;
		Student stemp(fname, lname, id, day, month, year, grades, average);
		studentArr += stemp;
		cout << "student array 1 after change: " << endl;
		cout << studentArr;
		cout << "********************************************" << endl;
		cout << "student array 2 data: " << endl;
		cout << studentArr2;
		cout << "enter student data to add to the array 2" << endl;
		cout << "enter first name" << endl;
		cin >> fname;
		cout << "enter last name" << endl;
		cin >> lname;
		cout << "enter student id(9 digit)" << endl;
		cin >> id;
		cout << "enter date of birth (day month year)" << endl;
		cin >> day >> month >> year;
		cout << "enter grade amount" << endl;
		cin >> grades;
		cout << "enter average" << endl;
		cin >> average;
		Student stemp1(fname, lname, id, day, month, year, grades, average);
		studentArr2 += stemp1;
		cout << "student array 2 after change: " << endl;
		cout << studentArr2;
		cout << "**********************************" << endl;
		cout << "i will remove student with 337687097 from student array 2" << endl;        //remove data using -= operator
		Student temp3("ss", "ss", "337687097", 1, 2, 1994, 4, 95.3);
		studentArr2 -= temp3;
		cout << studentArr2;
		cout << "float array 1 max: ";														//prints min and max value from each array
		cout << *(floatarr1.findmax()) << endl;
		cout << "float array 2 max: ";
		cout << *(floatarr2.findmax()) << endl;
		cout << "student array 1 max: " << endl;;
		cout << *(studentArr.findmax());
		cout << "student array 2 max: " << endl;;
		cout << *(studentArr2.findmax()) << endl;;
		cout << "****************************" << endl;
		cout << "float array 1 min: ";
		cout << *(floatarr1.findmin()) << endl;
		cout << "float array 2 min: ";
		cout << *(floatarr2.findmin()) << endl;
		cout << "student array 1 min: " << endl;;
		cout << *(studentArr.findmin());
		cout << "student array 2 min: " << endl;;
		cout << *(studentArr2.findmin()) << endl;
		cout << "****************************" << endl;
		if (floatarr1.is_sorted()) {															//check if each array is sorted
			cout <<"float array 1 is sorted !"<<endl;
		}
		else {
			cout << "float array 1 is not sorted !" << endl;
		}
		if (floatarr2.is_sorted()) {
			cout << "float array 2 is sorted !" << endl;
		}
		else {
			cout << "float array 2 is not sorted !" << endl;
		}
		if (studentArr.is_sorted()) {
			cout << "student array 1 is sorted !" << endl;
		}
		else {
			cout << "student array 1 is not sorted !" << endl;
		}
		if (studentArr2.is_sorted()) {
			cout << "student array 2 is sorted !" << endl;
		}
		else {
			cout << "student array 2 is not sorted !" << endl;
		}
		delete[] arr;
	
}
	catch (const char * msg) {															//catch block for exeptions
		cout << "an error has occured" << endl;
		cout << msg << endl;
	}
	catch (...) {
		cout << "an unknown error has occured" << endl;
	}
	return 0;
}

void Buildarr(float** arr, int& size,float value) {					//build array from file (value->from file)
	if (size == 0) {
		*arr = new float(value);
		size++;
	}
	else {
		float* temp = *arr;
		size++;
		int i;
		*arr = new float[size];
		for (i = 0; i < size - 1; i++) {
			(*arr)[i] = temp[i];
		}
		(*arr)[i] = value;
		if (size - 1 == 1) {
			delete temp;
		}
		else {
			delete[] temp;
		}
	}
}




