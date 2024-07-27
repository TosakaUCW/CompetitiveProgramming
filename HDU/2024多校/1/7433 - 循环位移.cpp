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

typedef unsigned long long ull;

void solve()
{
    string A, B; cin >> A >> B;
    int n = A.size(); A = " " + A + A;
    int m = B.size(); B = " " + B;
    
    ull bas = 13331;
    vector<ull> ha(2 * n + 1), hb(m + 1), pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++) pow[i] = pow[i - 1] * bas;
    for (int i = 1; i <= 2 * n; i++) ha[i] = ha[i - 1] * bas + A[i] - 'A';
    for (int i = 1; i <= m; i++) hb[i] = hb[i - 1] * bas + B[i] - 'A';

    std::unordered_map<ull, bool> mp;
    for (int i = 1; i <= n; i++)
    {
        ull x = ha[i + n - 1] - ha[i - 1] * pow[n];
        mp[x] = 1;
    }
    
    int ans = 0;
    for (int i = 1; i + n - 1 <= m; i++)
    {
        ull x = (hb[i + n - 1] - hb[i - 1] * pow[n]);
        if (mp[x]) ans++;
    }
    cout << ans << "\n";
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