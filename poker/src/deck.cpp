#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <cassert>
#include "deck.h"
#include "card.h"
//#include <time.h>

namespace poker {
	
	// Basic constructors
	Deck::Deck() { deck_; }

	Deck::~Deck() {}


	// Action functions (that change the instance)

	void Deck::addCard(Card& cd) {
		deck_.push_back(cd);
	}

	void Deck::addJokers() {
		Card bj(Card::Face::JOKER, Card::Suit::BIG);
		Card lj(Card::Face::JOKER, Card::Suit::LITTLE);
		deck_.push_back(bj);
		deck_.push_back(lj);
	}

	void Deck::populate(bool wJokers) {

		for (Card::Face f = Card::Face::TWO; f != Card::Face::END_FACE; ++f)
		{
			for (Card::Suit s = Card::Suit::DIAMOND; s != Card::Suit::END_SUIT; ++s)
			{
				Card cd(f,s);
				addCard(cd);
			}
		}
		// add Jokers
		if (wJokers == true) {
			addJokers();
		}
	}

	//void Deck::addDeck() {}

	Card Deck::draw(unsigned int nToDraw) {
		
		for (int i = 0; i != nToDraw; ++i) {
			Card cd = deck_.back();
			deck_.pop_back();
		}		

	}

	//void Deck::swap(Card* cd1, Card* cd2) {
	//	
	//	Card tmpC = *cd1;
	//	*cd1 = *cd2;
	//	*cd2 = tmpC;
	//}

	//void Deck::shuffle(Deck& dk)
	//{
	//	// Initialize seed randomly 
	//	srand(time(0));

	//	for (int i = 0; i < dk.size(); i++)
	//	{
	//		// Random for remaining positions. 
	//		int r = i + (rand() % (dk.size() - i));

	//		std::swap(dk[i], dk[r]);
	//	}
	//}

	//void Deck::shuffle() {

	//	assert(deck_.size() != 0); // Abort func if deck is empty.
	//	std::random_device rd; std::mt19937 rng(rd);
	//	std::random_shuffle(deck_[0], deck_[deck_.size()-1]);
	//}


	// Action functions (that do NOT change the instance -- only DISPLAY)

	void Deck::peek(unsigned int cut, unsigned int nToPeek) const
	{
		assert(deck_.size() != 0); // Abort func if deck is empty.
		int peekEnd = (cut + nToPeek);
		int ds = deck_.size();
		if ((ds-peekEnd) < 0) { throw std::invalid_argument("peek input out of scope"); };

		for (int i = cut; i < peekEnd; ++i) {
			Card cd = deck_[i];
			std::cout << cd;
			if (cd != deck_[peekEnd-1])
				std::cout << ", ";
		}
		std::cout << std::endl;
	}

	void Deck::print() const {
		// TO-DO: print jokers
		assert(deck_.size() != 0); // Abort func if deck is empty.
		for (Card cd : deck_) {
			std::cout << cd;
			if (cd != deck_.back())
				std::cout << ", ";
		}
		std::cout << std::endl;
	}


	// Stats functions

	int Deck::size(const char* cds)
	{
		return std::size(deck_);
	}

	


} // namespace poker