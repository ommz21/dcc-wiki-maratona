#include <iostream>
#include <vector>
#include <string>

int main()
{
    int a, b, c;
    std::vector<char> saida;
    std::string linha;
    while(std::getline(std::cin, linha) && !linha.empty())
    {
        a = linha[0];
        b = linha[2];
        c = linha[4];
        if(a != b && a != c)
            saida.push_back('A');
        else if(b != a && b != c)
            saida.push_back('B');
        else if(c != a && c != b)
            saida.push_back('C');
        else
            saida.push_back('*');
    }
    for(auto x : saida)
        std::cout << x << std::endl;
    return 0;
}