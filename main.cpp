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
    unsigned int line = 1;
    bool add_line = false;

    while (!file_input.get(c).eof())
    {

        if ((c == ' ' || c == '\n') && automaton.current_state != -1)
        {
            add_line = false;
            if (c == '\n' && (automaton.char_history.size() == 0 || automaton.char_history.size() == 1))
                add_line = true;

            automaton.analyzeHistory(line, file_output, file_input);

            if (add_line)
                line++;

            automaton.print_debug_info();
            automaton.reset();
            continue;
        }

        automaton.switchStateTo(c);
        bool did_rollback = false;
    }

    return 0;
}