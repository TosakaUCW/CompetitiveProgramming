#include <bits/stdc++.h>
// #define int long long
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

const int N = 2e5 + 5;
const int P = 998244353;

int n, m, k, x, y;
int a[N], fa[N], cnt[2][N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n + m; i++)
        a[i] = read(), fa[i] = i, cnt[i <= n][i] = 1;
    for (int i = 1; i <= n + m; i++)
    {
        int fx = find(i), fy = find(a[i]);
        if (fx == fy)
            continue;
        fa[fx] = fy;
        cnt[0][fy] += cnt[0][fx];
        cnt[1][fy] += cnt[1][fx];
    }
    for (int i = 1; i <= n + m; i++)
        if (i == find(i))
        {
            k++;
            if (cnt[0][i] + cnt[1][i] == 1)
                continue;
            if (!cnt[0][i])
                x++;
            if (!cnt[1][i])
                y++;
        }
    printf("%d\n", n + m - k + 2 * std::max(x, y));
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