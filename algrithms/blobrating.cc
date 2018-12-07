short calc(unsigned int own_br, unsigned int br_of_opponent)
{
        int gainValue = 0;
        int br_difference = own_br - br_of_opponent;
        if (br_difference < 0)
        {
                gainValue = pow(log10(-br_difference), 4);
        }
        else
        {
                gainValue = log1p(9998 / fdim(own_br, br_of_opponent));
        }
        if (own_br + gainValue >= 9999)
        {
                return 0;
        }
        if (gainValue > 999 || gainValue < 0) return 32;
        return gainValue == 0 ? ++gainValue : gainValue;
}
