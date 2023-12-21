#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
int n, m;
std::string s;
int sa[N], rk[N << 1], oldrk[N << 1], id[N], cnt[N], key[N];
bool cmp(int x, int y, int w) { return oldrk[x] == oldrk[y] and oldrk[x + w] == oldrk[y + w]; }
void solve()
{
    std::cin >> s, n = s.size(), m = 127, s = '*' + s;
    for (int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
    for (int w = 1, p = 0; w < n and p ^ n; w <<= 1, m = p, p = 0)
    {
        for (int i = n; i >  n - w; i--) id[++p] = i;
        for (int i = 1; i <= n; i++) if (sa[i] > w) id[++p] = sa[i] - w;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) ++cnt[key[i] = rk[id[i]]];
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[key[i]]--] = id[i];
        memcpy(oldrk + 1, rk + 1, n * sizeof(int)), p = 0;
        for (int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}