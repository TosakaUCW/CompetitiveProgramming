#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
using std::vector;
using std::cout;
using std::cin;
#define fi first
#define se second
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
struct Node
{
    int l, r, x, y, opt;
    bool friend operator < (Node a, Node b) { return a.l == b.l ? a.r < b.r : a.l < b.l; }
};
void solve()
{
    int n = read(), m = read();
    vector<Node> a(m);
    vector<int> b(n);
    for (int i = 0; i < m; i++)
        a[i].l = read() - 1, a[i].x = read(), a[i].r = read() - 1, a[i].y = read(), a[i].opt = i;
    std::sort(a.begin(), a.end());
    vector<int> k1;
    vector<int> k2;
    for (auto tmp : a)
    {
        int l = tmp.l, r = tmp.r, x = tmp.x, y = tmp.y;
        if (!b[l]) b[l] = x, b[r] = y, k1.push_back(tmp.opt);
        else if (b[l] < x) b[l] = x, b[r] = y, k1.push_back(tmp.opt);
        else if (b[l] == x and b[r] < y) b[l] = x, b[r] = y, k1.push_back(tmp.opt);
        else k2.push_back(tmp.opt);
    }
    int ans = 0;
    for (auto x : b) ans += x;
    cout << ans << '\n';
    for (auto x : k2) cout << x + 1 << ' ';
    for (auto x : k1) cout << x + 1 << ' ';
    cout << '\n';  

}
signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}