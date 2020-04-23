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
    for i in range(2 * n - 1):
        try:
            int(expressao[i])
        except ValueError:
            operandos.append(expressao[i])
    try:
        acum = int(termos[0])
    except ValueError:
        termos = termos[1:]
        if simbolo == '-':
            acum = -int(termos[0])
        elif simbolo == '+':
            acum = int(termos[0])
    for i in range(len(operandos)):
        if operandos[i] == '+':
            acum += int(termos[i+1])
        elif operandos[i] == '-':
            acum -= int(termos[i+1])
    print("Teste %i" %cont)
    print(acum)
    print("")
    cont += 1
    n = int(input())