#include "Deck.h"
#include <iterator>
using namespace std;

Deck::Deck() {

	vector<char> value = { '2','3','4','5','6','7','8','9','1','J','Q','K','A'};
	vector<char>mast = { char(3),char(4),char(5),char(6) };

	for (int i = 0; i < mast.size(); i++) {
		for (int j = 0; j < value.size(); j++) {
			deck.push_back(new Card(value[j], mast[i]));
		}
	}
}

Deck::~Deck() {

	for (vector<Card*>::iterator it = deck.begin(); it != deck.end(); it++)
		delete* it;

}

void Deck::Shuffle() {
	for (int i = 0; i < deck.size(); i++)
		swap(deck[rand() % deck.size()], deck[rand() % deck.size()]);
}


int Deck::getSize() {
	return deck.size();
}

Card* Deck::pop() {

	Card* tmp = deck[0];
	deck.erase(deck.begin());
	return tmp;
}

void Deck::Print() {

	for (int i = 0; i < sizeof(deck); i++) {

		cout << deck[i] << endl;
	}

}