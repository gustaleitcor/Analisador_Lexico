#pragma once

#include <iostream>
#include <vector>

class Automaton
{
public:
    std::vector<int> accepted_states;
    int current_state = 0;
    std::vector<int> history;

    void switchState(char c);
    void stateIsAccepted(int current_state);
};