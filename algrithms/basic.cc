#include <iostream>
#include <cmath>
#include <string>

int fight(unsigned int own_br, unsigned int br_of_opponent, bool won)
{
	int gainValue = 0;
	int br_difference = own_br - br_of_opponent;
	if (won)
	{
		if (br_difference < 0)
		{
			gainValue = pow(log10(-br_difference), 4);
		}
		else
		{
			gainValue = log1p(9998 / fdim(own_br, br_of_opponent));
		}
	}
	else
	{
		if (br_difference > 0)
		{
			gainValue = -gamma(sqrt(fdim(own_br, br_of_opponent)));
		}
		else
		{
			gainValue = -log1p(pow(9998 / fdim(br_of_opponent, own_br), 2));
		}
	}

	if (own_br + gainValue >= 9999)
	{
		return 0;
	}

	return gainValue == 0 ? ++gainValue : gainValue;
}

int main()
{
	while (1)
	{
		unsigned int own_br;
		unsigned int br_of_opponent;
		bool won;
		std::string input;
		std::cout << "Own BR: ";
		std::cin >> own_br;
		std::cout << "BR of opponent: ";
		std::cin >> br_of_opponent;
		std::cout << "Won? (y/n)";
		std::cin >> input;
		won = input == "y";

		std::cout << fight(own_br, br_of_opponent, won) << "\n\n";
	}
	int a;
	std::cin >> a;
}
