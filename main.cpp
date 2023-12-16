#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Automaton.h"

bool is_first;

int main()
{
    std::ifstream file_input("code.txt");
    std::ofstream file_output("analysed_code.txt");
    Automaton automaton;
    char c;
    unsigned int line = 0, counter_char = 0, max_counter_char = 0;

    while (!file_input.get(c).eof())
    {

        if (c == '\n' && max_counter_char < counter_char)
        {
            max_counter_char = counter_char;
            line++;
        }

        counter_char++;

        if ((c == ' ' || c == '\n') && automaton.current_state != -1)
        {
            automaton.analyzeHistory(line, file_output, file_input, counter_char);
            automaton.print_debug_info();
            automaton.reset();
            continue;
        }

        automaton.switchStateTo(c);
    }

    return 0;
}