#include <iostream>
#include <vector>
#include <cmath>

unsigned int get_median(std::vector<int> points){
	int sum = 0;
	for(auto &val : points) sum += val;
	return sum / (points.size());
}

int main(){
	std::vector<int> points = {
		1000,
		2000,
		6000,
		4000
	};
	
	unsigned int own_points = 10000;
	unsigned int median = get_median(points); // 3250 in this example
	srand(median);
	int diff = median - own_points; // -6750 in this example
	
	
	if(own_points > median){
		std::cout << -log(-diff * 1e10);
	} else {
		std::cout << log(diff * 1e10);
	}
}
