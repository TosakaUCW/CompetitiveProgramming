#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mid ((L + R) >> 1)
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1 << 30;
int n, a[N];
int las[N], sum[N];
vector<int> work()
{
    vector<int> ans(n, n);
    for (int i = 1; i <= n; i++)
    {
        las[i] = a[i] == a[i - 1] ? las[i - 1] : i;
        sum[i] = sum[i - 1] + a[i];
        if (a[i - 1] > a[i]) { ans[i - 1] = 1; continue; }
        for (int L = 1, R = i - 1; L <= R; )
            if (sum[i - 1] - sum[mid - 1] > a[i] and las[i - 1] > mid)
                ans[i - 1] = i - mid, L = mid + 1;
            else R = mid - 1;
    }
    return ans;
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    auto l = work();
    std::reverse(a + 1, a + 1 + n);
    auto r = work();
    for (int i = 0; i < n; i++)
    {
        int now = std::min(l[i], r[n - 1 - i]);
        printf("%lld ", now == n ? -1 : now);
    }
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}