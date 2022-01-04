#include "game.h" // iostream,limit,
#include <unistd.h>
using namespace std;

Game::Game()
{
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Sachin";
	players[1] = "Sehwag";
	players[2] = "Gambhir";
	players[3] = "Raina";
	players[4] = "Dhoni";
	players[5] = "Kohli";
	players[6] = "Yuvraj";
	players[7] = "Zaheer";
	players[8] = "Harbhajan";
	players[9] = "Yusuf";
	players[10] = "Nehra";

	isFirstInnings = true;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}

void Game::welcome(){
		cout << "\t\t\t"   <<"_______________________________________" << endl<<endl;;
	    cout << "\t\t\t"   <<"|___      ////  CRICK-IN  \\\\\\\\     ___|" << endl;
	    cout << "\t\t\t"   <<"|                                     |" << endl;
	    cout << "\t\t\t"   <<"|         Welcome to CRICK-IN         |" << endl;
	    cout << "\t\t\t"   <<"_______________________________________" << endl;

	    //instructions
	    cout <<endl<<endl<<endl;
		cout << "\n\n\n\t\t"<<"============================================" << endl;
		cout << "\t\t"      <<"|                                          |" << endl;
	    cout << "\t\t"      <<"|          --- Instructions ---            |" << endl; //11
	    cout << "\t\t"      <<"|                                          |" << endl;
	    cout << "\t\t"      <<"| 1.Create 2 teams(Team-A and Team-B with  |" << endl;
	    cout << "\t\t"      <<"|   4 players each) from a given pool of   |" << endl;
	    cout << "\t\t"      <<"|   11 players.		                   |" << endl;
	    cout << "\t\t"      <<"|                                          |" << endl;
	    cout << "\t\t"      <<"| 2.Lead the toss and decide the choice of |" << endl;
	    cout << "\t\t"      <<"|    play.                                 |" << endl;
	    cout << "\t\t"      <<"|                                          |" << endl;
	    cout << "\t\t"      <<"| 3.Each innings will be of 6 balls.       |" << endl;
	    cout << "\t\t"      <<"|                                          |" << endl;
	    cout << "\t\t"      <<"|                                          |" << endl;
	    cout << "\t\t"		<<"============================================" << endl;

}

void Game::showPlayers(){

    // pool of players
	cout << "\t\t\t"   <<" _____________________________________ " << endl;
	cout << "\t\t\t"   <<"|			              |" << endl;
    cout << "\t\t\t"   <<"|__________ Pool  of Players__________|" << endl;
    cout << "\t\t\t"   <<"|_____________________________________|" << endl;
    cout <<"\n\n";

    //players name with index
    for(int i=0;i<totalPlayers;i++)
    cout <<"\t\t\t\t\t"<<"["<<i<<"] "<<players[i]<<endl;




}


int Game::takeIntegerInput(){
	int value;
	while(!(cin >> value))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears input buffer
		// from limit library
		cout <<"Invalid input! Please try again with valid input : ";
	}

	return value;

}

bool Game::validPlayer(int x){
	for(unsigned int i=0;i<teamA.players.size();i++){
		if(x==teamA.players[i].id)
			return false;
	}
	for(unsigned int i=0;i<teamB.players.size();i++){
		if(x==teamB.players[i].id)
			 return false;
	}
	return true;
}

void Game::selectPlayers(){
	   cout << endl;
	   cout << "\t\t\t"   <<"_______________________________________" << endl;
	   cout << "\t\t\t"   <<"|			              |" << endl;
	   cout << "\t\t\t"   <<"|______ Create Team-A and Team-B _____|" << endl;
	   cout << "\t\t\t"   <<"|_____________________________________|" << endl;
	   cout <<"\n\n";


	for(int i=0;i<playersPerTeam; i++){
		// Add players to team A
	 teamASelection:
		cout <<endl<<"\t\t\tSelect Player "<<i+1 <<" of Team A- ";
		int playerIdTeamA = takeIntegerInput();
		if(playerIdTeamA<0||playerIdTeamA>10){
			cout <<"\t\t\tPlease select from given players"<<endl;
			goto teamASelection;
		}
		else if(!validPlayer(playerIdTeamA)){
			cout << "\t\t\tPlayer selected is already selected. Please try again " << endl;
			goto teamASelection;
		}
		else{
		Player teamAPlayer;
		teamAPlayer.id = playerIdTeamA;
		teamAPlayer.name = players[playerIdTeamA];

		teamA.players.push_back(teamAPlayer);
		}

	}
	// Add players to team B
	for(int i=0;i<playersPerTeam; i++){
			// Add player to team A
		teamBSelection:
			cout <<endl<<"\t\t\tSelect Player "<<i+1 <<" of Team B- ";
			int playerIdTeamB = takeIntegerInput();
			if(playerIdTeamB<0||playerIdTeamB>11){
				cout <<"\t\t\tPlease select from given players"<<endl;
				goto teamBSelection;
			}
			else if(!validPlayer(playerIdTeamB)){
				cout << "\t\t\tPlayer selected is already selected. Please try again " << endl;
				goto teamBSelection;
			}
			else{
			Player teamBPlayer;
			teamBPlayer.id = playerIdTeamB;
			teamBPlayer.name = players[playerIdTeamB];

			teamB.players.push_back(teamBPlayer);
			}
		}
}


