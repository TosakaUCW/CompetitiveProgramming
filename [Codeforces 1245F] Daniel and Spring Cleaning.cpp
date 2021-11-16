#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::swap, std::vector, std::string, std::queue, std::cin, std::cout;
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

const int N = 1e6 + 5;

int a[N], b[N], f[N][2][2];

int dfs(int p, int x, int y)
{
    if (p == -1)
        return 1;
    if (f[p][x][y] != -1)
        return f[p][x][y];
    f[p][x][y] = 0;
    for (int i = 0; i <= (x ? a[p] : 1); i++)
        for (int j = 0; j <= (y ? b[p] : 1); j++)
            if (!(i & j))
                f[p][x][y] += dfs(p - 1, x and i == a[p], y and j == b[p]);
    return f[p][x][y];
}

int solve(int x, int y)
{
    memset(f, -1, sizeof f);
    int k = 0;
    for (; x || y; k++, x /= 2, y /= 2)
        a[k] = x % 2, b[k] = y % 2;
    return dfs(k - 1, 1, 1);
}

void solve()
{
    int L = read(), R = read();
    printf("%lld\n", solve(R, R) - 2 * solve(L - 1, R) + solve(L - 1, L - 1));
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}