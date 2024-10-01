#include <iostream>
#include <vector>

std::vector<int> removeDuplicates(const std::vector<int>& input) 
{
    std::vector<int> uniqueElements;

    for (size_t i = 0; i < input.size(); ++i) 
    {
        if (i == 0 || input[i] != input[i - 1]) 
        {
            uniqueElements.push_back(input[i]);
        }
    }

    return uniqueElements;
}

int main() 
{
    int choice{0};
    std::cout<<"If you want custom input then press 1 or else anything else for default input "<<std::endl;
    std::cin>>choice;
    std::cin.ignore();
    if(choice!=1)
    {

      std::vector<int> input = {2, 3, 4, 4, 6, 7, 7};
      std::vector<int> output = removeDuplicates(input);

      for (int num : output) 
      {
          std::cout << num << " ";
      }
      std::cout << std::endl; 
    }
    else 
    {
      int size{0};
      std::cout<<"Enter the number of elements you want in array:"<<std::endl;
      std::cin>>size;
      std::cin.ignore();
      std::vector<int> input{};
      for(int i{0};i<size;i++)
      {
        int temp{};
        std::cin>>temp;
        input.push_back(temp);
      }
      std::vector<int> output=removeDuplicates(input);
      for (int num : output) 
      {
          std::cout << num << " ";
      }
      std::cout << std::endl; 

    }

    return 0;
}