void Game::showTeamPlayers(){
	cout << endl<< endl;
	cout <<"\t\t\t"<<"--------------------\t--------------------"<<endl;
	cout <<"\t\t\t"<<"|_-_-_ Team-A _-_-_|\t|_-_-_ Team-B _-_-_|"<<endl;
	cout <<"\t\t\t"<<"--------------------\t--------------------"<<endl<<endl;;

	for(int i=0; i< playersPerTeam; i++){
		cout <<"\t\t\t"<<" "<<"["<<i<<"] "<<teamA.players[i].name <<"\t\t "<<"["<<i<<"] "<<teamB.players[i].name<<"\t "<<endl;

	}
	//cout <<"\t\t\t"<<"---------------------------------------------------"<<endl<<endl;

	cout <<endl<<endl<<"\t\t\t"<<"______________________________________________________"<<endl;
	cout <<"\t\t\t"<<"______________________________________________________"<<endl<<endl<<endl<<endl;

}

void Game::toss(){


	cout <<endl;
	srand(time(NULL));
	int r = rand()%2;
	if(r==1)
	{
			cout <<"\t\t\t"<<"Team-B win the toss"<<endl<<endl;

		    cout <<"\t\t\t"<<"Enter 1 to bat or 2 to bowl first"<<endl;
			cout <<"\t\t\t"<<"1. Bat"<<endl;
			cout <<"\t\t\t"<<"2. Bowl"<<endl;

			int choice;

		chooseAgainTeamB:
			cout <<"\t\t\t";
			cin >> choice;
			if(choice==1)
			{
				cout <<"\t\t\t"<<"Team-B win the toss and elected to bat first"<<endl;
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			else if(choice==2)
			{
				cout <<"\t\t\t"<<"Team-B win the toss and elected to bowl first"<<endl;
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else
			{
				cout <<"\t\t\t"<<"Incorrect option choosen. Please try again."<<endl;
				goto chooseAgainTeamB;
			}

	}
	else
	{
					cout <<"\t\t\t"<<"Team-A win the toss"<<endl<<endl;


				    cout <<"\t\t\t"<<"Enter 1 tp bat or 2 to bowl first"<<endl;
					cout <<"\t\t\t"<<"1. Bat"<<endl;
					cout <<"\t\t\t"<<"2. Bowl"<<endl;

					int choice;

				chooseAgainTeamA:
					cout <<"\t\t\t";
					cin >> choice;
					if(choice==1)
					{
						cout <<"\t\t\t"<<"Team-A won the toss and elected to bat first"<<endl;
						battingTeam = &teamA;
						bowlingTeam = &teamB;

					}
					else if(choice==2)
					{
						cout <<"\t\t\t"<<"Team-A won the toss and elected to bowl first"<<endl;
						battingTeam = &teamB;
						bowlingTeam = &teamA;
					}
					else
					{
						cout <<"\t\t\t"<<"\t\t\t"<<"Incorrect option chosen. Please try again."<<endl;
						goto chooseAgainTeamA;
					}
	}


}

void Game::startFirstInnings(){
	//cout <<"\n\n\n\t\t\t" <<"\t\t __________________________"<<endl<<endl;
	cout <<"\n\n\n\n\t\t\t" <<"\t\t || FIRST INNINGS STARTS ||\n\n"<<endl;
	//cout <<"\t\t\t" <<"\t\t __________________________"<<endl<<endl<<endl;
	isFirstInnings = true;

	initializePlayers();
}

void Game::initializePlayers(){
	// choose batsman and bowler: Initialize *batsman and *bowler

	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout <<"\t\t\t"<<battingTeam->name<<" - "<<batsman->name <<" is batting "<<endl;
	cout <<"\t\t\t"<<bowlingTeam->name<<" - "<<bowler->name <<" is bowling \n\n"<<endl;

}

void Game::playInnings(){
	for(int i=0;i<maxBalls;i++){
		cout <<"\t\t\t"<<"Press enter to bowl...\n";
		cin.get();
		cout << "\t\t\t"<<"Bowling...\n"<<endl;
		bat();

		if(!validateInnings()){
			break;

		}
	}
}

void Game::bat(){
	sleep(1);
	srand(time(NULL));
	int runScored = rand()%7;

	//Updating batting team and batsman score

	batsman->runScored +=runScored;
	battingTeam->totalRunsScored+=runScored;
	batsman->ballsPlayed++;

	//Updating bowling team and bowling score
	bowler->ballsBowled++;
	bowlingTeam->totalBallsBowled++;
	bowler->runsGiven+=runScored;




	if(runScored==0) {
		cout <<endl<<"\t\t\t"<<bowler->name<<" to "<<batsman->name<<" OUT!\n\n";			// wicket
		battingTeam->wicketsLost++;
		bowler->wicketsTaken++;
		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];

		showGameScorecard();
			}
	else{																					// runs
	cout <<"\n\t\t\t"<<bowler->name<<" to "<<batsman->name<<" "<<runScored<<" runs!\n\n";
	showGameScorecard();
	}



}
bool Game::validateInnings(){

	if (isFirstInnings){

		if(battingTeam->wicketsLost == playersPerTeam||bowlingTeam->totalBallsBowled ==maxBalls){
			cout <<"\n\t\t\t"<<"First Innings ended\n\n";
			cout <<"\t\t\t"<<battingTeam->name<<" " <<battingTeam->totalRunsScored<<" - "			//1st  innings ended
					<< battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled
					<<")"<<endl<<endl;

			cout <<"\t\t\t"<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored+1
					<<" runs to win the match"<<endl<<endl;

			isFirstInnings = false;
			return false; // innings ended
		}
		}
	else{ //2nd inning
		if(battingTeam->wicketsLost == playersPerTeam||(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored)||bowlingTeam->totalBallsBowled ==maxBalls){
		cout <<"\n\t\t\t"<<"Second Innings ended\n";
		cout <<"\t\t\t"<<battingTeam->name<<" " <<battingTeam->totalRunsScored<<" - "               // 2nd innings ended
			 << battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled
			 <<")"<<endl<<endl;
		return false; // innings ended
		}
		}


	return true;



}

void Game::showGameScorecard(){

	cout << "\t\t\t" << "---------------------------------------------------------------\n";
	cout << "\t\t\t" << "[ "<<battingTeam->name << " " << battingTeam->totalRunsScored
		 << " - "<< battingTeam->wicketsLost << " ("<< bowlingTeam->totalBallsBowled
	 	 << ") | " << batsman->name << " " << batsman->runScored << "("<< batsman->ballsPlayed
		 << ")\t " << bowler->name << " " << bowler->ballsBowled << " - "<< bowler->runsGiven
		 << " - " << bowler->wicketsTaken << " ]" << endl;
	cout << "\t\t\t" << "---------------------------------------------------------------\n\n";



}

void Game::swapTeams(){
/*	Team *temp;
	temp = &battingTeam;
	battingTeam = &bowlingTeam;
	bowlingTeam = &temp;*/

		Team temp;
		temp = *battingTeam;
		*battingTeam = *bowlingTeam;
		*bowlingTeam = temp;



}
void Game::startSecondInnings(){
	sleep(3);
	cout <<"\n\t\t\t=========================================================================\n\n\n\n\n";

	cout<<"\n\n\n\t\t\t"<<"\t\t || SECOND INNINGS STARTS ||\n\n\n\n";
	swapTeams();
	initializePlayers();

}

void Game::decideWinner(){
//	sleep();
	if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored)
	{
		cout <<"\t\t\t\t=="<<battingTeam->name<<" won the match==\n\n";
	}
	else if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored){
		cout <<"\t\t\t\t=="<<"Match is Draw==\n\n";
	}
	else{
		cout <<"\t\t\t\t=="<<bowlingTeam->name<<" won the match==\n\n";
	}

}

