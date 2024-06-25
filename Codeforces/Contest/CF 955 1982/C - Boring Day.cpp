#include <bits/stdc++.h>
using i64 = long long;
#define int long long
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

const int N = 1e6 + 5;

void solve()
{
    int n = read();
    int L = read(), R = read();
    vector<int> a(n + 1), sum(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1];
        int res = 0, l = 1, r = i;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (sum[i] - sum[mid - 1] >= L) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        // cout << i << ' ' << res << '\n';
        if (1 <= res and res <= n and sum[i] - sum[res - 1] <= R) f[i] = std::max(f[i], f[res - 1] + 1);
    }   
    
    // puts("------");
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    cout << f[n] << '\n';
}// 1 4 2 2 4

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}