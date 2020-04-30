#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    int testes;
    std::string seq, bracel, bracelr;
    std::cin >> testes;
    bool denovo, resposta;
    int cont;
    for (int i = 0; i < testes; i++)
    {
        cont = 0;
        denovo = false;
        resposta = false;
        std::cin >> seq >> bracel;
        bracelr = bracel;
        for (int j = 0; j < bracelr.size() / 2; j++)
            std::swap(bracelr[j], bracelr[bracelr.size() - 1 - j]);
        for (int j = 0; j < bracel.size(); j++)
        {
            if(cont == seq.size())
            {
                resposta = true;
                cont = 0;
                break;
            }
            if(bracel[j] == seq[cont])
                cont++;
            else
                cont = 0;
            if((j == bracel.size() - 1) && (cont > 0))
            {
                j = -1;
                denovo = true;
            }   
            if((denovo) && (cont == 0))
                break;
        }
        if(!resposta)
            for (int j = 0; j < bracelr.size(); j++)
            {
                if(cont == seq.size())
                {
                    resposta = true;
                    cont = 0;
                    break;
                }
                if(bracelr[j] == seq[cont])
                    cont++;
                else
                    cont = 0;
                if((j == bracelr.size() - 1) && (cont > 0))
                {
                    j = -1;
                    denovo = true;
                }
                if((denovo) && (cont == 0))
                    break;
            }
        if(resposta)
            std::cout << "S";
        else
            std::cout << "N";
        std::cout << std::endl;
    }    
    return 0;
}
