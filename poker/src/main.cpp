#include <iostream>
#include <string>

using String = std::string;

class Game
{
private:
    String card;

public:
    Game() : card("Ace") {}
    Game(const String& face) : card(face) {}

    const String& GetFace() const { return card; }
};

struct Deck {
    int face; 
    int suit;
    bool incJokers;
    int drawn;
};

int main()
{
    Game game;

    std::cout << game.GetFace() << std::endl;

    std::cin.get();
}