#include <iostream>
#include "Automaton.h"
#include <fstream>
#include <unordered_map>

int main()
{
    std::ifstream file("code.txt");
    Automaton automaton;
    char c;

    while (!file.get(c).eof())
    {
        if (c == ' ' || c == '\n')
        {
            std::cout << automaton.current_state << std::endl;
            automaton.current_state = 0;
            for (auto i : automaton.history)
            {
                std::cout << i << ' ';
            }
            std::cout << std::endl;
            automaton.history.clear();
            continue;
        }

        automaton.switchState(c);
    }
    return 0;
}