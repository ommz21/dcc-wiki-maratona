fibo = [0, 1]
n = int(input())
if n < 0:
    pass
elif n <= 2:
    for i in range(n):
        print(fibo[i], end = " ")
else:
    print(fibo[0], fibo[1], end = " ")
    for i in range(2, n):
        fibo.append(fibo[i-1] + fibo[i-2])
        if i != n-1:
            print(fibo[i], end = " ")
        else:
            print(fibo[i])
