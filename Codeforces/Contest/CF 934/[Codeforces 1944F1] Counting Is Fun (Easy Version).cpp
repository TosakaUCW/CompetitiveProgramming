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
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, k, p;
void solve()
{
    n = read(), k = read(), p = read();
    vector<vector<int>> f(k + 1, vector<int>(k + 1, 0));
    f[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<vector<int>> g(k + 1, vector<int>(k + 1, 0));
        // g 先存恰好 c = b - a 的，最后再求和
        for (int b = 0; b <= k; b++)
        {
            for (int a = 0; a <= k; a++)
            {
                int c = std::max(0LL, b - a);
                g[b][c] += f[a][b], g[b][c] %= p;
            }
            for (int j = 1; j <= k; j++)
                g[b][j] += g[b][j - 1], g[b][j] %= p;
        }
        f.swap(g);
    }

    int ans = 0;
    for (int a = 0; a <= k; a++)
        for (int b = 0; b <= a; b++)
            ans += f[a][b], ans %= p;
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}