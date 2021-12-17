#include "Card.h"





Card::~Card() {}

char Card::getName() {
	return num_;
}
void Card::setName(char value) {
	num_ = value;
}

char Card::getMast() {
	return mast_;
}
void Card::setMast(char mast) {
	mast_ = mast;
}

int Card::getScore() {

	int score;
	switch (num_)
	{
	case '2': score = 2; break;
	case '3': score = 3; break;
	case '4': score = 4; break;
	case '5': score = 5; break;
	case '6': score = 6; break;
	case '7': score = 7; break;
	case '8': score = 8; break;
	case '9': score = 9; break;
	case '1': score = 10; break;
	case 'J': score = 10; break;
	case 'Q': score = 10; break;
	case 'K': score = 10; break;
	case 'A': score = 11; break;
	default:  score = 0; break;
	}
	return score;

}


std::ostream& operator<<(std::ostream& stream, Card& card)
{
	if (card.num_ == '1') stream << "10 " << card.mast_;

	else
		stream << card.num_ << card.mast_;

	return stream;
}