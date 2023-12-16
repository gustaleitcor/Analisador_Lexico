#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Automaton.h"

int main()
{
    std::ifstream file_input("code.txt");
    std::ofstream file_output("analysed_code.txt");
    Automaton automaton;
    char c;
    unsigned int line = 1;

    while (!file_input.get(c).eof())
    {

        if (c == '\n')
        {
            line++;
            std::cout << "linha" << std::endl; // a linha está bugada
        }

        if ((c == ' ' || c == '\n') && automaton.current_state != -1)
        {
            automaton.analyzeHistory(line, file_output, file_input);
            automaton.print_debug_info();
            automaton.reset();
            continue;
        }

        automaton.switchStateTo(c);
    }
    return 0;
}