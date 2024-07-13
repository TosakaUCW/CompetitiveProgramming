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

const int logn = 30;
const int N = 2e5 + 5;
int f[N][logn + 5], Logn[N];

int query(int x, int y)
{
    int s = Logn[y - x + 1];
    return std::__gcd(f[x][s], f[y - (1 << s) + 1][s]);
}

void solve()
{
    int n = read(), ans = 0;
    for (int i = 1; i <= n; i++) f[i][0] = read();
    for (int j = 1; j <= logn; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = std::__gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= n; i++)
    {
        int res = i;
        for (int L = i, R = n; L <= R; )
        {
            int mid = L + R >> 1;
            if (query(i, mid) == 1) res = mid, R = mid - 1;
            else L = mid + 1;
        }
        if (query(i, res) == 1) ans++;
        i = res;
    }
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("Qgame3.in", "r", stdin);
#endif
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i < N; i++) Logn[i] = Logn[i / 2] + 1;
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}