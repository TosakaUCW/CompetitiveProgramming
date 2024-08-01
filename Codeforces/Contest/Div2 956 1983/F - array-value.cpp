#include <bits/stdc++.h>
using i64 = long long;
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

const int N = 2e5 + 5;

int idx = 1, tr[30 * N][2], mx[30 * N];
void clear()
{
    for (int i = 0; i <= idx; i++)
        tr[i][0] = tr[i][1] = mx[i] = 0;
    idx = 1;
}
void insert(int x, int pos)
{
    for (int i = 30, p = 1; i >= 0; i--)
    {
        int bit = x >> i & 1;
        if (!tr[p][bit]) tr[p][bit] = ++idx;
        p = tr[p][bit], mx[p] = std::max(mx[p], pos);
    }
}
int query(int x, int lim)
{
    int res = 0, p = 1;
    for (int i = 30; i >= 0; i--)
    {
        int bit = x >> i & 1;
        if (lim >> i & 1)
        {
            res = std::max(res, mx[tr[p][bit]]);
            p = tr[p][bit ^ 1];
        }
        else
            p = tr[p][bit];
    }
    return std::max(res, mx[p]);
}

void solve()
{
    int n = read(); i64 k;
    cin >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    
    auto judge = [&](int lim)
    {
        i64 res = 0;
        int max = 0;
        clear();
        for (int i = 1; i <= n; i++)
        {
            max = std::max(max, query(a[i], lim));
            res += max, insert(a[i], i);
        }
        return res >= k;
    };
    
    int ans = 0;
    for (int L = 0, R = 1 << 30; L <= R; )
    {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}