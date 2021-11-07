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
const int P = 1e9 + 7;

int n;
int a[N], las[N], f[N];
int stk[N], top, buk[N];

void solve()
{
    n = read(), f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * (4 * i - 2) % P * pow(i + 1, P - 2, P) % P;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    top = 1;
    for (int i = 1; i <= n; i++)
    {
        while (top > 1 and a[stk[top]] > a[i])
            top--;
        las[i] = stk[top], stk[++top] = i;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
        if (a[las[i]] == a[i])
            ++buk[a[i]];
        else
            ans = ans * f[buk[a[i]]] % P, buk[a[i]] = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * f[buk[a[i]]] % P, buk[a[i]] = 1;
    printf("%lld\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("J.in", "r", stdin);
#endif
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}