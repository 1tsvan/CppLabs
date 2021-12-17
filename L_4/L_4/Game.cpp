#include "Game.h"
#include <conio.h>

Game::Game()
{
	for (int i = 0; i < 4; i++) {
		decks_.push_back(new Deck());
		decks_[i]->Shuffle();
	}
	dealer_ = new Dealer();
	player_ = new Player();
}

Game::~Game() {

	for (vector<Deck*>::iterator it = decks_.begin(); it < decks_.end(); ++it)
		delete* it;

	delete dealer_;
	delete player_;
}

void Game::PrintStatus() {

	for (int i = 0; i < decks_.size(); i++)
		cout << " [" << decks_[i]->getSize() << "] ";
	if (islose_) {
		cout << endl << "Диллер:";
		dealer_->getHand()->PrintCards();
		
	}
	else {
		cout << endl << "Диллер:";
		dealer_->getHand()->PrintCards();
		cout << "??";
	}
	

	cout << endl << "Игрок:";
	
	player_->getHand()->PrintCards();
	cout << endl << endl << "Баланс: " << player_->getBalance() << endl;
	
}

void Game::Lose() { 
	islose_ = true;
	PrintStatus();
	cout << endl << "LOSE!" << endl << "Баланс: " << player_->getBalance() << endl << "Счет: " << player_->getHand()->CalculateScore() << endl << "Диллер: " << dealer_->getHand()->CalculateScore() << endl << endl;
	player_->getHand()->Restart();
	dealer_->getHand()->Restart();
}


void Game::Win() {

	
	player_->addBalance(player_->getCurrentBet());
	player_->addBalance((player_->getCurrentBet() ) );
	PrintStatus();
	cout << endl << "WIN!" << endl << "Баланс: " << player_->getBalance() << endl << "Счет: " << player_->getHand()->CalculateScore() <<  endl;
	player_->getHand()->Restart();
	dealer_->getHand()->Restart();


}



bool Game::TakeMore() {

	try {
		 player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		
		if (player_->getHand()->CalculateScore() <= 21) {
		
		
			return true;
		}
		throw 22;
	}
	catch (int a) {
		Lose();
		return false;
	}

}



void Game::Run() {

	int all_count_cards = 0;

	while (true) {



		for (int i = 0; i < decks_.size(); i++) {
			all_count_cards += decks_[i]->getSize();
		}

		if (all_count_cards < 52 * decks_.size() / 3) {

			int count_deck = decks_.size();

			for (vector<Deck*>::iterator it = decks_.begin(); it < decks_.end(); ++it)
				delete* it;

			for (int i = 0; i < count_deck; i++) {
				decks_.push_back(new Deck());
			}
		}


		cout << "Ваш баланс: " << player_->getBalance() << endl;
		cout << "Ваша ставка: ";


		cin >> player_->NewBet();
		
			if ((player_->getBalance() - player_->getCurrentBet()) < 0) {
				cout << "Недостаточно денег";
				break;
			}

			else {
				player_->SubBalance(player_->getCurrentBet());
				player_->setStartBet(player_->getCurrentBet());
			}
		cout << endl << "Баланс: " << player_->getBalance() << endl;
		cout << "Ставка: " << player_->getCurrentBet() << endl << endl;


		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		dealer_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
		player_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());


		while (true) {

			PrintStatus();

			if (player_->getHand()->IsBlackDjeck()) {

				if (dealer_->getHand()->getCards()[0]->getScore() == 11) {
					cout << "1 Хватит" << endl << "2 Еще" << endl << "3. Саррендер" << endl;

				}
				else {
					cout << "У вас Блек Джек" << endl;
					if (player_->getHand()->getCards()[0]->getMast() == player_->getHand()->getCards()[1]->getMast()) {
						Win();
					}
					else
					{
						Win();
					}
					break;
				}
			}
			else {


				cout << "1 Хватит" << endl << "2 Еще" << endl << "3 Саррендер" << endl;

			}

			cin >> select_;
			

			if (select_ == 1) {

				system("cls");
				int dealer_score = dealer_->getHand()->CalculateScore();
				int player_score = player_->getHand()->CalculateScore();

			
					dealer_->getHand()->addCard(decks_[rand() % decks_.size()]->pop());
					dealer_score = dealer_->getHand()->CalculateScore();
				


				if (dealer_score > 21) {
					Win();
					cout << "У диллера перебор" << endl;;
					break;
				}

				if (dealer_->getHand()->IsBlackDjeck()) {

					if (!player_->getHand()->IsBlackDjeck()) {
						Lose();
						break;
					}

				}
				else
				{
					if (player_->getHand()->IsBlackDjeck()) {
						if (player_->getHand()->getCards()[0]->getMast() == player_->getHand()->getCards()[1]->getMast()) {
							Win();
						}
						else {
							Win();
						}
						break;
					}
					else
					{
						if (dealer_score < player_score) {
							Win();
							break;
						}
						if (dealer_score > player_score) {
							Lose();
							break;
						}
						if (dealer_score == player_score) {
							Lose();
							break;
						}
					}
				}

				
			}

			if (select_ == 2) {
				system("cls");
				player_->countCards++;
				if (!TakeMore()) break;
				if (player_->countCards == player_->maxCountCards) break;
			}

			if (select_ == 3) {
				system("cls");

				player_->addBalance(player_->getCurrentBet() / 2);
				player_->NewBet() /= 2;
			
				cout << endl;
			
			}

			
		}


		if (player_->getBalance() <= 0)
		{
			cout << "-Деньги +Кредит" << endl;
			break;
		}

		
		
	}
}

