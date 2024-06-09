#include <bits/stdc++.h>
using namespace std;
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
const int N = 1e3 + 5;
// const int INF = 1e18;
int n, m, c;
int a[N][N];
int dis(int a, int b, int c, int d) { return abs(a - c) + abs(b - d); }
void solve()
{
    n = read(), m = read(), c = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    int ans = 1LL << 62;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int ii = 1; ii <= n; ii++)
                for (int jj = 1; jj <= m; jj++)
                    if (i != ii or j != jj)
                        ans = std::min(ans, a[i][j] + a[ii][jj] + c * dis(i, j, ii, jj));

    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}