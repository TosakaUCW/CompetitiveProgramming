#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::priority_queue;
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

int n, a[N], ans, l[N], r[N];
priority_queue<pii> Q;
bool vis[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), Q.push({a[i], i}),
        l[i] = i - 1, r[i] = i + 1;
    a[0] = a[n + 1] = -1e18;
    r[0] = 1, l[n + 1] = n;
    for (int t = 1; t <= (n + 1) / 2; t++)
    {
        while (vis[Q.top().se])
            Q.pop();
        pii x = Q.top();
        Q.pop();
        ans += x.fi;
        int i = x.se;
        x.fi = a[i] = a[l[i]] + a[r[i]] - a[i];
        Q.push(x);
        vis[l[i]] = vis[r[i]] = 1;
        l[i] = l[l[i]], r[l[i]] = i;
        r[i] = r[r[i]], l[r[i]] = i;
        printf("%lld\n", ans);
    }
}

signed main()
{
    solve();
    return 0;
}