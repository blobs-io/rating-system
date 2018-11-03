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

int main(int argc, char* argv[])
{
	unsigned int own_br = atoi(argv[1]);
	unsigned int br_of_opponent = atoi(argv[2]);
	bool won = atoi(argv[3]);
	std::cout << fight(own_br, br_of_opponent, won);
	return 0;
}
