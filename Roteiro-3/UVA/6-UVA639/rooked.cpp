#include <iostream>
#include <vector>

int coloca (int linha, int col, int n, std::vector < std::vector < char > > &board)
{
    if (board[linha][col] == 'X')
        return 0;
    for (int i = linha; i < n; i++)
    {
        if(board[i][col] == 'R')
            return 0;
        else if (board[i][col] == 'X')
            break;
    }
    for (int i = linha; i >= 0; i--)
    {
        if(board[i][col] == 'R')
            return 0;
        else if (board[i][col] == 'X')
            break;
    }
    for (int i = col; i < n; i++)
    {
        if(board[linha][i] == 'R')
            return 0;
        else if (board[linha][i] == 'X')
            break;
    }
    for (int i = col; i >= 0; i--)
    {
        if(board[linha][i] == 'R')
            return 0;
        else if (board[linha][i] == 'X')
            break;
    }
    board[linha][col] = 'R';
    return 1;
}

int comeca(int lini, int cini, int n, std::vector < std::vector < char > > board)
{
    int cont = 1;
    if (board[lini][cini] == 'X')
        return 0;
    board[lini][cini] = 'R';
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cont += coloca(i, j, n, board);
    return cont;
}

int main()
{
    int n, quant, max;
    std::vector < std::vector < char > > board, board2;
    while (std::cin >> n && n != 0)
    {
        quant = 0;
        board.resize(n);
        for (int i = 0; i < n; i++)
            board[i].resize(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                std::cin >> board[i][j]; 
        max = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                quant = comeca(i, j, n, board);
                if(quant > max)
                    max = quant;
            }
        std::cout << max << std::endl;            
    }
    return 0;
}