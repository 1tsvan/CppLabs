#pragma once
#include <fstream>

using namespace std;

class Card
{
private:

	char mast_;
	char num_;

public:

	Card(char value, char mast) :num_(value), mast_(mast) { }
	~Card();

	void setMast(char mast);
	char getMast();

	void setName(char name);
	char getName();

	int  getScore();

	friend ostream& operator << (ostream&, Card&);
};

