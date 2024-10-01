#include <iostream>
#include <stdexcept>
#include <limits>

class Stack 
{
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) : capacity(size), top(-1) 
    {
        arr = new int[size];
    }

    ~Stack() 
    {
        delete[] arr;
    }

    void push(int item) 
    {
        if (isFull()) 
        {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = item;
        std::cout << "Pushed " << item << " to the stack.\n";
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            throw std::underflow_error("Stack underflow");
        }
        int item = arr[top--];
        std::cout << "Popped " << item << " from the stack.\n";
        return item;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            throw std::underflow_error("Stack is empty");
        }
        std::cout << "Top element is " << arr[top] << ".\n";
        return arr[top];
    }

    bool isEmpty() 
    {
        return top == -1;
    }

    bool isFull() 
    {
        return top == capacity - 1;
    }

    int size() 
    {
        return top + 1;
    }
};

void clearInputBuffer() 
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() 
{
    int stackSize;
    std::cout << "Enter the maximum size of the stack: ";
    std::cin >> stackSize;
    clearInputBuffer();

    Stack stack(stackSize);

    int choice;
    do {
        std::cout << "\n1. Push\n2. Pop\n3. Peek\n4. Check if empty\n5. Check if full\n6. Get size\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInputBuffer();

        try {
            switch (choice) 
            {
                case 1: 
                {
                    int item;
                    std::cout << "Enter the element to push: ";
                    std::cin >> item;
                    clearInputBuffer();
                    stack.push(item);
                    break;
                }
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.peek();
                    break;
                case 4:
                    std::cout << (stack.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                    break;
                case 5:
                    std::cout << (stack.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
                    break;
                case 6:
                    std::cout << "Current stack size: " << stack.size() << "\n";
                    break;
                case 7:
                    std::cout << "Exiting the program.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } 
        catch (const std::exception& e) 
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    } while (choice != 7);

    return 0;
}
