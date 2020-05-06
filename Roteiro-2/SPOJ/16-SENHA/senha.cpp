#include <iostream>
#include <set>
#include <vector>
#include <string>

int main()
{
    int testes, a, b, anteriora, anteriorb, cont2, cont3, cont, maior;
    std::string dig,  digitados = "";
    std::vector < int > vetor(10);
    cont2 = 0;
    while (std::cin >> testes && testes)
    {
        std::set < std::pair < int, std::pair < int, int > > > senha;
        for (int j = 0; j < testes; j++)
        {
            std::pair < int, std::pair < int ,int > > par;
            for (int i = 0; i < 10; i++)
                std::cin >> vetor[i];
            for (int i = 1; i <= 6; i++)
            {
                cont =  0;
                std::cin >> dig;
                digitados.append(dig);
                for (int k = 'A'; k <= 'E'; k++)
                {
                    if (dig[0] == k)
                        break;
                    cont += 2;
                }
                par.first = i;
                if (vetor[cont] <= vetor[cont+1])
                {
                    par.second.first = vetor[cont];
                    par.second.second = vetor[cont+1];    
                }
                else
                {
                    par.second.first = vetor[cont+1];
                    par.second.second = vetor[cont];
                }
                senha.insert(par);
            }
        }
        std::cout << "Teste " << cont2+1 << std::endl;
        for (int i = 1; i <= 6; i++)
        {
            cont = 0;
            cont3 = 0;
            anteriora = -1;
            anteriorb = -1;
            for(auto x : senha)
            {
                a = x.second.first;
                b = x.second.second;
                if(x.first > i)
                    break;
                if(x.first == i)
                {
                    if(cont == 0)
                    {
                        anteriora = -1;
                        anteriorb = -1;
                    }
                    if(anteriora == a || anteriorb == a || anteriora == -1)
                        cont++;
                    if(anteriorb == b || anteriorb == b || anteriorb == -1)
                        cont3++;
                    anteriora = a;
                    anteriorb = b;
                }
                if(cont > 1 || cont3 > 1)
                    break;
            }
            if(cont >= cont3)
                maior = a;
            else
                maior = b;
            std::cout << maior;
            if(i == 6)
                std::cout << std::endl;
            else
                std::cout << " ";
        }
        std::cout << std::endl;
        cont2++;
    }
    return 0;
}