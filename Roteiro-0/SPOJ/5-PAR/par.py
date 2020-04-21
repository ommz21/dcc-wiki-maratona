rodadas = int(input())
cont = 1
while rodadas != 0:
    resultado = []
    par = input()
    impar = input()    
    for i in range(rodadas):
        lista = input().split(" ")
        soma = int(lista[0]) + int(lista[1])
        if soma % 2 == 0:
            resultado.append(par)
        else:
            resultado.append(impar)
    print("Teste %i" % cont)
    for i in range(rodadas):
        print(resultado[i])
    print(" ")
    rodadas = int(input())
    cont += 1
