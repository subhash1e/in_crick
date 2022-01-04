#include "player.h"
#include <vector>


class Team{

	public:

		Team();
	   std::string name;
	   int totalRunsScored;
		int totalBallsBowled;
		int wicketsLost;
		std::vector<Player>players;

};



