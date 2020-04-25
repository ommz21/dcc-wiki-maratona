def erro(lista):
    try:
        lista.sort(key = int)
    except Exception:
        lista[-1] = '0'
        lista.remove('0')
        lista = erro(lista)
    return lista

quant = int(input())

for j in range(quant):
    par = 0
    trinca = 0
    quadra = 0
    sequencia = 1
    pontuacao = 0
    mao = input().split(" ")
    mao = erro(mao)
    cartas = {'1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0, '9':0, '10':0, '11':0, '12':0, '13':0}
    for i in mao:
        cartas[i] += 1
    inicio = int(mao[0])
    atual = int(mao[1])
    for i in range(len(mao)-1):
        try:
            if int(mao[i]) + 1 != int(mao[i+1]):
                sequencia = 0
        except Exception:
            pass
    for i in cartas:
        if cartas[i] == 2:
            if par == 1:
                x = int(i)
            else:
                y = int(i)
            par += 1
        elif cartas[i] == 3:
            trinca += 1
            x = int(i)
        elif cartas[i] == 4:
            quadra += 1
            x = int(i)
    if sequencia == 1:
        pontuacao = int(mao[0]) + 200
    elif quadra == 1:
        pontuacao = x + 180
    elif trinca == 1 and par == 1:
        pontuacao = x + 160
    elif trinca == 1:
        pontuacao = x + 140
    elif par == 2:
        pontuacao = 3 * x + 2 * y + 20
    elif par == 1:
        pontuacao = y 
    print("Teste %i" %(j+1))
    print(pontuacao)
    print("")