#include "Dealer.h"


Dealer::Dealer() {
	hand_ = new Hand();
}

Dealer::~Dealer() {
	delete hand_;
}

Hand* Dealer::getHand() {
	return hand_;
}

