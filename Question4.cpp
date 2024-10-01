#include <iostream>
#include <vector>
#include <string>

void calculateCartons(int bottles) 
{
    std::vector<std::pair<std::string, int>> cartons = 
    {
        {"xl", 48},
        {"large", 24},
        {"medium", 12},
        {"small", 6}
    };

    std::vector<std::string> result;

    for (const auto& carton : cartons) 
    {
        int count = bottles / carton.second;
        if (count > 0) 
        {
            result.push_back(std::to_string(count) + " " + carton.first);
            bottles -= count * carton.second;
        }
    }

    for (size_t i = 0; i < result.size(); ++i) 
    {
        std::cout << result[i];
        if (i != result.size() - 1) 
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() 
{

    int bottles;
    std::cout << "Enter the number of bottles: ";
    std::cin >> bottles;

    calculateCartons(bottles);  

    return 0;
}

