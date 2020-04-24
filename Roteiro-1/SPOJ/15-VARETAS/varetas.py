quant = int(input())

while quant:
    dicio = {}
    for i in range(quant):
        entrada = input().split(" ")
        dicio[entrada[0]] = entrada[1]
    quadrados = 0
    dois = False
    for i in dicio:
        quadrados += int(int(dicio[i]) / 4)
        if int(dicio[i]) % 4 != 0:
            if int(dicio[i]) % 4 >= 2:
                if dois:
                    dois = False
                    quadrados += 1
                else:
                    dois = True
    print(quadrados)
    quant = int(input())
