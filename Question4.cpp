#include <iostream>

void calculateCartons(int bottles)
{
    int xl = bottles / 48;
    bottles %= 48;
    
    int l = bottles / 24;
    bottles %= 24;
    
    int m = bottles / 12;
    bottles %= 12;
    
    int s = (bottles + 5) / 6;

    std::cout << xl << " xl, " << l << " large, " << m << " medium, " << s << " small" << std::endl;
}

int main() 
{
    int bottles;
    std::cout << "Enter the number of bottles: ";
    std::cin >> bottles;

    calculateCartons(bottles);  

    return 0;
}
