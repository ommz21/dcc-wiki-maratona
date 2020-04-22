entrada = input()
lista = entrada.split(" ")
dig = lista[0]
num = lista[1]

while dig != "0" and num != "0":
    num = num.replace(dig, "!")
    lista = num.split("!")
    saida = ""
    for i in lista:
        saida += i
    if saida == "":
        saida = "0"
    print(int(saida))
    entrada = input()
    lista = entrada.split(" ")
    dig = lista[0]
    num = lista[1]