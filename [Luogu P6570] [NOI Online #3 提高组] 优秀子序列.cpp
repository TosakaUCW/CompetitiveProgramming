#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int P = 1e9 + 7;

int n, m, max, ans = 1;
int buk[N], f[N], phi[N];
int prime[N], cnt;

void compute(int x)
{
    phi[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (phi[i] == 0)
            prime[++cnt] = i, phi[i] = i - 1;
        for (int j = 1; j <= cnt and prime[j] * i <= x; j++)
            if (i % prime[j] == 0)
            {
                phi[prime[j] * i] = prime[j] * phi[i];
                break;
            }
            else
                phi[prime[j] * i] = (prime[j] - 1) * phi[i];
    }
}

signed main()
{
    n = read();
    for (int i = 1, x; i <= n; i++)
        buk[x = read()]++, max = std::max(max, x);
    while ((1 << m) <= max)
        m++;
    compute(1 << m), f[0] = 1;
    for (int i = 1; i <= (1 << m); i++)
        for (int s = i;; s = (s - 1) & i)
        {
            int t = i ^ s;
            if (s < t)
                break;
            f[i] = (f[i] + f[t] * buk[s] % P) % P;
        }
    for (int i = 1; i <= (1 << m); i++)
        ans = (ans + f[i] * phi[i + 1] % P) % P;
    for (int i = 1; i <= buk[0]; i++)
        ans = ans * 2 % P;
    return printf("%lld", ans), 0;
}