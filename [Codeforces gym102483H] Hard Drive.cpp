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

const int N = 5e5 + 5;
const int P = 998244353;

int n, k, m;
bool buk[N], ans[N];

void solve()
{
    int p = 2;
    if (k & 1)
        k--, ans[1] = 1, p++;
    if (!k)
        return;
    for (; p <= n; p++)
    {
        int q = p;
        while (!buk[p] and p <= n)
            p++;
        for (int i = q; i < p; i += 2)
        {
            ans[i] = 1, k -= 2;
            if (!k)
                return;
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("my_input.in", "r", stdin);
#endif
    n = read(), k = read(), m = read();
    for (int i = 1; i <= m; i++)
        buk[read()] = 1;
    solve();
    for (int i = 1; i <= n; i++)
        printf("%d", ans[i]);
    puts("");
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}