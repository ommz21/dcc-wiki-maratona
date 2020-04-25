#include <iostream>
#include <string>

void inicializar(int &linha, int &coluna, char &orientacao, char oinicial, int i, int j)
{
    orientacao = oinicial;
    linha = i;
    coluna = j;
}

int mover(int &linha, int &coluna, char &orientacao, char **mat, char instrucao, int n, int m)
{
    std::string direita = "NLSON";
    std::string esquerda = "NOSLN";
    if(instrucao == 'D')
        for (int i = 0; i < direita.size(); i++)
            if(orientacao == direita[i])
            {
                orientacao = direita[i+1];
                return 0;
            }
    if(instrucao == 'E')
        for (int i = 0; i < esquerda.size(); i++)
            if(orientacao == esquerda[i])
            {
                orientacao = esquerda[i+1];
                return 0;
            }
    switch (orientacao)
    {
    case 'N':
        if(linha == 0 || mat[linha-1][coluna] == '#')
            break;
        linha = linha - 1;
        if(mat[linha][coluna] == '*')
        {
            mat[linha][coluna] = '.';
            return 1;
        }
        break;
    case 'S':
        if(linha == n-1 || mat[linha+1][coluna] == '#')
            break;
        linha = linha + 1;
        if(mat[linha][coluna] == '*')
        {
            mat[linha][coluna] = '.';
            return 1;
        }
        break;

    case 'L':
        if(coluna == m-1 || mat[linha][coluna+1] == '#')
            break;
        coluna = coluna + 1;
        if(mat[linha][coluna] == '*')
        {
            mat[linha][coluna] = '.';
            return 1;
        }
        break;
    
    case 'O':
        if(coluna == 0 || mat[linha][coluna-1] == '#')
            break;
        coluna = coluna - 1;
        if(mat[linha][coluna] == '*')
        {
            mat[linha][coluna] = '.';
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}



int main()
{
    int n, m, quant_instru, linha, coluna, figuras;
    char orientacao;
    std::string instru;
    std::cin >> n >> m >> quant_instru;
    
    while(n >= 1 && m >= 1 && quant_instru >= 1)
    {
        figuras = 0;
        char **mat = new char *[n];
        for(int i = 0; i < n; i++)
            mat[i] = new char [m];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> mat[i][j];
                switch (mat[i][j])
                {
                case 'N':
                    inicializar(linha, coluna, orientacao, 'N', i, j);
                    mat[i][j] = '.'; 
                    break;
                case 'S':
                    inicializar(linha, coluna, orientacao, 'S', i, j);
                    mat[i][j] = '.';
                    break;
                case 'O':
                    inicializar(linha, coluna, orientacao, 'O', i, j);
                    mat[i][j] = '.';
                    break;
                case 'L':
                    inicializar(linha, coluna, orientacao, 'L', i, j);
                    mat[i][j] = '.';
                    break;
                default:
                    break;
                }
            }
        }
        std::cin >> instru;
        for (int i = 0; i < instru.size(); i++)
        {
            figuras += mover(linha, coluna, orientacao, mat, instru[i], n, m);
        }
        std::cout << figuras << std::endl;
        for(int i = 0; i < n; i++)
            delete [] mat[i];
        delete [] mat;
        std::cin >> n >> m >> quant_instru;
    }
    return 0;
}