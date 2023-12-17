#include "Automaton.h"
#include <fstream>

void branch_and_cut(Automaton *automaton, std::string s, std::ifstream &file_input, unsigned int &line)
{
    bool has_found = false;
    for (auto c : s)
    {
        if (automaton->char_history.find(c) != std::string::npos && automaton->char_history.size() != 1)
        {
            int rollback = 0;
            size_t char_index = automaton->char_history.find(c);
            size_t buffer_size = automaton->char_history.size();

            if (automaton->char_history.size() > 1 &&
                ((automaton->char_history[0] == ':' && automaton->char_history[1] == '=') || (automaton->char_history[0] == '<' && automaton->char_history[1] == '=') || (automaton->char_history[0] == '>' && automaton->char_history[1] == '=')))
            {
                rollback = buffer_size - 2;
            }
            else if (automaton->char_history[0] == '{')
            {
                rollback = buffer_size - automaton->char_history.find('}') - 1;
            }
            else
            {
                rollback = buffer_size - char_index - ((char_index == 0) ? 1 : 0);
            }

            for (int i = 0; i < rollback; i++)
            {
                file_input.unget();
                automaton->char_history.pop_back();
                automaton->state_history.pop_back();
            }
            if (!has_found)
            {
                file_input.unget();
                has_found = true;
            }

            automaton->current_state = automaton->state_history[automaton->state_history.size() - 1];
        }
    }
}

void Automaton::analyzeHistory(unsigned int &line, std::ofstream &file_output, std::ifstream &file_input)
{
    branch_and_cut(this, ":;+-*/()=<>.{", file_input, line);

    Type type = Type::NONE;
    for (const auto &pair : this->StateToType)
    {
        for (int i : pair.first)
        {
            if (i == this->current_state)
            {
                type = pair.second;
                break;
            }
        }
    }

    switch (type)
    {
    case Type::DELIMITER:
        file_output << "DELIMITER " << this->char_history << ' ' << line << std::endl;
        break;
    case Type::OPERATOR:
        file_output << "OPERATOR " << this->char_history << ' ' << line << std::endl;
        break;
    case Type::ATRIBUTION:
        file_output << "ATRIBUTION " << this->char_history << ' ' << line << std::endl;
        break;
    case Type::INDENTIFIER:
        file_output << "INDENTIFIER " << this->char_history << ' ' << line << std::endl;
        break;
    case Type::INTEGER:
        file_output << "INTEGER " << this->char_history << ' ' << line << std::endl;
        break;
    case Type::REAL:
        file_output << "REAL " << this->char_history << ' ' << line << std::endl;
        break;
    case Type::COMMENT:
        break;
    case Type::KEYWORD:
        file_output << "KEYWORD " << this->char_history << ' ' << line << std::endl;
        break;

    case Type::NONE:
    default:
        break;
    }
}

void Automaton::print_debug_info()
{
    std::cout << "Current state: " << this->current_state << std::endl;

    std::cout << "State History: ";
    for (auto i : this->state_history)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::cout << "Char History: ";
    for (auto c : this->char_history)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    std::cout << "/----/" << std::endl;
}

void Automaton::reset()
{
    this->current_state = 0;
    this->state_history.clear();
    this->char_history.clear();
}

