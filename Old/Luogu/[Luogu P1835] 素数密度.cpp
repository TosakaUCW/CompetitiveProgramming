#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>

#define int long long

const int N = 1e6 + 5;

int L, R;
int prime[N], v[N], num_prime, cnt;
bool vis[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void Euler(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[++num_prime] = i;
        for (int j = 1; j <= num_prime; j++)
        {
            if (v[i] < prime[j] or prime[j] > n / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}

signed main()
{
    L = read(), R = read();
    memset(vis, 0, sizeof vis);
    cnt = 0, num_prime = 0;
    memset(v, 0, sizeof v);
    if (L == 1)
        vis[0] = true;
    Euler(sqrt(R));
    for (int i = 1; i <= num_prime; i++)
        for (int j = L / prime[i]; j <= R / prime[i]; j++)
        {
            if (prime[i] * j < L)
                continue;
            if (j > 1)
                vis[prime[i] * j - L] = true;
        }
    for (int i = L; i <= R; i++)
        if (!vis[i - L])
            ++cnt;
    return printf("%lld", cnt), 0;
}