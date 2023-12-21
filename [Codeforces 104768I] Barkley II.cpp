#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define pb push_back
#define ins insert
#define lb(i) (i & -i)
const int N = 5e5 + 5;
int n;
int a[N], las[N], now[N], t[N];
std::set<int> s;
std::vector<std::array<int, 3>> q;

void add(int x, int k) { for (; x <= n; x += lb(x)) t[x] += k; }
int sum(int x, int res = 0)
{
    for (; x; x -= lb(x)) res += t[x];
    return res;
}

void solve()
{
    n = read() + 1, read();
    q.clear(), s.clear();
    memset(t, 0, (n + 1) * sizeof(int));
    for (int i = 2; i <= n; i++)
        a[i] = read(), now[a[i]] = 1;
    for (int i = 2; i <= n; i++)
    {
        las[i] = now[a[i]], now[a[i]] = i;
        s.insert(a[i]);
        if (las[i] and las[i] + 1 <= i - 1)
            q.pb({i - 1, las[i] + 1, a[i]});
    }
    for (int x : s)
        if (now[x] + 1 <= n)
            q.pb({n, now[x] + 1, x});
    std::sort(q.begin(), q.end());

    int tmp;
    for (tmp = 1; tmp <= *s.rbegin(); tmp++)
        if (s.find(tmp) == s.end())
            break;

    int p = 2, ans = s.size() == 1 and *s.begin() == 1 ? -1 : 0;
    for (auto [r, l, x] : q)
    {
        for (; p <= r; p++) add(p, 1), add(las[p], -1);
        ans = std::max(ans, sum(r) - sum(l - 1) - x);
    }
    ans = std::max(ans, sum(n) - sum(1) - tmp);
    printf("%d\n", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}