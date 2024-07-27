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

void solve()
{
    int n = read(), L = read(), D = read();
    
    vector<int> a(n);
    for (auto &x : a) x = read();
    
    sort(a.begin() + 1, a.end());
    
    for (int i = 3; i < n; i++)
    {
        std::array b {a[0], a[1], a[2], a[i]};
        std::sort(b.begin(), b.end());
        
        if (b[2] >= L or b[3] - b[0] <= D) continue;
        puts("Yes");
        return;
    }
    puts("No");
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