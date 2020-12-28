#include <iostream>
#include <sstream>
#include <stack>
#include <cassert>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string NormalExpression;
    std::cout << "Выражение в обычной записи: ";
    std::getline(std::cin, NormalExpression);
    std::stringstream ss(NormalExpression);

    std::stack<char> Polska;

    std::cout << "Выражение в обратной польской записи: ";

    std::string token;
    while (!ss.eof())
    {
        ss >> token;
        try {
            std::cout << std::stod(token) << ' ';
        }
        catch (...)
        {
            switch (token[0])
            {
            case '+':
            case '-':
            case '*':
            case '/':
                Polska.push(token[0]);
                break;
            }
        }
    }

    while (!Polska.empty())
    {
        std::cout << Polska.top() << ' ';
        Polska.pop();
    }

}
