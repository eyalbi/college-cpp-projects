#include <iostream>
#include <string>
#define ZERO 0
#define ONE 1
using namespace std;
class OrderedSet {				//הכרזה על מחלקה
private:						//	הגדרת האזור הפרטי עם נותני המחלקה ופונקציות עזר
	int * Group;
	int Size;
	void Sort_G(int *, int);		//פונקציה למיון מערך לקבוצה
	bool Orderd_G(int *, int);			//פונקצייה הבודקת אם מערך מסודר
	int ReturningValue(int * group, int size);			//פונקצייה הבודקת את כמות הערכים החוזרים במערך
	bool inArray(int*, int, int);					//פונקמיה הבודקת אם מספר שלם נמצא במערך
	int SameValues(OrderedSet obj);					//פונקציה הבודקת כמות ערכים חוזרים בין שתי קבוצות שונות

public:
	OrderedSet() : Group(NULL), Size(ZERO) {} //בנאי דפולטיבי
	OrderedSet(int *group, int size);			//בנאי עם פמטרים
	OrderedSet(const OrderedSet & obj);			// בנאי מעתיק
	~OrderedSet() { delete[] Group; }				// הורס שמשחרר את הזיכרון
	int *Get_Group() { return Group; }					//פונקציות לקבלת נתוני מחלקה
	int Get_Size() { return Size; }
	bool Contain(int);									//פונקציה לבדיקה אם מספר שלם כלשהו מופיעה בקבוצה
	void ChangeGroup(int * group, int size);		// מתודה המשנה קבוצה למערך שמתקבל דרך הפרמטרים(טם לא קבוצה מוציאה הודעה מתאימה 
	OrderedSet Def(OrderedSet obj);						//פונקצייה המחשבת הפרש בין קבוצות
	OrderedSet intersect(OrderedSet obj);				// פונקצייה המחשבת חיתוך בין קבוצות
	OrderedSet Union(OrderedSet obj);						// פונקצייה המחשבת איחוד של קבוצות
	bool EqualGroups(OrderedSet obj);						// פונקצייה הבודקת אם קבוצות שוות
	bool EmptyGroup();										//פונקציה הבודקת אם קבוצה היא הקבוצה הריקה
	bool Contain(OrderedSet obj);							//פונקציהה הבודקת אם קבוצה אחת מכילה את השנייה 
	void PrintGroup();		//פונקצייה המדפיסה קבוצה
	
};