#pragma once

#include <vector>
#include "Card.h"
#include <iostream>
class Hand
{

private:

	vector<Card*> cards;

public:

	Hand();
	~Hand();

	void addCard(Card*);
	void Restart();

	bool IsBlackDjeck();

	int getCountCard();
	int CalculateScore();
	void PrintCards();

	vector<Card*> getCards();

	Card * gamercards[11];
	int k = 0;


};


