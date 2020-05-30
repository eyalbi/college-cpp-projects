#include "Coach.h"

class Referee :public Worker {       //inherited class from worker that adds mistake game and max mistake amounts
private:
	int Mistakes;
	int Games;
	static int MaxMistakes;
public:
	Referee() :Worker(), Mistakes(ZERO), Games(ZERO) {};
	Referee(string name, string surname, string id, int TVeteck, int mistake) :Worker(name, surname, id, TVeteck), Mistakes(mistake),Games(ZERO){
		if (MaxMistakes < Mistakes) { MaxMistakes = Mistakes; }
	};
	Referee(const Referee&);
	~Referee() {};
	float ReturnSalary()const;
	bool checkspecial()const;
	void AddMistakes(int mistake);
	void GamesUpdate() {Games++;};
	bool checkId(int index, Referee** refs, string&id);
	friend class Ligat_HaAl;
};
