#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;
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

const int N = 40 + 5;
const int P = 1e9 + 7;

int n, X, Y, Z;
int f[N][1 << 17];

int dfs(int x, int k, int pos)
{
    if (pos == k)
        return !x;
    int res = 0;
    for (int i = 1; i <= x; i++)
        res += dfs(x - i, k, pos + 1);
    return res;
}

void solve()
{
    n = read(), X = read(), Y = read(), Z = read();
    int now = (1 << X - 1) | (1 << X + Y - 1) | (1 << X + Y + Z - 1);
    int U = (1 << X + Y + Z) - 1;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int S = 0; S <= U; S++)
            for (int j = 1; j <= 10; j++)
            {
                int T = ((S << j) | (1 << j - 1)) & U;
                if ((T & now) != now)
                    f[i][T] = (f[i][T] + f[i - 1][S]) % P;
            }
    int ans = pow(10, n, P);
    for (int i = 0; i <= U; i++)
        ans = (ans - f[n][i] + P) % P;
    printf("%lld\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    for (int T = 1; T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << std::endl;
#endif
    return 0;
}