#include "Dictionary.h"

class Menu {             ///class declaration
private:
	Dictionary *EvenShushan;
public:																								
	Menu():EvenShushan(NULL) {};							//default ctour
	~Menu() { delete EvenShushan; };						//dtour
	void MainMenu();										//an operating function for the dictinary has all the fanctuality inside it
	
};
