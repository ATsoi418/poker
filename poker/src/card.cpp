#pragma once

#include "card.h"
#include <iostream>

namespace pokerCards {

    Card::Card(int value, Suit suit) : value_(value), suit_(suit) {}
    Card::Card(const Card& o) : value_(o.value_), suit_(o.suit_) {}
    Card::~Card() {}

    bool Card::IsValid() const { return (value_ >= ACE) && (value_ <= KING) && (suit_ >= SPADE) && (suit_ <= DIAMOND); }

    //std::string Card::PrintCard() const {
    //    std::iostream out;
    //    out << *this;
    //    return out.str();
    //}

    bool Card::operator==(const Card& o) const {
        return ((value_ == o.value_) && (pokerCards::Card::suit_ == o.suit_));
    }

    bool Card::red() const { return ((suit_ == HEART) || (suit_ == DIAMOND)); }
    int Card::value() const { return value_; }
    Suit Card::suit() const { return suit_; }

}  // namespace pokerCards


//std::iostream& operator<<(std::iostream& out, const pokerCards::Card& card) {
//    if (!card.IsValid()) {
//        std::cout << "<Invalid>";
//        return out;
//    }
//
//    int value = card.value();
//    switch (card.value()) {
//    case Card::ACE: out << "Ace"; break;
//    case Card::JACK: out << "Jack"; break;
//    case Card::QUEEN: out << "Queen"; break;
//    case Card::KING: out << "King"; break;
//    default: out << value; break;
//    }
//    std::cout << " of ";
//    switch (card.suit()) {
//    case Card::SPADE: out << "Spades"; break;
//    case Card::CLUB: out << "Clubs"; break;
//    case Card::HEART: out << "Hearts"; break;
//    case Card::DIAMOND: out << "Diamonds"; break;
//    }
//    return out;
}