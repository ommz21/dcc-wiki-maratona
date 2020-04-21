oitavas = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P']
quartas = []
semi = []
final = []
cont = 0
for i in range(8):
    placar = input().split(" ")
    if int(placar[0]) > int(placar[1]):
        quartas.append(oitavas[i+cont])
    else:
        quartas.append(oitavas[i+cont+1])
    cont += 1
cont = 0
for i in range(4):
    placar = input().split(" ")
    if int(placar[0]) > int(placar[1]):
        semi.append(quartas[i+cont])
    else:
        semi.append(quartas[i+cont+1])
    cont += 1
cont = 0
for i in range(2):
    placar = input().split(" ")
    if int(placar[0]) > int(placar[1]):
        final.append(semi[i+cont])
    else:
        final.append(semi[i+cont+1])
    cont += 1
placar = input().split(" ")
if int(placar[0]) > int(placar[1]):
    print(final[0])
else:
    print(final[1])