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

const int N = 1e6 + 5;
const int P = 998244353;

int L, R, k, f[N], g[N];
bool vis[N];
vector<int> S;

void init()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
            S.pb(i);
        for (auto x : S)
        {
            if (i * x >= N)
                break;
            vis[i * x] = 1;
            if (i % x == 0)
                break;
        }
    }
}

void solve()
{
#define j (i - L)
    L = read(), R = read(), k = read();
    for (int i = L; i <= R; i++)
        f[j] = i, g[j] = 1;
    for (auto x : S)
    {
        if (x * x > R)
            break;
        for (int i = L - L % x; i <= R; i += x)
            if (i >= L)
            {
                int cnt = 0;
                while (f[j] % x == 0)
                    f[j] /= x, cnt++;
                g[j] = g[j] * (cnt * k + 1) % P;
            }
    }
    for (int i = L; i <= R; i++)
        if (f[j] != 1)
            g[j] = g[j] * (k + 1) % P;
    int ans = 0;
    for (int i = L; i <= R; i++)
        ans = (ans + g[j]) % P;
    printf("%lld\n", ans);
}

signed main()
{
    init();
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << std::endl;
#endif
    return 0;
}