int calc(unsigned int own_br, unsigned int br_of_opponent)
{
	int gainValue = 0;
	
	if (br_of_opponent > own_br) {
		gainValue = lgamma(sqrt(fdim(br_of_opponent, own_br)));
	} else {
		gainValue = log1p(9998 / fdim(own_br, br_of_opponent)) * 12.5;
	}
	
	
	return gainValue == 0 ? ++gainValue : gainValue;
}
