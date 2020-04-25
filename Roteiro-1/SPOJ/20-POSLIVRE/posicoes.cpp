#include <iostream>

int preencher(int **mat, int x1, int y1, int x2, int y2)
{
    int direita, esquerda, cima, baixo, deltax, deltay, cont;
    cont = 0;
    if(x1 >= x2)
    {
        direita = x1;
        esquerda = x2;
    }
    else
    {
        direita = x2;
        esquerda = x1;
    }
    if(y1 >= y2)
    {
        baixo = y1;
        cima = y2;
    }
    else
    {
        baixo = y2;
        cima = y1;
    }
    deltax = direita - esquerda;
    deltay = baixo - cima;
    for(int i = cima-1; i <= baixo-1; i++)
        for(int j = esquerda-1; j <= direita-1; j++)
            if(mat[i][j] == 0)
            {
                mat[i][j] = 1;
                cont++;
            }
    return cont;
}

int main()
{
    int colunas, linhas, partes;
    int x1, x2, y1, y2, total, ocupados;

    std::cin >> colunas >> linhas >> partes;
    
    while(colunas != 0 || linhas != 0 || partes != 0)
    {
        total = linhas * colunas;
        ocupados = 0;
        int **mat = new int *[linhas];
        for(int i = 0; i < linhas; i++)
            mat[i] = new int [colunas];

        for(int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                mat[i][j] = 0;
            

        for (int i = 0; i < partes; i++)
        {
            std::cin >> x1 >> y1 >> x2 >> y2;    
            ocupados += preencher(mat, x1, y1, x2, y2);
        }
        if(ocupados == total)
            std::cout << "There is no empty spots." << std::endl;
        else if(ocupados + 1 == total)
            std::cout << "There is one empty spot." << std::endl;
        else
            std::cout << "There are " << total - ocupados << " empty spots." << std::endl;
        
        for(int i = 0; i < linhas; i++)
            delete [] mat[i];
        delete [] mat;

        std::cin >> colunas >> linhas >> partes;
    }
    return 0;
}