void Game::matchSummary(){

	cout <<"\n\n\t\t\t[ MATCH   SUMMARY ]  \n\n\n";

	cout <<"\t\t\t"<<teamB.name<<" "<<teamB.totalRunsScored<<"-"<<teamB.wicketsLost
		 <<"  ("<< teamB.totalBallsBowled <<")"<<endl;


	cout <<"\t\t\t"<<"============================================================\n";
	cout <<"\t\t\t\t"<<"  PLAYER\t\tBATTING\t\tBOWLING  \n";
	for(int i=0;i<playersPerTeam;i++){
		cout <<"\t\t\t\t"<<" ["<<i<<"] "<<teamB.players[i].name<<"\t\t"<<teamB.players[i].runScored
			 <<"("<<teamB.players[i].ballsPlayed<<")\t\t"<<teamB.players[i].ballsBowled
			 <<"-"<<teamB.players[i].runsGiven<<"-"<<teamB.players[i].wicketsTaken<<" \n";
			}
	cout <<"\t\t\t"<<"============================================================\n\n\n\n\n";

	cout <<"\t\t\t"<<teamA.name<<" "<<teamA.totalRunsScored<<"-"<<teamA.wicketsLost
		 <<"  ("<< teamA.totalBallsBowled <<")"<<endl;

	cout <<"\t\t\t"<<"============================================================\n";
	cout <<"\t\t\t\t"<<"  PLAYER\t\tBATTING\t\tBOWLING  \n";
	for(int i=0;i<playersPerTeam;i++){
		cout <<"\t\t\t\t"<<" ["<<i<<"] "<<teamA.players[i].name<<"\t\t"<<teamA.players[i].runScored
			 <<"("<<teamA.players[i].ballsPlayed<<")\t\t"<<teamA.players[i].ballsBowled
			 <<"-"<<teamA.players[i].runsGiven<<"-"<<teamA.players[i].wicketsTaken<<" \n";
	}
	cout <<"\t\t\t"<<"============================================================\n";


}
//End of Program


