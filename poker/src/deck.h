#pragma once
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include "card.h"

namespace poker {

	//template<typename T>
	//void constexpr swap(T& lhs, T& rhs)
	//{
	//	T tmp = lhs;
	//	lhs = rhs;
	//	rhs = tmp;
	//}

	class Deck {
	public: // Basic constructors / operators
		
		Deck();
		~Deck();
		Card operator[](int index)
		{
			return deck_[index];
		}

	public: // Action functions (that change the instance)

		void addCard(Card& cd);
		void addJokers(); 
		void populate(bool wJokers = false);
		//void addDeck();
		//void delDeck();
        void draw(unsigned int nToDraw = 1);
		void swap(Card* & cd1, Card* & cd2);
		//void shuffle(Deck& dk);

	public: // Action functions (that do NOT change the instance -- only DISPLAY)

		void peek(unsigned int cut=0, unsigned int nToPeek=1) const;
		void print() const;
		
	public: // Stats functions
        		
		int size(const char* cds);

	private: // Items  
		
		std::vector<Card> deck_, drawn_;
        
		// stats
		//int nDecks_;
		//int maxNCards_;
		

	};

} // namespace poker


