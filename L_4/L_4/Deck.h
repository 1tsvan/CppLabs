#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include <iterator>
#include "IFormattable.h"

class Deck
{

	vector<Card*> deck;

public:

	Deck();
	~Deck();
	void Shuffle();
	int getSize();
	void Print();
	Card* pop();
};