void Automaton::switchStateTo(char c)
{
    // COMMENT

    if (this->current_state == -1 && c == '}')
    {
        this->current_state = -2;
        goto end;
    }

    if (c == '{' || this->current_state == -1)
    {
        this->current_state = -1;
        goto end;
    }

    // PROGRAM

    if (this->current_state == 0 && c == 'p')
    {
        this->current_state = 1;
        goto end;
    }
    else if (this->current_state == 1 && c == 'r')
    {
        this->current_state = 2;
        goto end;
    }
    else if (this->current_state == 2 && c == 'o')
    {
        this->current_state = 3;
        goto end;
    }
    else if (this->current_state == 3 && c == 'g')
    {
        this->current_state = 4;
        goto end;
    }
    else if (this->current_state == 4 && c == 'r')
    {
        this->current_state = 5;
        goto end;
    }
    else if (this->current_state == 5 && c == 'a')
    {
        this->current_state = 6;
        goto end;
    }
    else if (this->current_state == 6 && c == 'm')
    {
        this->current_state = 7;
        goto end;
    }

    // VAR

    if (this->current_state == 0 && c == 'v')
    {
        this->current_state = 8;
        goto end;
    }
    else if (this->current_state == 8 && c == 'a')
    {
        this->current_state = 9;
        goto end;
    }
    else if (this->current_state == 9 && c == 'r')
    {
        this->current_state = 10;
        goto end;
    }

    // INTEGER

    if (this->current_state == 0 && c == 'i')
    {
        this->current_state = 11;
        goto end;
    }
    else if (this->current_state == 11 && c == 'n')
    {
        this->current_state = 12;
        goto end;
    }
    else if (this->current_state == 12 && c == 't')
    {
        this->current_state = 13;
        goto end;
    }
    else if (this->current_state == 13 && c == 'e')
    {
        this->current_state = 14;
        goto end;
    }
    else if (this->current_state == 14 && c == 'g')
    {
        this->current_state = 15;
        goto end;
    }
    else if (this->current_state == 15 && c == 'e')
    {
        this->current_state = 16;
        goto end;
    }
    else if (this->current_state == 16 && c == 'r')
    {
        this->current_state = 17;
        goto end;
    }

    // IF

    if (this->current_state == 0 && c == 'i')
    {
        this->current_state = 11;
        goto end;
    }
    else if (this->current_state == 11 && c == 'f')
    {
        this->current_state = 18;
        goto end;
    }

    // THEN

    if (this->current_state == 0 && c == 't')
    {
        this->current_state = 19;
        goto end;
    }
    else if (this->current_state == 19 && c == 'h')
    {
        this->current_state = 20;
        goto end;
    }
    else if (this->current_state == 20 && c == 'e')
    {
        this->current_state = 21;
        goto end;
    }
    else if (this->current_state == 21 && c == 'n')
    {
        this->current_state = 22;
        goto end;
    }

    // ELSE

    if (this->current_state == 0 && c == 'e')
    {
        this->current_state = 23;
        goto end;
    }
    else if (this->current_state == 23 && c == 'l')
    {
        this->current_state = 24;
        goto end;
    }
    else if (this->current_state == 24 && c == 's')
    {
        this->current_state = 25;
        goto end;
    }
    else if (this->current_state == 25 && c == 'e')
    {
        this->current_state = 26;
        goto end;
    }

    // WHILE

    if (this->current_state == 0 && c == 'w')
    {
        this->current_state = 27;
        goto end;
    }
    else if (this->current_state == 27 && c == 'h')
    {
        this->current_state = 28;
        goto end;
    }
    else if (this->current_state == 28 && c == 'i')
    {
        this->current_state = 29;
        goto end;
    }
    else if (this->current_state == 29 && c == 'l')
    {
        this->current_state = 30;
        goto end;
    }
    else if (this->current_state == 30 && c == 'e')
    {
        this->current_state = 31;
        goto end;
    }

    // BOOLEAN

    if (this->current_state == 0 && c == 'b')
    {
        this->current_state = 32;
        goto end;
    }
    else if (this->current_state == 32 && c == 'o')
    {
        this->current_state = 33;
        goto end;
    }
    else if (this->current_state == 33 && c == 'o')
    {
        this->current_state = 34;
        goto end;
    }
    else if (this->current_state == 34 && c == 'l')
    {
        this->current_state = 35;
        goto end;
    }
    else if (this->current_state == 35 && c == 'e')
    {
        this->current_state = 36;
        goto end;
    }
    else if (this->current_state == 36 && c == 'a')
    {
        this->current_state = 37;
        goto end;
    }
    else if (this->current_state == 37 && c == 'n')
    {
        this->current_state = 38;
        goto end;
    }

    // PROCEDURE

    if (this->current_state == 0 && c == 'p')
    {
        this->current_state = 1;
        goto end;
    }
    else if (this->current_state == 1 && c == 'r')
    {
        this->current_state = 2;
        goto end;
    }
    else if (this->current_state == 2 && c == 'o')
    {
        this->current_state = 3;
        goto end;
    }
    else if (this->current_state == 3 && c == 'c')
    {
        this->current_state = 42;
        goto end;
    }
    else if (this->current_state == 42 && c == 'e')
    {
        this->current_state = 43;
        goto end;
    }
    else if (this->current_state == 43 && c == 'd')
    {
        this->current_state = 44;
        goto end;
    }
    else if (this->current_state == 44 && c == 'u')
    {
        this->current_state = 45;
        goto end;
    }
    else if (this->current_state == 45 && c == 'r')
    {
        this->current_state = 46;
        goto end;
    }
    else if (this->current_state == 46 && c == 'e')
    {
        this->current_state = 47;
        goto end;
    }

    // BEGIN

    if (this->current_state == 0 && c == 'b')
    {
        this->current_state = 32;
        goto end;
    }
    else if (this->current_state == 32 && c == 'e')
    {
        this->current_state = 48;
        goto end;
    }
    else if (this->current_state == 48 && c == 'g')
    {
        this->current_state = 49;
        goto end;
    }
    else if (this->current_state == 49 && c == 'i')
    {
        this->current_state = 50;
        goto end;
    }
    else if (this->current_state == 50 && c == 'n')
    {
        this->current_state = 51;
        goto end;
    }

    // END

    if (this->current_state == 0 && c == 'e')
    {
        this->current_state = 23;
        goto end;
    }
    else if (this->current_state == 23 && c == 'n')
    {
        this->current_state = 52;
        goto end;
    }
    else if (this->current_state == 52 && c == 'd')
    {
        this->current_state = 53;
        goto end;
    }

    // REAL

    if (this->current_state == 0 && c == 'r')
    {
        this->current_state = 54;
        goto end;
    }
    else if (this->current_state == 54 && c == 'e')
    {
        this->current_state = 55;
        goto end;
    }
    else if (this->current_state == 55 && c == 'a')
    {
        this->current_state = 56;
        goto end;
    }
    else if (this->current_state == 56 && c == 'l')
    {
        this->current_state = 57;
        goto end;
    }

    // DO

    if (this->current_state == 0 && c == 'd')
    {
        this->current_state = 58;
        goto end;
    }
    else if (this->current_state == 58 && c == 'o')
    {
        this->current_state = 59;
        goto end;
    }

    // NOT

    if (this->current_state == 0 && c == 'n')
    {
        this->current_state = 60;
        goto end;
    }
    else if (this->current_state == 60 && c == 'o')
    {
        this->current_state = 61;
        goto end;
    }
    else if (this->current_state == 61 && c == 't')
    {
        this->current_state = 62;
        goto end;
    }

    // DOT
    if (c == '.')
    {
        this->current_state = 63;
        goto end;
    }

    // COMMA

    if (c == ',')
    {
        this->current_state = 64;
        goto end;
    }

    // PLUS

    if (c == '+')
    {
        this->current_state = 65;
        goto end;
    }

    // SEMICOLON

    if (c == ';')
    {
        this->current_state = 66;
        goto end;
    }

    // ASTERISK

    if (c == '*')
    {
        this->current_state = 67;
        goto end;
    }

    // OPEN PARENTHESIS

    if (c == '(')
    {
        this->current_state = 68;
        goto end;
    }

    // CLOSE PARENTHESIS

    if (c == ')')
    {
        this->current_state = 69;
        goto end;
    }

    // ATRIBUTION

    if (c == ':')
    {
        this->current_state = 70;
        goto end;
    }
    else if (this->current_state == 70 && c == '=')
    {
        this->current_state = 71;
        goto end;
    }

    // EQUAL

    if (c == '=')
    {
        this->current_state = 74;
        goto end;
    }

    // >=

    if (c == '>')
    {
        this->current_state = 84;
        goto end;
    }
    else if (this->current_state == 84 && c == '=')
    {
        this->current_state = 85;
        goto end;
    }

    // <=

    if (c == '<')
    {
        this->current_state = 86;
        goto end;
    }
    else if (this->current_state == 86 && c == '=')
    {
        this->current_state = 87;
        goto end;
    }

    // NUMBERS

    if ((this->current_state == 0 || this->current_state == 72) && c == '0')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '1')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '2')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '3')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '4')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '5')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '6')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '7')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '8')
    {
        this->current_state = 72;
        goto end;
    }
    else if ((this->current_state == 0 || this->current_state == 72) && c == '9')
    {
        this->current_state = 72;
        goto end;
    }

    // REAL

    if ((this->current_state == 63 || this->current_state == 75) && c == '0')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '1')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '2')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '3')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '4')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '5')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '6')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '7')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '8')
    {
        this->current_state = 75;
        goto end;
    }
    else if ((this->current_state == 63 || this->current_state == 75) && c == '9')
    {
        this->current_state = 75;
        goto end;
    }

    // AND

    if (this->current_state == 0 && c == 'a')
    {
        this->current_state = 76;
        goto end;
    }
    else if (this->current_state == 76 && c == 'n')
    {
        this->current_state = 77;
        goto end;
    }
    else if (this->current_state == 77 && c == 'd')
    {
        this->current_state = 78;
        goto end;
    }

    // OR

    if (this->current_state == 0 && c == 'o')
    {
        this->current_state = 79;
        goto end;
    }
    else if (this->current_state == 79 && c == 'r')
    {
        this->current_state = 80;
        goto end;
    }

    // /

    if (this->current_state == 0 && c == '/')
    {
        this->current_state = 81;
        goto end;
    }

    // MINUS

    if (this->current_state == 0 && c == '-')
    {
        this->current_state = 82;
        goto end;
    }

    this->current_state = 73;

end:
    this->state_history.push_back(this->current_state);
    this->char_history.push_back(c);
}
