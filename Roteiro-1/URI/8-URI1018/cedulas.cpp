#include <iostream>

int quant_notas(int &valor_acum, int valor_nota)
{
    int notas = 0;
    while(valor_acum >= valor_nota)
    {
        valor_acum -= valor_nota;
        notas++;
    }
    return notas;
}

int main()
{
    int valor_acum;
    std::cin >> valor_acum;
    std::cout << valor_acum << std::endl;
    std::cout << quant_notas(valor_acum, 100) << " nota(s) de R$ 100,00" << std::endl;
    std::cout << quant_notas(valor_acum, 50) << " nota(s) de R$ 50,00" << std::endl;
    std::cout << quant_notas(valor_acum, 20) << " nota(s) de R$ 20,00" << std::endl;
    std::cout << quant_notas(valor_acum, 10) << " nota(s) de R$ 10,00" << std::endl;
    std::cout << quant_notas(valor_acum, 5) << " nota(s) de R$ 5,00" << std::endl;
    std::cout << quant_notas(valor_acum, 2) << " nota(s) de R$ 2,00" << std::endl;
    std::cout << quant_notas(valor_acum, 1) << " nota(s) de R$ 1,00" << std::endl;
    return 0;
}