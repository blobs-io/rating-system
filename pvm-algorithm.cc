#include <iostream>
#include <cmath>
#include <string>


unsigned int fight(unsigned int own_br, unsigned int br_of_opponent, bool won){
    int gainValue = 0;
    int br_difference = own_br - br_of_opponent; // positive if own_br > br_of_opponent   | -98999
    if(won){
        if(br_difference < 0){
            gainValue = pow(log10(-br_difference), 4);
        } else {
            gainValue = pow(log10(-br_difference), 4);
        }
    }
    
    return gainValue;
}

int main(){
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
    
    std::cout << fight(own_br, br_of_opponent, won);

    int a;
    std::cin >> a;
}
