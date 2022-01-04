#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include "team.h"  // player.h string, vector




class Game{

public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];


	Team teamA,teamB;
	Team *battingTeam;
	Team *bowlingTeam;
	Player *batsman, *bowler;
	bool isFirstInnings;

	void welcome(void);
	void showPlayers(void);
	int takeIntegerInput(void);
	bool validPlayer(int);
	void selectPlayers(void);
	void showTeamPlayers(void);

	void toss(void);

	void startFirstInnings(void);
	bool validateInnings(void);
	void initializePlayers(void);

	void swapTeams(void);
	void startSecondInnings(void);

	void playInnings(void);
	void bat(void);
	void showGameScorecard(void);
	void decideWinner(void);
	void matchSummary(void);

};
