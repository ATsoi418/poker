#include <iostream>
#include <string>

namespace pokerCards {

class Card {
public:
	const static int ACE = 1;
	const static int JACK = 11;
	const static int QUEEN = 12;
	const static int KING = 13;

	enum Suit { SPADE=1, HEART, CLUB, DIAMOND };

	Card(int value, Suit suit);
	Card(const Card& o);
	~Card();

	bool IsValid() const;
	std::string PrintCard() const;
	bool operator==(const Card& o) const;

	bool red() const;
	int value() const;
	Suit suit() const;

private:
	int value_;
	Suit suit_;

};

} // namespace pokerCards


std::iostream& operator<<(std::iostream& out, const Card& card);







};
