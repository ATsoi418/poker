#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace poker {

	template <typename E>
	constexpr auto enumVal(E e)
	{
		static_assert(std::is_enum<E>::value, "Parameter is not of type enum or enum class");
		return static_cast<typename std::underlying_type<E>::type>(e);
	}

	template <typename E>
	constexpr E begin(E e)
	{
		static_assert(std::is_enum<E>::value, "Parameter is not of type enum or enum class");
		return e;
	}

	template <typename E>
	constexpr E operator++(E& e)
	{
		static_assert(std::is_enum<E>::value, "Parameter is not of type enum or enum class");
		return e = (E)(std::underlying_type<E>::type(e) + 1);
	}

	template <typename E>
	constexpr E operator--(E& e)
	{
		static_assert(std::is_enum<E>::value, "Parameter is not of type enum or enum class");
		return e = (E)(std::underlying_type<E>::type(e) - 1);
	}
	
	template <typename E>
	constexpr E operator*(E e)
	{
		static_assert(std::is_enum<E>::value, "Parameter is not of type enum or enum class");
		return e;
	}

	class Card {
	public: // Defining Face & Suit
		enum class Face { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, END_FACE, JOKER };
		enum class Suit { DIAMOND = 0, CLUB, HEART, SPADE, END_SUIT, LITTLE, BIG };
		const std::vector<std::string> faceStr = { "JACK", "QUEEN", "KING", "ACE", "END_FACE", "JOKER" };
		const std::vector<std::string> suitStr = { "DIAMOND", "CLUB", "HEART", "SPADE", "END_SUIT", "LITTLE", "BIG" }; // Order should match enum class Suit
	
	public: // Basic constructors

		Card(Face face, Suit suit);
		Card(const Card& cd);
		~Card();

		Face face();
		Suit suit();

	public: // 

		bool isRed() const;
		bool isValid() const;
		bool operator==(const Card& lhs, const Card& rhs);
		bool operator!=(const Card& lhs, const Card& rhs);
		//bool operator<(const Card& lhs, const Card& rhs);
		//bool operator>(const Card& lhs, const Card& rhs);

		std::vector<std::string> cd_to_str();
		
		friend std::ostream& operator<<(std::ostream& os, Card & cd)
		{	
            return (os << (cd.cd_to_str())[0] << " of " << (cd.cd_to_str())[1] << "S");
		}

	private:
		Face face_;
		Suit suit_;

	};

	

} // namespace poker
