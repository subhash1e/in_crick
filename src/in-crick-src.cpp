//	Author: Subhash Kumar
//	Topic: C++ code for in-crick game application
#include "game.h"
using namespace std;

int main()
{
									// Introduction section
	Game g1;
	g1.welcome();

	cout << "\n\t\t"    <<"Press enter to continue \n\n" << endl;
	cin.get();

	g1.showPlayers(); // showing players available


	cout << "\n\t\t"    <<"Press enter to continue \n\n" << endl;
	cin.get();

									//player selection section

	g1.selectPlayers();
	g1.showTeamPlayers();

	cout <<"\t\t\t" <<"Press Enter to Toss"<<endl<<"\t\t\t";

	getchar();
	getchar();
									// innings section
	g1.toss();

	g1.startFirstInnings();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	g1.playInnings();
	g1.startSecondInnings();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	g1.playInnings();






									// result section
	g1.decideWinner();


	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	g1.matchSummary();
	cin.get();




	//End of program





	return 0;
}

