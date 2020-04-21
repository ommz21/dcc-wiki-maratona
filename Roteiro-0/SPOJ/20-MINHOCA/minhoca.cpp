#include <iostream>

int main()
{
    int lin, col, num, maior;
    while(true)
    {
        maior = 0;
        std::cin >> lin;
        std::cin >> col;
        
        if(std::cin.eof())
    		return 0;
        if(lin == 0 && col == 0)
            return 0;

        int *linhas = new int [lin];
        int *colunas = new int [col];
        for(int i = 0; i < lin; i++)
            linhas[i] = 0;
        for(int i = 0; i < col; i++)
            colunas[i] = 0;
            
        for(int i = 0; i < lin; i++)
        {
            for(int j = 0; j < col; j++)
            {
                std::cin >> num;
                colunas[j] += num;
                linhas[i] += num;
            }
        }

        for(int i = 0; i < lin; i++)
            if(linhas[i] > maior)
                maior = linhas[i];
        
        for(int i = 0; i < col; i++)
            if(colunas[i] > maior)
                maior = colunas[i];

        std::cout << maior << std::endl << std::endl;
        delete [] linhas;
        delete [] colunas;
    }
	return 0;
}