#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
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

const int N = 1e6 + 5;
const int P = 998244353;
const int INF = 2147483647;

int n, ind[N], ans;
std::set<int> g[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        ind[i] = 0, g[i].clear();
    for (int i = 1; i <= n; i++)
        for (int j = read(); j; j--)
        {
            int x = read();
            if (x ^ i)
                g[x].ins(i), ind[i]++;
        }
    std::priority_queue<int> Q[2];
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            Q[0].push(-i);
    for (int k = 0, ans = 1; 1; k ^= 1, ans++)
    {
        for (int u; !Q[k].empty();)
        {
            u = -Q[k].top(), Q[k].pop();
            for (auto v : g[u])
                if (!(--ind[v]))
                    Q[v > u ? k : k ^ 1].push(-v);
        }
        if (Q[k ^ 1].empty())
        {
            for (int i = 1; i <= n; i++)
                if (ind[i])
                    return puts("-1"), void();
            return printf("%d\n", ans), void();
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
    return 0;
}