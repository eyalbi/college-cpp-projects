#include "Dictionary.h"

Dictionary::~Dictionary()
{
	for (int i = ZERO; i < DictSize; i++) {
		delete Milon[i];
	}
	delete[] Milon;
}

Dictionary & Dictionary::operator=(const Dictionary &Rdic)
{
	if (Rdic.DictSize <= ZERO)
	{
		return *this;
	}
	if (this != &Rdic) {
		if (Milon == NULL) {
			DictSize = Rdic.DictSize;
			Milon = new Definition*[DictSize];
		}
		else {
			for (int i = ZERO; i < DictSize; i++) {
				delete Milon[i];
			}
			delete[] Milon;
			DictSize = Rdic.DictSize;
			Milon = new Definition*[DictSize];
		}
		for (int i = ZERO; i < DictSize; i++) {
			Milon[i] = new Definition;
			*Milon[i] = *Rdic.Milon[i];
		}
	}
	return *this;
}

bool Dictionary::operator==(const Dictionary &Rdic) const
{
	if (DictSize == Rdic.DictSize) {
		for (int i = ZERO; i < DictSize; i++) {
			if (*Milon[i] == *Rdic.Milon[i]) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

Dictionary & Dictionary::operator-=(int index)
{
	if (index > ZERO && index <= DictSize) {
		Dictionary temp;
		int j = ZERO;
		temp = *this;
		for (int i = ZERO; i < DictSize; i++) {
			delete Milon[i];
		}
		delete[] Milon;
		DictSize = temp.DictSize - 1;
		Milon = new Definition *[DictSize];
		for (int i = ZERO; i < temp.DictSize; i++) {
			if (index - 1 != i) {
				Milon[j] = new Definition;
				*Milon[j++] = *temp.Milon[i];
			}
		}
	}
	else {
		cout << "invalid index" << endl;
	}
	return *this;
}

Dictionary & Dictionary::operator+=(const Definition & NewHagdara)
{
	bool flag = 1;
	for (int i = ZERO; i < DictSize; i++) {
		if (*Milon[i] == NewHagdara) {
			flag = ZERO;
		}
	}
	if (flag) {
		int i;
		Dictionary temp;
		temp = *this;
		for (i = ZERO; i < DictSize; i++) {
			delete Milon[i];
		}
		delete[] Milon;
		DictSize = temp.DictSize + 1;
		Milon = new Definition*[DictSize];
		for (i = ZERO; i < temp.DictSize; i++) {
			Milon[i] = new Definition;
			*Milon[i] = *temp.Milon[i];
		}
		Milon[i] = new Definition;
		*Milon[i] = NewHagdara;
	}
	return *this;
}

Definition & Dictionary::operator[](int index)
{
	if (index > ZERO && index <= DictSize) {
		return *Milon[index - 1];
	}
	else {
		cout << "invalid index" << endl;
		exit(1);
	}
}

bool Dictionary::InMilon(const Definition &Hagdra, int index) const
{
	for (int i = ZERO; i < index; i++) {
		if (*Milon[i] == Hagdra) {
			cout << "this word is allready in the dictionary try again" << endl;
			return true;
		}
	}
	return false;
}

void Dictionary::FixDic()
{
	int i;
	do {
		for (i = ZERO; i < DictSize - 1; i++) {
			if (Milon[i]->word.strcompare(Milon[i + 1]->word) == false) {
				Definition temp;
				temp = *Milon[i];
				*Milon[i] = *Milon[i + 1];
				*Milon[i + 1] = temp;
			}
		}
	} while (this->DicIsFixed() == false);
}

bool Dictionary::DicIsFixed()
{
	for (int i = ZERO; i < DictSize - 1; i++) {
		if (Milon[i]->word.strcompare(Milon[i + 1]->word) == false) {
			return false;
		}
	}
	return true;
}

void Dictionary::SearchAndAdd(const String& word1)
{
	bool flag = ZERO;
	int index,i;
	for (i = ZERO; i < DictSize; i++) {
		if((*Milon[i]).word == word1){
			flag = 1;
			index = i;
		}
	}
	if (flag) {
		String temp;
		cout << "enter a new the definition" << endl;
		cin >> temp;
		*(Milon[index]) += temp;
	}
}

void Dictionary::SearchAndPrint(const String & deff) const
{
	bool flag = 1;
	for (int i = ZERO; i < DictSize; i++) {
		if ((*Milon[i]).word == deff) {
			cout << *(Milon[i]);
			flag = ZERO;
		}
	}
	if (flag) {
		cout << " there is no such word in the dictionary" << endl;
	}
}

void Dictionary::SearchEqualDeff()
{
	String temp;
	int i,j = ZERO;
	int flag = ZERO;
	for (i = ZERO; i < DictSize; i++) {
		for (j = ZERO; j < (*Milon[i]).Number_d; j++) {
			temp = *((*Milon[i]).Defanitions)[j];
			for (int k = i + 1; k < DictSize; k++) {
				for (int z = ZERO; z < (*Milon[k]).Number_d; z++) {
					if (temp == *((*Milon[k]).Defanitions)[z]) {
						if (flag == ZERO) {
							cout << *Milon[i] << *Milon[k];
						}
						else {
							cout << *Milon[k];
						}
						flag++;
					}
				}
			}
		}
	}
}

ostream & operator<<(ostream & out, const Dictionary & dic)
{
	for (int i = ZERO; i < dic.DictSize; i++) {
		cout << *(dic.Milon[i]);
	}
	return out;
}

istream & operator>>(istream & input, Dictionary & dic)
{

	if (dic.Milon != NULL) {
		for (int i = ZERO; i < dic.DictSize; i++) {
			delete dic.Milon[i];
		}
		delete[] dic.Milon;
	}
	cout << "how many words do you want in your dictionary" << endl;
	cin >> dic.DictSize;
	getchar();
	int i = ZERO;
	dic.Milon = new Definition*[dic.DictSize];
	dic.Milon[i] = new Definition;
	cin >> *dic.Milon[i];
	for (i = 1; i < dic.DictSize; i++) {
		do {
			dic.Milon[i] = new Definition;
			cin >> *dic.Milon[i];
		} while (dic.InMilon(*dic.Milon[i], i) == true);
	}
	dic.FixDic();
	return input;
}
