#include "Digit.h"


bool Digit::InArray(int num, int index, Digit array[4])
{
	for (int i = ZERO; i < index; i++) {
		if (num == array[i].value) {
			return true;
		}
	}
	return false;
}
	

bool Digit::DEqual(const Digit & TDigit) const
{
	if (value == TDigit.value) {
		return true;
	}
	return false;
}

void Digit::Set_Digit(int num)
{
	if(num > ZERO && num <= 9)
	value = num;
}
