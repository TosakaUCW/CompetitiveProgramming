from math import factorial


def C(n, m):
    if m > n:
        return 0
    return factorial(n) // factorial(m) // factorial(n - m)


def pow(x, k):
    res = 1
    while k > 0:
        if k & 1:
            res *= x
        x *= x
        k >>= 1
    return res


n = int(input())
k, Sum = 0, 0
a = []

for i in range(n):
    x = int(input())
    if x == -1:
        k += 1
    else:
        x -= 1
        Sum += x
        a.append(x)

ans = C(n - 2, Sum) * factorial(Sum)
for x in a:
    ans = ans // factorial(x)
ans *= pow(k, n - 2 - Sum)

print(ans)