#include <iostream>

int main()
{
    int quant, capac, sai, entra, atual;
    bool resposta = false;
    atual = 0;
    std::cin >> quant >> capac;
    for(int i = 0; i < quant; i++)
    {
        std::cin >> sai >> entra;
        atual += (entra - sai);
        if(atual > capac)
            resposta = true;
    }
    if(resposta)
        std::cout << "S";
    else
        std::cout << "N";
    std::cout << std::endl;
    return 0;
}
