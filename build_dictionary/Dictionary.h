#include "Defintion.h"

class Dictionary{								//class declaration
private:
	int DictSize;
	Definition** Milon;
public:
	Dictionary() :DictSize(ZERO), Milon(NULL) {};					//default ctour
	~Dictionary();													//dtour that releases heap memory
	Dictionary & operator = (const Dictionary&);						//operator overloading
	bool operator == (const Dictionary&)const;
	friend ostream& operator <<(ostream&out, const Dictionary&);
	friend istream& operator >>(istream&input, Dictionary& dic);
	Dictionary &  operator -=(int index);
	Dictionary & operator +=(const Definition&);
	Definition& operator [](int index);
	bool InMilon(const Definition&,int index)const;						//checks if a dictionary has a specific word defanition up to a given index
	void FixDic();														//order dictionary alphabeticly
	bool DicIsFixed();
	void SearchAndAdd(const String&);									//add a new defanition to an existing word in the dictionary			
	void SearchAndPrint(const String&)const;								//searchin for a word in the dictionary and prints it .if there is no such word prints a message to infrom user
	void SearchEqualDeff();												//search for words with equal defanition and prints them
	friend class Menu;											//friend class declaration
	friend class String;
};
