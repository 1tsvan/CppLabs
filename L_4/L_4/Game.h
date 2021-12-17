#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <exception>

class Game
{
private:

	vector<Deck*> decks_;
	Dealer* dealer_;
	Player* player_;
	int select_;
	bool islose_ = false;
public:

	Game();
	~Game();

	void Run();
	void PrintStatus();


	void Win();
	void Lose();
	bool TakeMore();

};

