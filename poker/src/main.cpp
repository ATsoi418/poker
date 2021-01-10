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

    // Swap cards
    poker::Card firstC = dk[0];
    poker::Card secC = dk[1];

    //poker::Card* firstCptr = &dk[0]; //00B8F750
    //poker::Card* secCptr = &dk[1]; //00B8F720

    std::cout << firstC << std::endl; // 2 of DIAMONDS
    std::cout << secC << std::endl; // 2 of CLUBS

    swap(firstC, secC);

    poker::Card newFirstC = dk[0];
    poker::Card newSecC = dk[1];
    
    std::cout << newFirstC << std::endl; // 2 of CLUBS
    std::cout << newSecC << std::endl; // 2 of DIAMONDS
    std::cin.get();

    return 0;
}