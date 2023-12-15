#include "Automaton.h"

void Automaton::switchState(char c)
{
    // PROGRAM

    if (this->current_state == 0 && c == 'p')
    {
        this->current_state = 1;
    }
    else if (this->current_state == 1 && c == 'r')
    {
        this->current_state = 2;
    }
    else if (this->current_state == 2 && c == 'o')
    {
        this->current_state = 3;
    }
    else if (this->current_state == 3 && c == 'g')
    {
        this->current_state = 4;
    }
    else if (this->current_state == 4 && c == 'r')
    {
        this->current_state = 5;
    }
    else if (this->current_state == 5 && c == 'a')
    {
        this->current_state = 6;
    }
    else if (this->current_state == 6 && c == 'm')
    {
        this->current_state = 7;
    }

    // VAR

    if (this->current_state == 0 && c == 'v')
    {
        this->current_state = 8;
    }
    else if (this->current_state == 8 && c == 'a')
    {
        this->current_state = 9;
    }
    else if (this->current_state == 9 && c == 'r')
    {
        this->current_state = 10;
    }

    // INTEGER

    if (this->current_state == 0 && c == 'i')
    {
        this->current_state = 11;
    }
    else if (this->current_state == 11 && c == 'n')
    {
        this->current_state = 12;
    }
    else if (this->current_state == 12 && c == 't')
    {
        this->current_state = 13;
    }
    else if (this->current_state == 13 && c == 'e')
    {
        this->current_state = 14;
    }
    else if (this->current_state == 14 && c == 'g')
    {
        this->current_state = 15;
    }
    else if (this->current_state == 15 && c == 'e')
    {
        this->current_state = 16;
    }
    else if (this->current_state == 16 && c == 'r')
    {
        this->current_state = 17;
    }

    // IF

    if (this->current_state == 0 && c == 'i')
    {
        this->current_state = 11;
    }
    else if (this->current_state == 11 && c == 'f')
    {
        this->current_state = 18;
    }

    // THEN

    if (this->current_state == 0 && c == 't')
    {
        this->current_state = 19;
    }
    else if (this->current_state == 19 && c == 'h')
    {
        this->current_state = 20;
    }
    else if (this->current_state == 20 && c == 'e')
    {
        this->current_state = 21;
    }
    else if (this->current_state == 21 && c == 'n')
    {
        this->current_state = 22;
    }

    // ELSE

    if (this->current_state == 0 && c == 'e')
    {
        this->current_state = 23;
    }
    else if (this->current_state == 23 && c == 'l')
    {
        this->current_state = 24;
    }
    else if (this->current_state == 24 && c == 's')
    {
        this->current_state = 25;
    }
    else if (this->current_state == 25 && c == 'e')
    {
        this->current_state = 26;
    }

    // WHILE

    if (this->current_state == 0 && c == 'w')
    {
        this->current_state = 27;
    }
    else if (this->current_state == 27 && c == 'h')
    {
        this->current_state = 28;
    }
    else if (this->current_state == 28 && c == 'i')
    {
        this->current_state = 29;
    }
    else if (this->current_state == 29 && c == 'l')
    {
        this->current_state = 30;
    }
    else if (this->current_state == 30 && c == 'e')
    {
        this->current_state = 31;
    }

    // BOOLEAN

    if (this->current_state == 0 && c == 'b')
    {
        this->current_state = 32;
    }
    else if (this->current_state == 32 && c == 'o')
    {
        this->current_state = 33;
    }
    else if (this->current_state == 33 && c == 'o')
    {
        this->current_state = 34;
    }
    else if (this->current_state == 34 && c == 'l')
    {
        this->current_state = 35;
    }
    else if (this->current_state == 35 && c == 'e')
    {
        this->current_state = 36;
    }
    else if (this->current_state == 36 && c == 'a')
    {
        this->current_state = 37;
    }
    else if (this->current_state == 37 && c == 'n')
    {
        this->current_state = 38;
    }

    // PROCEDURE

    if (this->current_state == 0 && c == 'p')
    {
        this->current_state = 1;
    }
    else if (this->current_state == 1 && c == 'r')
    {
        this->current_state = 2;
    }
    else if (this->current_state == 2 && c == 'o')
    {
        this->current_state = 3;
    }
    else if (this->current_state == 3 && c == 'c')
    {
        this->current_state = 42;
    }
    else if (this->current_state == 42 && c == 'e')
    {
        this->current_state = 43;
    }
    else if (this->current_state == 43 && c == 'd')
    {
        this->current_state = 44;
    }
    else if (this->current_state == 44 && c == 'u')
    {
        this->current_state = 45;
    }
    else if (this->current_state == 45 && c == 'r')
    {
        this->current_state = 46;
    }
    else if (this->current_state == 46 && c == 'e')
    {
        this->current_state = 47;
    }

    // BEGIN

    if (this->current_state == 0 && c == 'b')
    {
        this->current_state = 32;
    }
    else if (this->current_state == 32 && c == 'e')
    {
        this->current_state = 48;
    }
    else if (this->current_state == 48 && c == 'g')
    {
        this->current_state = 49;
    }
    else if (this->current_state == 49 && c == 'i')
    {
        this->current_state = 50;
    }
    else if (this->current_state == 50 && c == 'n')
    {
        this->current_state = 51;
    }

    // END

    if (this->current_state == 0 && c == 'e')
    {
        this->current_state = 23;
    }
    else if (this->current_state == 23 && c == 'n')
    {
        this->current_state = 52;
    }
    else if (this->current_state == 52 && c == 'd')
    {
        this->current_state = 53;
    }

    // REAL

    if (this->current_state == 0 && c == 'r')
    {
        this->current_state = 54;
    }
    else if (this->current_state == 54 && c == 'e')
    {
        this->current_state = 55;
    }
    else if (this->current_state == 55 && c == 'a')
    {
        this->current_state = 56;
    }
    else if (this->current_state == 56 && c == 'l')
    {
        this->current_state = 57;
    }

    // DO

    if (this->current_state == 0 && c == 'd')
    {
        this->current_state = 58;
    }
    else if (this->current_state == 58 && c == 'o')
    {
        this->current_state = 59;
    }

    // NOT

    if (this->current_state == 0 && c == 'n')
    {
        this->current_state = 60;
    }
    else if (this->current_state == 60 && c == 'o')
    {
        this->current_state = 61;
    }
    else if (this->current_state == 61 && c == 't')
    {
        this->current_state = 62;
    }

    this->history.push_back(this->current_state);
}
