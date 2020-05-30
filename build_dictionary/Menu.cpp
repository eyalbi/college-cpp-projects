#include "Menu.h"

void Menu::MainMenu()
{
	Definition temp;
	String Stemp;
	int i = ZERO, end;
	cout << "Hello i am dictionary follow the instruction and hace fun" << endl;
	do {
		cout << "1. Create a dictionary\n\n2.Enter a new word to the dictionary\n\n3.Add a new definition to an existing word\n\n4.find a word in the dictionary\n\n5.Print all the words with the same defintions\n\n6.EXIT" << endl;
		do {
			cin >> end;
			if(i == ZERO && end != 1 && end !=6){
				cout << "you need to create a dictionary first try again" << endl;
			}
			if (i > ZERO && end == 1) {
				cout << "the Dictionary allready exist please try a diffrent option" << endl;
				cout << "1. Create a dictionary\n\n2.Enter a new word to the dictionary\n\n3.Add a new definition to an existing word\n\n4.find a word in the dictionary\n\n5.Print all the words with the same defintions\n\n6.EXIT" << endl;
			}
			} while ((end == 1 && i > ZERO) || (i == ZERO && end != 1 && end != 6));
			i++;
			getchar();
		switch (end)
		{
		default:
			cout << "invalid input try again\n";
			break;
		case 1:
			EvenShushan = new Dictionary;
			cin >> *EvenShushan;
				break;
		case 2:
			cin >> temp;
			*EvenShushan += temp;
			break;
		case 3:
			cout << "enter a search word\n";
			cin >> Stemp;
			EvenShushan->SearchAndAdd(Stemp);
			break;
		case 4:
			cout << "please enter a word for a search\n";
			cin >> Stemp;
			EvenShushan->SearchAndPrint(Stemp);
			break;
		case 5:
			EvenShushan->SearchEqualDeff();
			break;
		
		case 6:
			cout << "goodbye" << endl;
		}
	} while (end != 6);
}
