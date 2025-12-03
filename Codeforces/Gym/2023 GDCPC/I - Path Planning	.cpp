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
const int N = 5e5 + 5;
struct Node
{
    int x, y, val;;
    bool friend operator < (Node a, Node b) { return a.val < b.val; }
};
void solve()
{
    int n = read(), m = read();
    vector<Node> a;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a.push_back({i, j, read()});
    std::sort(a.begin(), a.end());
    std::set<pii> S;
    S.insert({0, 0});
    S.insert({n + 1, m + 1});
    int ans = 0;
    for (auto k : a)
    {
        int x = k.x, y = k.y, val = k.val;

        S.insert({x, y});
        auto it = S.find({x, y});
        auto prev = it, next = it;
        prev--, next++;

        if (it->fi >= prev->fi and it->se >= prev->se
        and it->fi <= next->fi and it->se <= next->se)
        {
            if (ans == val) ans++;
        }

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