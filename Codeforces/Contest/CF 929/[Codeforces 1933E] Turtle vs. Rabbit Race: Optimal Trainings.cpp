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
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n, a[N], b[N];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    for (int q = read(), l, u; q--; )
    {
        l = read(), u = read();
        int res = l;
        for (int L = l, R = n; L <= R; )
        {
            int mid = (L + R) >> 1;
            int tot = b[mid - 1] - b[l - 1];
            int st = u - tot, ed = u - tot - a[mid] + 1;
            int sum = (st + ed) * a[mid] / 2;
            if (sum > 0) res = mid, L = mid + 1;
            else R = mid - 1;
        }
        cout << res << ' ';
    }
    cout << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}