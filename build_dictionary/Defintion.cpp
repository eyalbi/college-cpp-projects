#include "Defintion.h"

Definition::~Definition()
{
	for (int i = ZERO; i < Number_d; i++) {
		Defanitions[i]->~String();
	}
	delete[] Defanitions;

}

Definition & Definition::operator=(const Definition &Rdeff)
{
	if (this != &Rdeff) {

		if (Defanitions == NULL) {
			Defanitions = new String*[Rdeff.Number_d];
		}
		else {
			for (int i = 0; i < Number_d; i++) {
				delete Defanitions[i];

			}
			delete[] Defanitions;
			Defanitions = new String*[Rdeff.Number_d];
		}
		int i;
		word = Rdeff.word;
		Number_d = Rdeff.Number_d;
		for (i = ZERO; i < Number_d; i++) {
			Defanitions[i] = new String;
			*(Defanitions[i]) = *(Rdeff.Defanitions[i]);
		}


	}
	return *this;
}

bool Definition::operator==(const Definition &Rdeff) const
{
	if (word != Rdeff.word) {
		return false;
	}
	return true;
}
Definition& Definition::operator-=(int index)
{
	if (index > ZERO && index <= Number_d) {
		Definition temp;
		int i, j = ZERO;
		temp.word = word;
		temp.Number_d = Number_d - 1;
		temp.Defanitions = new String*[temp.Number_d];
		for (i = ZERO; i < Number_d; i++) {
			if (index - 1 != i) {
				temp.Defanitions[j] = new String;
				*temp.Defanitions[j] = *Defanitions[i];
				j++;
			}
		}

		*this = temp;

	}
	return *this;
}

Definition & Definition::operator+=(const String& hagdra)
{
	bool flag = 1;
	for (int i = ZERO; i < Number_d; i++) {
		if (*(Defanitions[i]) == hagdra) {
			flag = ZERO;
		}
	}
	if (flag) {
		Definition temp;
		int i;
		temp = *this;
		for (int i = 0; i < Number_d; i++) {
			delete Defanitions[i];
		}
		delete[] Defanitions;
		Number_d = temp.Number_d + 1;
		Defanitions = new String*[Number_d];
		for (i = ZERO; i < temp.Number_d; i++) {
			Defanitions[i] = new String;
			*(Defanitions[i]) = *(temp.Defanitions[i]);
		}
		Defanitions[i] = new String;
		*(Defanitions[i]) = hagdra;

	}

	return *this;
}

String & Definition::operator[](int index)
{
	if (index > ZERO && index <= Number_d) {
		return *(Defanitions[index - 1]);
	}
	else {
		cout << "invalid index" << endl;
		exit(1);
	}
}

bool Definition::InDefanition(const String & Hagdra, int index)
{
	for (int i = ZERO; i < index; i++) {
		if (Hagdra == *Defanitions[i]) {
			cout << "this definition is allready exist to this specfic word please try again" << endl;
			return true;
		}
	}
	return false;
}

ostream & operator<<(ostream & out, const Definition & deff)
{
	cout << deff.word << ':' << endl;
	for (int i = ZERO; i < deff.Number_d; i++) {
		cout << i + 1 << ':';
		cout << *((deff.Defanitions)[i]) << endl;
		cout << endl;
	}
	return out;
}

istream & operator>>(istream & input, Definition & deff)
{
	int i = ZERO;
	cout << "enter a word for the dictionary" << endl;
	cin >> deff.word;
	cout << "enter number of definitions you desire\n";
	cin >> deff.Number_d;
	getchar();
	if (deff.Number_d > ZERO) {
		if (deff.Defanitions == NULL) {
			deff.Defanitions = new String*[deff.Number_d];
		}
		else {
			deff.~Definition();
			deff.Defanitions = new String*[deff.Number_d];
		}
		cout << "enter definition number " << i + 1 << endl;
		(deff.Defanitions)[i] = new String;
		cin >> *((deff.Defanitions)[i]);
		for (int i = 1; i < deff.Number_d; i++) {
			do {
				cout << "enter definition number " << i + 1 << endl;
				(deff.Defanitions)[i] = new String;
				cin >> *((deff.Defanitions)[i]);
			} while (deff.InDefanition(*((deff.Defanitions)[i]), i) == true);
		}
	}
	return input;
}

