#pragma once

#include <iostream>
#include <vector>
#include "vector_extension.h"
#include <unordered_map>

enum Type
{
    DELIMITER,
    INDENTIFIER,
    OPERATOR,
    ATRIBUTION,
    INTEGER,
    REAL,
    COMMENT,
    KEYWORD,
    NONE,
};

class Automaton
{
public:
    std::unordered_map<std::vector<int>, Type> StateToType = {{{63, 64, 66, 68, 69, 70}, Type::DELIMITER},
                                                              {{73}, Type::INDENTIFIER},
                                                              {{74, 65, 67, 78, 80, 81, 82, 84, 85, 86, 87}, Type::OPERATOR},
                                                              {{71}, Type::ATRIBUTION},
                                                              {{72}, Type::INTEGER},
                                                              {{75}, Type::REAL},
                                                              {{-2}, Type::COMMENT},
                                                              {{7, 10, 17, 18, 22, 26, 31, 38, 47, 51, 53, 57, 59, 62}, Type::KEYWORD}};

    int current_state = 0;
    std::vector<int> state_history;
    std::string char_history;

    void switchStateTo(char c);
    void stateIsAccepted(int current_state);
    void analyzeHistory(unsigned int &line, std::ofstream &file_output, std::ifstream &file_input);
    void reset();

    // debug

    void print_debug_info();
};