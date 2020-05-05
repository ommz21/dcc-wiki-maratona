#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

int main()
{
    int testes, palavras, frases;
    std::istringstream stream;
    std::string linha, japao, port, pal, trad;
    std::cin >> testes;
    for (int i = 0; i < testes; i++)
    {
        std::map < std::string, std::string > dicio;
        std::cin >> palavras >> frases;
        std::vector < std::string > traduzidas(frases);
        for (int j = 0; j < palavras; j++)
        {
            std::cin >> japao;
            std::getline(std::cin >> std::ws, port);
            dicio[japao] = port;
        }
        for (int j = 0; j < frases; j++)
        {
            std::getline(std::cin >> std::ws, linha);
            trad = "";
            stream = std::istringstream(linha);
            while(std::getline(stream, pal, ' '))
            {
                if(dicio[pal] == "")
                    trad.append(pal);
                else
                    trad.append(dicio[pal]);
                trad.append(" ");
            }
            trad.erase(trad.end() - 1);
            traduzidas[j] = trad;
        }
        for(auto x : traduzidas)
            std::cout << x << std::endl;
    }
    return 0;
}
