def linhap(atuali, inicioi):
    atualp = []
    for i,k in enumerate(inicioi):
        atualp.append(str(int((int(k) - int(atuali[i]) - int(atuali[i+1])) / 2)))
    return atualp

def concat(linhap, linhai):
    linha = []
    conti = 0
    contp = 0
    for i in range((len(linhap) + len(linhai))):
        if i % 2 != 0:
            linha.append(linhap[contp])
            contp += 1
        else:
            linha.append((linhai[conti]))
            conti += 1
    return linha

def apartir(linhab):
    linha = []
    for i in range(len(linhab) - 1):
        linha.append(int(linhab[i]) + int(linhab[i+1]))
    return linha

def exibir(linha):
    cont = 1
    for i in linha:
        if cont != len(linha):
            print("%i" %int(i), end = " ")
            cont += 1
        else:
            print("%i" %int(i))

n = int(input())
for i in range(n):    
    prii = input().split(" ")
    seg = []
    ter = []
    teri = input().split(" ")
    quar = []
    quin = []
    quini = input().split(" ")
    sex = []
    seti = []
    setii = input().split(" ")
    oit = []
    nona = []
    nonai = input().split(" ")
    nonap = []

    nonap = linhap(nonai, setii)
    nona = concat(nonap, nonai)
    oit = apartir(nona)
    seti = apartir(oit)
    sex = apartir(seti)
    quin = apartir(sex)
    quar = apartir(quin)
    ter = apartir(quar)
    seg = apartir(ter)

    exibir(prii)
    exibir(seg)
    exibir(ter)
    exibir(quar)
    exibir(quin)
    exibir(sex)
    exibir(seti)
    exibir(oit)
    exibir(nona)