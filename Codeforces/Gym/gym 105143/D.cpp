#include <bits/stdc++.h>
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
const int N = 5e3 + 5;
// const int INF = 1e18;
int n, m, a[N];
pii f[N][N];
void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                if (i == 1) f[i][j] = {0, 1};
                else if (i == n) f[i][j] = {1, 0};
                else
                {
                    if (a[i - 1] > a[i + 1]) f[i][j] = {1, 0};
                    else f[i][j] = {0, 1};
                }
            }

        }
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("B.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}