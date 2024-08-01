#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
const int INF = 1LL << 60;
int c[N], sum[N], add[N];
int calc(int n, int k)
{
    if (n & k == 0) return 0;
    int x = n / k;
    int l = n % k, r = k - l;
    int L = (x + 1) * l, R = x * r;
    return R * L + (R - x) * R / 2 + L * (L - x - 1) / 2;
}
void solve()
{
    int n = read(), B = read(), X = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    int m = *std::max_element(c + 1, c + 1 + n);
    memset(sum, 0, (m + 1) * 8UL);
    memset(add, 0, (m + 1) * 8UL);
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= c[i]; k++)
            sum[k] += calc(c[i], k);
        add[c[i]] += calc(c[i], c[i]);
    }
    int ans = 0, tot = 0;
    for (int k = 1; k <= m; k++)
        ans = std::max(ans, B * (sum[k] + tot) - (k - 1) * X),
        tot += add[k];
    printf("%lld\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}