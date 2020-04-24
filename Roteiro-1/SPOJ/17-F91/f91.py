def f91(n):
    if n >= 101:
        return n - 10
    else:
        return 91

n = int(input())
while n:
    resposta = f91(n)
    print("f91(%i) = %i" %(n, resposta))
    n = int(input())