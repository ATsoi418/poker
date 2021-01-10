#include "card.h"
#include <iostream>
#include <string>

namespace poker {

// Basic constructors

Card::Card(Face face, Suit suit) : face_(face), suit_(suit) {}
Card::Card(const Card& cd) : face_(cd.face_), suit_(cd.suit_) {}
Card::~Card() {}

Card::Face Card::face() { return face_; }
Card::Suit Card::suit() { return suit_; }

bool Card::isValid() const { return (int(face_) >= 1) && (int(face_) < 14) && (int(suit_) >= 1) && (int(suit_) < 5); }
bool Card::isRed() const { return ((suit_ == Suit::HEART) || (suit_ == Suit::DIAMOND) || (suit_ == Suit::BIG)); }
bool operator==(const Card& lhs, const Card& rhs) { return lhs.face_ == rhs.face_ && lhs.suit_ == rhs.suit_; }
bool operator!=(const Card& lhs, const Card& rhs) { return !(lhs == rhs); }
//bool operator<(const Card& lhs, const Card& rhs) { return lhs.face_ < rhs.face_; }
//bool operator>(const Card& lhs, const Card& rhs) { return !(lhs < rhs); }

std::vector<std::string> Card::cd_to_str()
{
	// init card string vector
	std::vector<std::string> cdStr;

	// push_back face string
	int faceInt = enumVal(Card::face());
	if (faceInt > 10) { cdStr.push_back(Card::faceStr[faceInt - 11]); }
	else { cdStr.push_back(std::to_string(faceInt)); }

	// push_back suit string
	cdStr.push_back(Card::suitStr[enumVal(Card::suit())]);

	// return result
	return cdStr;
}




}