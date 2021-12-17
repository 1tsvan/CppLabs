#pragma once
#include "Hand.h"




class Player
{
private:
	Hand* hand_;
	int balance_;
	int Currentbet_;
	int startBet_;
public:

	static const int maxCountCards = 12;
	int countCards = 0;

	Player();
	~Player();

	Hand* getHand()const;

	int getBalance()const;


	int getStartBet()const;
	void setStartBet(int bet);

	int getCurrentBet();
	int& NewBet();

	void addBalance(int money);
	void SubBalance(int money);

};

