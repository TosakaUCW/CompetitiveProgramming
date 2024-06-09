a = int(input())
ans = 1
for i in range(a + 2, 2 * a + 1):
    ans *= i
for i in range(1, a + 1):
    ans //= i
print(int(ans))