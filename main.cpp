#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Automaton.h"

bool is_first;

int main(int argc, char **argv)
{
    std::ifstream input_file;
    std::ofstream output_file;
    Automaton automaton;
    char c;
    unsigned int line = 1;
    bool add_line = false;

    // Trata a entrada dos parametros argc, argv
    if (argc > 1)
    {
        if (argc == 2)
        {
            input_file.open(argv[1]);
            output_file.open("a.txt");
        }
        else if (argc == 3)
        {
            input_file.open(argv[1]);
            output_file.open(argv[2]);
        }
        else
        {
            std::cerr << "ERROR: Wrong amount of parameters" << std::endl;
            std::cout << "Quantidade de parâmetros errados\nTente: analyse <input_file> <output_file>" << std::endl;
        }
    }

    // Verifica se os arquivos foram abertos normalmente

    if (!input_file)
    {
        std::cerr << "ERROR: Could not open file" << std::endl;
        std::cout << "Não foi possivel abrir o arquivo " << argv[1] << "\nTente novamente" << std::endl;
        return -1;
    }
    if (!output_file)
    {
        std::cerr << "ERROR: Could not create file" << std::endl;
        std::cout << "Não foi possivel criar o arquivo" << argv[2] << "\nTente novamente" << std::endl;
        return -1;
    }

    // Inicia a leitura dos caracteres

    while (!input_file.get(c).eof())
    {
        // Apenas é analisado caso o caracter lido seja um espaço ou quebra linha
        if ((c == ' ' || c == '\n') && automaton.current_state != -1)
        {
            add_line = false;

            // Se o único caracter lido for uma quebra de linha, Linha += 1
            if (c == '\n' && (automaton.char_history.size() == 0 || automaton.char_history.size() == 1))
                add_line = true;

            // Metodo para analisar a saida e o estado corrente
            automaton.analyzeHistory(line, output_file, input_file);

            if (add_line)
                line++;

            // automaton.print_debug_info();
            // Reseta o estado para 0 e limpa o histórico
            automaton.reset();
            continue;
        }

        // Troca de estado mediante ao caracter lido
        automaton.switchStateTo(c);
    }

    return 0;
}