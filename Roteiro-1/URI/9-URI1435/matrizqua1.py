def cria_mat(ordem, valor):
    matriz = []
    for i in range(ordem):
        linhas = []
        for j in range(ordem):
            linhas.append(valor)
        matriz.append(linhas)
    return matriz

def exibe_mat(matriz):
    for i in range(len(matriz)):
        for j in range(len(matriz)):
            print("%3i" %matriz[i][j], end = "")
            if j != len(matriz) - 1:
                print(" ", end = "")
            else:
                print("")
    print("")

def mesclar_mat(matriz1, matriz2):
    resultado = matriz1
    for i in range(len(matriz2)):
        for j in range(len(matriz2)):
            resultado[i+1][j+1] = matriz2[i][j]
    return resultado

ordem = int(input())
while(ordem != 0):
    ordens = []
    matrizes = []
    cont = 0
    aux = ordem
    while aux > 0:
        cont += 1
        aux -= 2
        ordens.append(cont)
    ordens.reverse()
    ultima_ordem = ordem - 2 * (len(ordens) - 1)
    for i in range(len(ordens)):
        matrizes.append(cria_mat(ultima_ordem, ordens[i]))
        ultima_ordem += 2
    for i in range(len(matrizes)-1):
        matrizes[i+1] = mesclar_mat(matrizes[i+1], matrizes[i])
    exibe_mat(matrizes[-1])
    ordem = int(input())