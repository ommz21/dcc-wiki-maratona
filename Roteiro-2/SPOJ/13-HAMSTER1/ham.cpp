#include <iostream>
#include <vector>
#include <math.h>
//#include <iomanip>

float calc(float k1, float k2, float angulo)
{
    return (float)(k1 * sin(2. * angulo)) + (k2 * sin(angulo) * sin(angulo));
}

float busca(std::vector < float > &angulos, float i, float k, float k1, float k2)
{
    float angulo, epi, media;
    media = i + ((k-i) / 2);
    epi = media - i;
    if (epi < 0.000000009)
        return i;
    else if(calc(k1, k2, i) > calc(k1, k2, k))
        angulo = busca(angulos, i, media, k1, k2);
    else
        angulo = busca(angulos, media, k, k1, k2);
    return angulo;
}

int main()
{
    int testes, cont, ki1, ki2;
    float angulo, k1, k2, vel, pontos;
    float limite = acos(-1) / 2.;
    std::vector < float > angulos(1572);
    cont = 0;
    angulos[cont] = 0;
    for (float i = 0.001; i <= limite; i += 0.001)
    {
        angulos[++cont] = i;
    }
    angulos[cont+1] = limite;
    //std::cin >> testes;
    scanf("%d", &testes);
    for (int i = 0; i < testes; i++)
    {
        //std::cin >> vel >> ki1 >> ki2;
        scanf("%f %d %d", &vel, &ki1, &ki2);
        k1 = ((float)(ki1) * pow(vel, 2)) / 10.;
        k2 = ((float)ki2 * pow(vel, 2)) / 20;
        angulo = busca(angulos, 0.0, limite, k1, k2);
        pontos = calc(k1, k2, angulo);
        printf("%.3f %.3f \n", angulo, pontos);
        //std::cout << std::fixed << std::showpoint;
        //std::cout << std::setprecision(3);
        //std::cout << angulo << ' ' << calc(k1, k2, angulo) << std::endl;
    }    
    return 0;
}