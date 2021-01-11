#pragma once
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include "card.h"

namespace poker {

	template <class T>
	void swap(T& a, T& b)
	{
		T c(std::move(a)); a = std::move(b); b = std::move(c);
	}

	class Deck {
	public: // Basic constructors / operators
		
		Deck();
		~Deck();
		auto operator[](int index)
		{
			return deck_[index];
		}

	public: // Action functions (that change the instance)

		void addCard(Card& cd);
		void addJokers(); 
		void populate(bool wJokers = false);
		//void addDeck();
		//void delDeck();
        Card draw(unsigned int nToDraw = 1);
		//void swap(Card* cd1, Card* cd2);
		//void shuffle(Deck& dk);

	public: // Action functions (that do NOT change the instance -- only DISPLAY)

		void peek(unsigned int cut=0, unsigned int nToPeek=1) const;
		void print() const;
		
	public: // Stats functions
        		
		int size(const char* cds);

	private: // Items  
		
		std::vector<Card> deck_;
        

	};

} // namespace poker


