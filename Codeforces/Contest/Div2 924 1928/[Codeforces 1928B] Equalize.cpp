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
const int N = 1e6 + 5;
const int INF = 1LL << 60;
int n, a[N];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    std::sort(a + 1, a + 1 + n);
    int m = std::unique(a + 1, a + 1 + n) - a - 1, ans = 1;
    for (int i = 1; i <= m; i++)
    {
        int res = i;
        for (int L = i, R = m, mid; L <= R;)
            if (a[mid = (L + R) / 2] - a[i] < n) res = mid, L = mid + 1;
            else R = mid - 1;
        ans = std::max(ans, res - i + 1);
    }
    printf("%d\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}