#include "Hand.h"

Hand::Hand() {}


Hand::~Hand() {}


void Hand::addCard(Card* card) {
	cards.push_back(card);
	
}

void Hand::Restart() {
	for (std::vector<Card*>::iterator i = cards.begin(); i < cards.end(); ++i)
		delete* i;
	cards.clear();
}

int Hand::getCountCard() {
	return cards.size();
}

int Hand::CalculateScore() {

	int summ = 0;

	for (int i = 0; i < cards.size(); i++) {
		summ += cards[i]->getScore();
	}

	if (summ <= 10) {
		for (int i = 0; i < cards.size(); i++) {
			if (cards[i]->getName() == 'A') {
				summ += 11;
			}
		}
	}
	else {
		for (int i = 0; i < cards.size(); i++) {
			if (cards[i]->getName() == 'A') {
				summ += 1;
			}
		}
	}


	return summ;
}

void Hand::PrintCards() {
	for (int i = 0; i < cards.size(); i++) {
		cout << *cards[i] << "  ";
	}
}

vector<Card*> Hand::getCards() {
	return cards;
}

bool Hand::IsBlackDjeck() {
	if (cards.size() == 2) {
		if (cards[0]->getScore() == 10 && cards[1]->getScore() == 11) {
			return true;
		}
		if (cards[0]->getScore() == 11 && cards[1]->getScore() == 10) {
			return true;
		}
	}
	return false;
}