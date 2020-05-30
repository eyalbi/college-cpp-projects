#include "String.h"



class Definition {								//class declartion
private:
	int Number_d;
	String ** Defanitions, word;
public:
	Definition() :Number_d(ZERO), word(), Defanitions(NULL) {};						///default ctour
	~Definition();																	//dtour that releases heap memory
	Definition& operator = (const Definition&);								//class operator overloading
	bool  operator == (const Definition&)const;
	friend ostream& operator <<(ostream&out, const Definition& deff);
	friend istream& operator >>(istream&input, Definition& str);
	Definition& operator -=(int index);
	Definition& operator += (const String& hagdra);
	String& operator [](int index);
	bool InDefanition(const String &, int index);							//checks if a defanition has a certain defanition up to a specific index
	friend class Dictionary;											//friend class declaration 
	friend class Menu;
};