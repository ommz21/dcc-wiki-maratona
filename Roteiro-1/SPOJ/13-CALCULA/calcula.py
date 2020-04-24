import re

n = int(input())
cont = 1

while n:
    expressao = input()
    operandos = []
    simbolo = ""
    termos = re.split(r'[-+]', expressao)
    try:
        int(expressao[0])
    except ValueError:
        simbolo = expressao[0]
        expressao = expressao[1:]
    try:
        acum = float(termos[0])
    except ValueError:
        termos = termos[1:]
        if simbolo == '-':
            acum = -float(termos[0])
        elif simbolo == '+':
            acum = float(termos[0])
    for i in range(len(expressao)):
        try:
            int(expressao[i])
        except ValueError:
            if expressao[i] != '.':
                operandos.append(expressao[i])
    for i in range(len(operandos)):
        if operandos[i] == '+':
            acum += float(termos[i+1])
        elif operandos[i] == '-':
            acum -= float(termos[i+1])
    print("Teste %i" %cont)
    if int(acum)  == acum:
        print(int(acum))
    else:    
        print(acum)
    print("")
    cont += 1
    n = int(input())