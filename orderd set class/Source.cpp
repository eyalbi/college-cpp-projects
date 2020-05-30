#include "Header.h"
#include <iostream>
#define ZERO 0
#define ONE 1
int main() {				//תוכנית המציגה אתחול קבוצות מספרים שלמיםת חישוב חיתוכן ,הפרשן,איחודן 
	cout << "creating an orderset orderset1 with the following parmeters:\narr1 = {2,3,4,8,9,10,1,5,7,6}\nsize1 = 10" << endl;
	int arr1[10] = { 2,3,4,8,9,10,1,5,7,6 };
	int arr2[10] = { 2,3,4,-1 - 2,5,4,-3,1,-4,-5 };
	OrderedSet OS1(arr1, 10);
	cout << "printing orderset1:";
	OS1.PrintGroup();
	cout << "Creating an OrderedSet orderedSet2 with the following parameters :\narr2 = { 2,3,4,-1,- 2,5,4,-3,1,-4,-5 }\nsize2 = 10" << endl;
	OrderedSet OS2(arr2, 10);
	cout << "printing orderset2:";
	OS2.PrintGroup();
	cout << "Creating empty orderedSet orderedSet3 without parameters" << endl;
	OrderedSet OS3;
	cout << "printing orderset3:";
	OS3.PrintGroup();
	cout << "calculating the intersection of orderedSet1 and orderedSet2:" << endl;
	OrderedSet Intersection(OS1.intersect(OS2));
	Intersection.PrintGroup();
	cout << "calculating the intersection of orderedSet1 and orderedSet3:" << endl;
	OrderedSet I2(OS1.intersect(OS3));
	I2.PrintGroup();
	cout << "calculating the union of orderedSet1 and orderedSet2" << endl;
	OrderedSet U1(OS1.Union(OS2));
	U1.PrintGroup();
	cout << "calculating the union of orderedSet2 and orderedSet3" << endl;
	OrderedSet U2(OS2.Union(OS3));
	U2.PrintGroup();
	if (OS1.Contain(OS3)) {
		cout << "orderedSet1 contains orderedSet3" << endl;
	}
	else
	{
		cout << "orderedSet1 doesn't contains orderedSet3" << endl;
	}
	if (OS2.Contain(OS1) == false) {
		cout << "orderedSet2 doesn't contain orderedSet1" << endl;
	}
	else
	{
		cout << "orderedSet2 contains orderedSet1" << endl;
	}
	cout << "calculating the def of orderedSet1 - orderedSet2:" << endl;
	OrderedSet def(OS1.Def(OS2));
	def.PrintGroup();

	return ZERO;
}