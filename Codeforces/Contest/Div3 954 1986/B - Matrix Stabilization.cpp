#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e2 + 5;

int a[N][N];

void solve()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int max = 0;
            if (i - 1 >= 1)
            {
                if (a[i - 1][j] >= a[i][j])
                    continue;
                max = std::max(max, a[i - 1][j]);
            }
            if (i + 1 <= n)
            {
                if (a[i + 1][j] >= a[i][j])
                    continue;
                max = std::max(max, a[i + 1][j]);
            }
            if (j - 1 >= 1)
            {
                if (a[i][j - 1] >= a[i][j])
                    continue;
                max = std::max(max, a[i][j - 1]);
            }
            if (j + 1 <= m)
            {
                if (a[i][j + 1] >= a[i][j])
                    continue;
                max = std::max(max, a[i][j + 1]);
            }
            a[i][j] = max;
        }
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
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