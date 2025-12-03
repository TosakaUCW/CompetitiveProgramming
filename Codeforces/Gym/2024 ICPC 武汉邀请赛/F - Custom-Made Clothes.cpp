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

void solve()
{
    int n = read(), k = n * n - read() + 1;
    int l = 1, r = n * n, ans = 1;
    
    auto judge = [&](int val)
    {
        int res = 0, x = n, y = 1;
        while (x >= 1 and y <= n)
        {
            printf("? %d %d %d\n", x, y, val), fflush(stdout);
            int tmp; cin >> tmp;
            if (tmp) res += x, y++;
            else x--;
        }
        return res;
    };
    
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (judge(mid) >= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << "! " << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}