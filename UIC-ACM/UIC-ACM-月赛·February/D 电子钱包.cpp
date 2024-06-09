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
const int M = 1e5 + 5;
const int N = 10 + 5;
int n, m, k, a[N][M], sum[N][M], f[N][M];

void solve()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int j = 1; j <= m; j++)
    {
        std::vector<int> b(n);
        for (int i = 1; i <= n; i++) b[i - 1] = a[i][j];
        std::sort(b.rbegin(), b.rend());
        for (int i = 1; i <= n; i++) a[i][j] = b[i - 1];
        for (int i = 1; i <= n; i++) a[i][j] += a[i - 1][j];
    }
    for (int i = 1; i + k - 1 <= m; i++)
        for (int j = i; j <= i + k - 1; j++)
        {
            int len = j - i + 1;
            for (int c = 0; c <= len and i + k - 1 + c <= m + 1; c++)
                f[len - c + 1][i + c] = std::max(f[len - c + 1][i + c], f[len][i] + a[c][j]);
        }
    int ans = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= m + 1; j++)
            ans = std::max(ans, f[i][j]);
    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}