#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
using std::vector, std::cout, std::cin;
#define fi first
#define se second
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 5e5 + 5;
struct Node
{
    int x, y;
    bool friend operator < (Node a, Node b) { return a.x - a.y > b.x - b.y; }
};
void solve()
{
    int n = read(), m = read();
    vector<Node> a(n);
    for (int i = 0; i < n; i++)
        a[i].x = read(), a[i].y = read();
    std::sort(a.begin(), a.end());
    vector<int> sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i].y;
    int ans = 0, tot = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 1) { tot += a[i].x; continue; }
        if ((m - i + (i == 0)) / 2 >= n - i)
            ans = std::max(ans, tot + sum[i]);
        tot += a[i].x;
    }
    cout << ans << '\n';
}
signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}