#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 5e2 + 5;
const int P = 998244353;

int n, m, ans;
int f[N][N];
int fac[N], inv[N];

void init(int n)
{
    fac[0] = 1, f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % P, f[0][i] = 1;
    inv[n] = pow(fac[n], P - 2, P);
    for (int i = n - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % P;
}
int C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }

signed main()
{
    n = read(), m = read(), init(N - 5);
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (j < i)
                f[i][j] = pow(j, i, P);
            else
                for (int k = 0; k <= i; k++)
                    f[i][j] = (f[i][j] + C(i, k) * pow(i - 1, k, P) % P * f[i - k][j - i + 1] % P) % P;
    printf("%lld", f[n][m]);
    return 0;
}