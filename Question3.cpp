#include <iostream>
#include <vector>
#include <string>

std::string getDateFromDay(int day, int year) 
{
    std::vector<std::string> months = 
    {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };
    
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int month = 0;
    int daysInMonth[] = {31, isLeapYear ? 29 : 28, 31, 30, 31, 30, 
                         31, 31, 30, 31, 30, 31};

    while (day > daysInMonth[month]) 
    {
        day -= daysInMonth[month];
        month++;
    }

    return std::to_string(day) + " " + months[month] + ", " + std::to_string(year);
}

int main() 
{
    int day, year;
    std::cout << "Enter the day number: ";
    std::cin >> day;
    std::cout << "Enter the year: ";
    std::cin >> year;

    std::string date = getDateFromDay(day, year);
    std::cout << date << std::endl;  

    return 0;
}

