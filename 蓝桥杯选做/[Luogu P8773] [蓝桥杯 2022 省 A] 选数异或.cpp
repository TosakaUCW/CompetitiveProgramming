#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
// const int INF = 1e18;
int n, m, x, a[N], las[1 << 20 + 5], st[N][22], lg[N];
void solve()
{
    n = read(), m = read(), x = read();
    for (int i = 1; i <= n; i++)
    {
        int tmp = read();
        st[i][0] = las[tmp ^ x];
        las[tmp] = i;
    }
    lg[0] = -1;
    for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = std::max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    for (int L, R; m--; )
    {
        L = read(), R = read();
        int k = lg[R - L + 1];
        int res = std::max(st[L][k], st[R - (1 << k) + 1][k]);
        puts(res >= L ? "yes" : "no");
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}