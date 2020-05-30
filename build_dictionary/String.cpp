#include "String.h"

String::String(char *Ustr)
{
	*this = Ustr;

}

String& String::operator=(char * string1)
{
	if (str != NULL) {
		delete[]str;

	}
	StrSize = strlenth(string1);
	str = new char[StrSize + 1];
	int i;
	for (i = ZERO; i < StrSize; i++) {
		str[i] = string1[i];
	}
	str[i] = '\0';
	this->FixStr();
	return *this;
}

String& String::operator=(const String& Rstr)
{
	if (str != NULL) {
		delete[] str;
		str = new char[(Rstr.StrSize) + 1];
		StrSize = Rstr.StrSize;
	}
	else {
		str = new char[(Rstr.StrSize) + 1];
		StrSize = Rstr.StrSize;
	}
	*this = Rstr.str;
	this->FixStr();
	return *this;
}

bool String::operator==(const String & Rstr) const
{
	if (StrSize == Rstr.StrSize) {
		for (int i = ZERO; i < StrSize; i++) {
			if (str[i] != (Rstr.str)[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}

}

bool String::operator!=(const String &Rstr) const
{
	if (*this == Rstr) {
		return false;
	}
	return true;
}

String & String::operator-=(char letter)
{
	if (StrSize == ZERO) {
		return *this;
	}
	int tempSize = StrSize;
	int count = ZERO;
	int i, j = ZERO;
	for (i = ZERO; (this->str)[i] != '\0'; i++) {
		if (str[i] == letter) {
			count++;
		}
	}
	if (count > ZERO) {
		char* temp = str;
		str = new char[tempSize - count + 1];
		StrSize -= count;
		for (i = ZERO; temp[i] != '\0'; i++) {
			if (temp[i] != letter) {
				str[j++] = temp[i];
			}
		}
		str[j] = '\0';
		delete[]temp;
	}
	this->FixStr();
	return *this;
}

String & String::operator+=(char letter)
{
	int i;
	char* temp = str;
	int Tsize = StrSize;
	StrSize++;
	str = new char[StrSize + 1];
	for (i = ZERO; i < Tsize; i++) {
		str[i] = temp[i];
	}
	str[i++] = letter;
	str[i] = '\0';
	delete[] temp;
	this->FixStr();
	return *this;
}

char & String::operator[](int index)
{
	if (index >= ZERO && index < StrSize) {
		return str[index];
	}
	else {
		cout << "invalid index" << endl;
		exit(1);
	}
}

void String::FixStr()
{
	this->FixSpaces();
	this->Fix_Cases();
	this->Fix_Pisuk();

}

void String::FixSpaces()
{
	int count = ZERO;
	int i, j = ZERO;
	for (i = 0; i < StrSize; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') {
			count++;
		}
	}
	if (count > ZERO) {
		char *temp = str;
		str = new char[StrSize - count + 1];
		int tsize = strlenth(temp);
		StrSize -= count;
		for (i = ZERO; i < tsize; i++) {
			if (temp[i] == ' ' && temp[i + 1] == ' ') {
				continue;
			}
			else {
				str[j++] = temp[i];
			}
		}
		delete[] temp;
		str[j] = '\0';
	}

}

void String::Fix_Cases()
{
	int i;
	if ((str[ZERO] >= 'a' && str[ZERO] <= 'z')) {
		str[ZERO] -= CHARDIFF;
	}
	for (i = 1; i < StrSize; i++) {
		if (str[i - 1] == '.' && str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= CHARDIFF;
		}
		if (str[i - 1] != '.' && str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += CHARDIFF;
		}

	}

}

void String::Fix_Pisuk()
{
	int i, j = ZERO, count = ZERO;
	for (i = ZERO; i < StrSize; i++) {
		if (str[i] == '.' || str[i] == ',' || str[i] == ':') {
			if (str[i + 1] == ' ') {
				str[i + 1] = '$';
				count++;
			}
			if (str[i - 1] == ' ') {
				count++;
			}
		}

	}
	if (count > ZERO) {
		char* temp = str;
		str = new char[StrSize - count + 1];
		StrSize -= count;
		for (i = ZERO; temp[i] != '\0'; i++) {
			if ((temp[i] == ' ' && (temp[i + 1] == ',' || temp[i + 1] == ':' || temp[i + 1] == '.')) || temp[i] == '$') {
				continue;
			}
			else {
				str[j++] = temp[i];
			}

		}
		delete[] temp;
		str[j] = '\0';
	}

}

bool String::strcompare(const String & Rstr) const
{
	if (str[0] == Rstr.str[0]) {
		for (int i = 1; i < StrSize; i++) {
			if (str[i] == (Rstr.str)[i]) {
				continue;
			}
			else if (str[i] < Rstr.str[i]) {
				return true;
			}
			return false;
		}
	}
	else if (str[0] > Rstr.str[0]) {
		return false;
	}
	else if (str[0] < Rstr.str[0]) {
		return true;
	}

}

int strlenth(char * str)
{
	int count = ZERO;
	for (int i = ZERO; str[i] != '\0'; i++) {
		count++;
	}

	return count;
}

ostream & operator<<(ostream & out, const String & str)
{
	for (int i = ZERO; (str.str)[i] != '\0'; i++) {
		out << (str.str)[i];
		if ((str.str)[i] == '.') {
			cout << endl;
		}

	}
	return out;
}

istream & operator>>(istream & input, String & str)
{
	int i;
	char word[200];
	cin.getline(word, 200);
	str.StrSize = strlenth(word);
	if (str.str != NULL) {
		delete[] str.str;
		str.str = new char[str.StrSize + 1];
	}
	else {
		str.str = new char[str.StrSize + 1];
	}
	for (i = ZERO; word[i] != '\0'; i++) {
		(str.str)[i] = word[i];
	}
	(str.str)[i] = '\0';
	str.FixStr();
	return input;
}
