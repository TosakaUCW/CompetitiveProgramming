n = int(input())
f = [1, 3]
for i in range(2, n):
    f.append(f[i - 1] + f[i - 2])
ans = f[n - 1] * f[n - 1]
if (n % 2 == 0):
    ans -= 4
print(ans)