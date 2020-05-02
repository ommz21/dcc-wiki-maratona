#include "stdio.h"

int busca_b(int i, int j, int vetor[], int elemento)
{
    int atual = ((j - i) / 2) + i;
    if (i == j)
    {
        atual = i;
        if(elemento != vetor[atual])
            return -1;
        else
            return atual;
    }
    else if(elemento == vetor[atual])
        return atual;
    else if(elemento < vetor[atual])
        return busca_b(i, atual - 1, vetor, elemento);
    else
        return busca_b(atual + 1, j, vetor, elemento);
}

int main()
{
    int n, q, elemento, indice;
    scanf("%d", &n);
    scanf("%d", &q);
    int *vetor = new int [n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elemento);
        vetor[i] = elemento;
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &elemento);
        indice = busca_b(0, n-1, vetor, elemento);
        printf("%d\n", indice);
    }
    delete [] vetor;
    return 0;
}
