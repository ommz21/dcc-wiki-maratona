#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool sortsecond(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    std::string linha;
    int quant, menor, instancia, tam;
    instancia = 1;
    while(true)
    {
        try
        {
            std::cin >> quant;
            if(quant < 1 || quant > 100 || std::cin.fail() || std::cin.eof())
                throw std::exception();
        }
        catch(const std::exception& e)
        {
            std::cin.clear();
        	std::cin.ignore(1000, '\n');
        	return 0;
        }
        std::vector< std::pair< std::string, int > >  alunos(quant);
        std::vector< std::string > iguais(quant);
        for (int i = 0; i < quant; i++)
            std::cin >> alunos[i].first >> alunos[i].second;
        sort(alunos.begin(), alunos.end(), sortsecond);
        menor = alunos[0].second;
        iguais[0] = alunos[0].first;
        for (int i = 1; i < quant; i++)
        {
            if(alunos[i].second == menor)
                iguais[i] = alunos[i].first;
            else
                break;
        }                    
        sort(iguais.begin(), iguais.end());
        std::cout << "Instancia " << instancia << std::endl;
        std::cout << iguais[quant-1] << std::endl << std::endl;
        instancia++;
    }
   return 0;
}
