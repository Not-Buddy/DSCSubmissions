#include <iostream>
#include <vector>
#include <algorithm>

std::string sortWordsByLength(const std::string& input) 
{
    std::vector<std::string> words{};
    std::string word{};

    for (char ch : input) 
    {
        if (ch == ' ') 
        {
            if (!word.empty()) 
            {
                words.push_back(word);
                word.clear();
            }
        } else 
        {
            word += ch;
        }
    }
    if (!word.empty()) 
    {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) 
    {
        return a.length() < b.length();
    });

    std::string result;
    for (size_t i = 0; i < words.size(); ++i) 
    {
        result += words[i];
        if (i != words.size() - 1) 
        {
            result += " ";
        }
    }

    return result;
}

int main()
{
    int choice{0};
    
    std::cout<<"If you want custom input press 1 or else default"<<std::endl;
    std::cin>>choice;
    std::cin.ignore();
    if(choice != 1)
    {
      std::string input = "This is a cool sentence";
      std::string output = sortWordsByLength(input);
      std::cout << output << std::endl;  
    }
    else 
    {
      std::cout<<"Enter your Sentence :"<<std::endl;
      std::string input{};
      std::getline(std::cin,input);
      std::string output = sortWordsByLength(input);
      std::cout<<output<<std::endl;
    }

    return 0;
}

