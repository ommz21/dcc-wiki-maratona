#include <iostream>

int main()
{
    int menor, maior, aux, i;
    unsigned long long int fats[20];
    fats[0] = 1;
    fats[1] = 1;  
    for(i = 2; i <= 20; i++)
    {
        fats[i] = 0;
    }
    while(true)
    {
        std::cin >> menor;
        std::cin >> maior;
        if(std::cin.eof())
            break;
        if(menor > maior)
        {
            aux = maior;
            maior = menor;
            menor = aux;
        }
        if(fats[menor] == 0)
        {
            i = menor;
            while(fats[i] == 0)
                i--;
            while(i < menor)
            {
                fats[i+1] = fats[i] * (i+1);
                i++; 
            }
        }
        if(fats[maior] == 0)
        {
            i = maior;
            while(fats[i] == 0)
                i--;
            while(i < maior)
            {
                fats[i+1] = fats[i] * (i+1);
                i++; 
            }
        }
        std::cout << fats[menor] + fats[maior] << std::endl;
    }
	return 0;
}
