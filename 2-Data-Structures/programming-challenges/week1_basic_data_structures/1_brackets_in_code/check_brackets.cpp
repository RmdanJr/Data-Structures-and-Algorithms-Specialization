#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
    Bracket(char type, int position) : type(type), position(position) {}

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    bool answered = false;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here
            Bracket b = Bracket(next, position + 1);
            opening_brackets_stack.push(b);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here
            if (!opening_brackets_stack.top().Matchc(next) || opening_brackets_stack.empty())
            {
                opening_brackets_stack.pop();
                std::cout << position + 1 << std::endl;
                answered = true;
                break;
            }
            opening_brackets_stack.pop();
        }
    }

    // Printing answer, write your code here
    if (!answered)
        if (opening_brackets_stack.empty())
            std::cout << "Success" << std::endl;
        else
            std::cout << opening_brackets_stack.top().position << std::endl;
    return 0;
}
