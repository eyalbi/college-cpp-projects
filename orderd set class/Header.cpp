#include "Header.h"
#include <iostream>
#define ZERO 0
#define ONE 1
 void OrderedSet:: Sort_G (int * group, int size)
{
	while (Orderd_G(group, size) == false)
	{


		for (int i = ONE; i < size; i++) {
			if (group[i] < group[i - ONE]) {
				int temp = group[i];
				group[i] = group[i - ONE];
				group[i - ONE] = temp;
			}
		}

	}
}

bool OrderedSet::Orderd_G(int *group, int size)
{
	for (int i = ONE; i < size; i++) {
		if (group[i] < group[i - ONE]) {
			return false;
		}
	}
	return true;
	
}

int OrderedSet::ReturningValue(int * group, int size)
{
	int ReturnV = ZERO;
	for (int i = ZERO; i < size; i++) {
		for (int j = i + ONE; j < size; j++) {
			if (group[i] == group[j]) {
				ReturnV ++;
			}
		}
	}
	return ReturnV;
}

bool OrderedSet::inArray(int *group, int size, int num )
{
	for (int i = ZERO; i < size; i++) {
		if (group[i] == num) {
			return true;
		}
	}
	return false;
}

int OrderedSet::SameValues(OrderedSet obj)
{
	int i ,*Tgroup = obj.Get_Group(),Tsize = obj.Get_Size(), count = ZERO;
	for (i = ZERO; i < Size; i++) {
		for (int j = ZERO; j < Tsize; j++) {
			if (Group[i] == (Tgroup)[j])
				count++;
		}
	}
	return count;
}

OrderedSet::OrderedSet(int *group, int size)
{
	int count = ReturningValue(group, size);
	if(count == ZERO) {
		Sort_G(group , size);
		Group = group;
		Size = size;
	}
	else {
		Size = size - count;
		int j = ONE;
		Group = new int[Size];
		Group[ZERO] = group[ZERO];
		for (int i = ONE; i < size; i++) {
			if (inArray(Group, i , group[i]) == false) {
				Group[j++] = group[i];
			}
		}
		Sort_G(Group, size - count);
	}
}



OrderedSet::OrderedSet(const OrderedSet & obj)
{
	Size = obj.Size;
	Group = new int[Size];
	for (int i = ZERO; i < Size; i++) {
		Group[i] = (obj.Group)[i];
	}
}

bool OrderedSet::Contain(int num)
{
	for (int i = ZERO; i < Size; i++) {
		if (Group[i] == num)
			return true;
	}
	return false;
}

void OrderedSet::ChangeGroup(int * group, int size)
{
	if ((ReturningValue(group, size) == ZERO) && Orderd_G(group, size)) {
		delete[] Group;
		Group = group;
		Size = size;
	}
	else {
		cout << "the array isn't a group" << endl;
	}
}

OrderedSet OrderedSet::Def(OrderedSet obj)
{
	int j = ZERO;
	OrderedSet def;
	def.Size = Size - SameValues(obj);
	def.Group = new int[def.Size];
	for (int i = ZERO; i < Size; i++) {
		if (obj.Contain((Group)[i]) == false) {
			(def.Group)[j++] = Group[i];
		}
	}
	return def;
}

OrderedSet OrderedSet::intersect(OrderedSet obj)
{
	int c = ZERO;
	OrderedSet inter;
	if (obj.Size == ZERO) {
		inter.Group = NULL;
		inter.Size = ZERO;
	}
	else {
		inter.Size = SameValues(obj);
		inter.Group = new int[inter.Size];
		for (int i = ZERO; i < Size; i++) {
			for (int j = ZERO; j < obj.Size; j++) {
				if (Group[i] == (obj.Group)[j]) {
					(inter.Group)[c++] = Group[i];
				}

			}
		}
	}
return inter;
}

OrderedSet OrderedSet::Union(OrderedSet obj)
{
	int c = ZERO,j = ZERO,i;
	OrderedSet Union;
	Union.Size = Size + obj.Size - SameValues(obj);
	Union.Group = new int[Union.Size];
	for (i = ZERO; i < Size; i++) {
		(Union.Group)[i] = Group[j++];
	}
	for (j = ZERO; j < obj.Size; j++) {
		if (Contain((obj.Group)[j]) == false) {
			(Union.Group)[i++] = (obj.Group)[j];
		}
	}
	Sort_G(Union.Group, Union.Size);
	return Union;
}

bool OrderedSet::EqualGroups(OrderedSet obj)
{
	int i, j ,*Tgroup = obj.Get_Group();
	for (i = ZERO; i < Size; i++) {
		j = i;
			if (Group[i] != Tgroup[j]) {
				return false;
			}
	}
	return true;
}

bool OrderedSet::EmptyGroup()
{
	if (Size == ZERO) {
		return true;
	}
	return false;
}

bool OrderedSet::Contain(OrderedSet obj)
{
	if (obj.Size == ZERO) {
		return true;
	}
	for (int i = ZERO; i < obj.Size ; i++) {
		if (Contain((obj.Group)[i]) == false) {
			return false;
		}
	}
	return true;
}

void OrderedSet::PrintGroup()
{
	if (EmptyGroup() == true) {
		cout << '{' << '}' << endl;
	}
	else {
		cout << '{';
		for (int i = ZERO; i < Size; i++) {
			if (i == Size - ONE) {
				cout << Group[i] << '}' << endl;
			}
			else {
				cout << Group[i] << ',';
			}
		}
	}
}