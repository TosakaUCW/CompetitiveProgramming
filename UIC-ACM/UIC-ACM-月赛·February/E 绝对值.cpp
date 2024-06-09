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
// const long long INF = 1LL << 60;
int n, a[N], b[N];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += abs(a[i] - b[i]);
    int sum = ans, p = 1, q = 1;
    for (int i = 1; i <= n; i++)
    {
        if (std::max(a[i], b[i]) < std::max(a[p], b[p])) p = i;
        if (std::min(a[i], b[i]) > std::min(a[q], b[q])) q = i;
    }
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, sum - abs(a[i] - b[i]) - abs(a[p] - b[p]) + abs(a[i] - b[p]) + abs(a[p] - b[i])),
        ans = std::max(ans, sum - abs(a[i] - b[i]) - abs(a[q] - b[q]) + abs(a[i] - b[q]) + abs(a[q] - b[i]));
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}