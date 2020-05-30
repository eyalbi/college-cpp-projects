#include "Number.h"
#include <ctime>
Number::Number()
{
	for (int i = ZERO; i < 4; i++) {
		(number[i]).Set_Digit(ZERO);
	}
}

void Number::randomise()
{
	int temp;
	srand(time(NULL));
	(number)[ZERO].value = (rand() % 9) + 1;
	for (int i = 1; i < 4; i++) {
		do
		{
			temp = (rand() % 9) + 1;
			if (number[i].InArray(temp, i, number) == false) {
				number[i].value = temp;
			}
			
		} while (number[i].InArray(temp, i, number) == true);
	}
}
void Number::EnterValue()
{
	int num,ones,tens ,hund,thous;
	
	int i = ZERO;
	do
	{
		if (i == ZERO) {
			cout << "please enter a 4 digit integer without returning values or 0" << endl;
			cin >> num;
		}
		if (i > ZERO) {
			cout << "invalid input try agian" << endl;
			cin >> num;
		}
		ones = num % 10;
		tens = (num / 10) % 10;
		hund = (num / 100) % 10;
		thous = (num / 1000) % 10;
		number[ZERO].value = thous;
		number[1].value = hund;
		number[2].value = tens;
		number[3].value = ones;
		i++;
	} 
	while (ones == ZERO || ones == tens || ones == hund || ones == thous || tens == ZERO || tens == hund || tens == thous || hund == ZERO || hund == thous || thous == ZERO || num < 1000 || num > 9999 ); 
}

int Number::Get_Value(int num)
{
	if (num < 0 || num > 3) {
		return -1;
	}
	else {
		return (number)[num].value;
	}
}

void Number::PrintNumber()
{
	int num = 1000 * (number)[ZERO].value + 100 * (number)[1].value + 10 * (number)[2].value + (number)[3].value;
	cout << num ;
}
