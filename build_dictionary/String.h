#include <iostream>
#define ZERO 0
#define  CHARDIFF 'a' - 'A'
using namespace std;
int strlenth(char *str);
class String {										//string class declaration char* and size
private:													
	char *str;									
	int StrSize;
public:
	String() : str(NULL), StrSize(ZERO) {};						//default ctor
	String(char*);												//ctour with char * paramater for the char * private member
	~String() { delete[] str; };								//dtour releases str member memory
	String& operator = (char *);										// operator overloading for string class
	String& operator = (const String&);
	bool operator == (const String&)const;
	bool operator != (const String&)const;
	friend ostream& operator <<(ostream&out, const String& str);
	friend istream& operator >>(istream&input, String& str);
	String& operator -=(char);
	String& operator +=(char);
	char& operator [](int index);
	void FixStr();												// a method that uses the three other method to fix the string as instructed
	void FixSpaces();
	void Fix_Cases();
	void Fix_Pisuk();
	int getSIze() { return StrSize; }												//get method
	friend class Definition;														//friend class declaration
	friend class Dictionary;
	bool strcompare(const String&)const;												//checks two strings lexicography order 
};
