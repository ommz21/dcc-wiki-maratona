#include "stdio.h"
#include "stdlib.h"

int busca_b(long long int i, long long int j, long long int *vetor, long long int elemento)
{
    if (i <= j)
    {
        int atual = ((j - i) / 2) + i;
        if(elemento == vetor[atual] && elemento != vetor[atual-1])
            return atual;
        else if(elemento <= vetor[atual])
            return busca_b(i, atual - 1, vetor, elemento);
        else
            return busca_b(atual + 1, j, vetor, elemento);
    }
    else
        return -1;
}

int main()
{
    long long int n, q, elemento, indice, *vetor;;
    scanf("%d", &n);
    scanf("%d", &q);
    vetor = (long long int*) malloc(n * sizeof(long long int));
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
    free(vetor);
    return 0;
}
