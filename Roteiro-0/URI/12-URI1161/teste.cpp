#include <iostream>

int main()
{
    int menor, maior, aux, i;
    long long int fats[20];
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
        if(std::cin.eof)
            break;
        if(menor > maior)
        {
            aux = maior;
            maior = menor;
            menor = aux;
        }
        menor;
        if(fats[menor] == 0)
        {
            i = menor;
            while(fats[i] == 0)
                i--;
            while(i < menor)
            {
                fats[i+1] = fats[i] * i+1;
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
                fats[i+1] = fats[i] * i+1;
                i++; 
            }
        }
        std::cout << fats[menor] + fats[maior] << std::endl;
    }
	return 0;
}

#include <iostream>
#include <map>

int main()
{
    bool addmen, addmai;
    int n, m, menor, maior, aux, aux2;
    long long int menfat, maifat, resp;
    std::map<int,long long int> mem;
    while(true)
    {
        addmen = true;
        addmai = true;
        menfat = 1;
        maifat = 1;
        resp = 2;
        std::cin >> n;
        std::cin >> m;
        if(std::cin.eof())
            break;
        if(n <= m)
        {
            menor = n;
            maior = m;
        }
        else
        {
            menor = m;
            maior = n;
        }
        aux = menor;
        aux2 = maior;
        for(auto x : mem)
        {
            if(x.first == menor)
            {
                menfat = x.second;
                addmen = false;
            }
            if(x.first == maior)
            {
                maifat = x.second;
                addmai = false;
            }
        }
        if(addmen)
        {
            while(menor > 1)
            {
                menfat *= menor;
                menor--;
            }
            mem[aux] = menfat;
        }
        if(addmai)
        {
            maifat = menfat;
            while(maior > aux)
            {
                maifat *= maior;
                maior--;
            }
            mem[aux2] = maifat;
        }
        resp = menfat + maifat;
        std::cout << resp << std::endl;
    }
	return 0;
}