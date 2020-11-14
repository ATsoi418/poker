#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"

int main()
{
    //poker::Card::Face f = poker::Card::Face::TWO;
    //poker::Card::Suit s = poker::Card::Suit::HEART;
    //poker::Card cd(f, s); // 2 of HEARTS
    //poker::Card cd2 = cd; // 3 of CLUBS
    //poker::Card cd3(++f, --s); // 4 of DIAMONDS
    
    poker::Deck dk;
    dk.populate();
    dk.draw();
    //dk.shuffle();

    //dk.print();
    poker::Card firstC = dk[0]; // 2 of DIAMONDS
    poker::Card secC = dk[1]; // 3 of CLUBS
    std::cout << firstC << std::endl; // 2 of DIAMONDS

    // Swap cards
    
    poker::Card* firstCptr = &firstC;
    poker::Card* secCptr = &secC;

    dk.swap(firstCptr, secCptr);

    dk.print();
    std::cout << firstC << std::endl; // 3 of CLUBS
    //std::cin.get();
    return 0;
}