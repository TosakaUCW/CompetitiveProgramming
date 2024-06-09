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
const int N = 2e5 + 5;
const int M = 50 + 5;
// const int INF = 1e18;
int n, m;
int a[N], b[N][M];
void solve()
{
    n = read();
    int m = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        for (int j = 0; x; x >>= 1, j++)
        {
            b[i][j] = x & 1;
            m = std::max(m, j);
        }
    }
    int ans = 0, rem = n;
    vector<int> las;
    for (int j = m; j >= 1; j--)
    {
        for (int i = 1; i <= n; i++, puts(""))
            for (int j = m; j >= 0; j--)
                cout << b[i][j] << ' ';
        puts("--------");

        std::vector<int> minus, plus, newlas;


        for (int i = 1; i <= n; i++)
            if (b[i][j] and !b[i][j - 1]) minus.pb(i);
        for (int i = 1; i <= n; i++)
            if (!b[i][j] and !b[i][j - 1]) plus.pb(i);


        int pnt = 0;

        if (plus.size() + las.size() >= minus.size() and minus.size() <= rem)
        {
            for (auto i : plus)
            {
                if (rem == 0) break;
                if (pnt >= minus.size()) break;
                b[i][j - 1] = 1;
                b[minus[pnt]][j] = 0;
                b[minus[pnt]][j - 1] = 1;
                pnt++, rem--;
            }
            for (auto i : las)
            {
                if (rem == 0) break;
                if (pnt >= minus.size()) break;
                b[i][j] = 0;
                b[minus[pnt]][j] = 0;
                b[minus[pnt]][j - 1] = 1;
                pnt++, rem--;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!b[i][j] and b[i][j - 1]) newlas.pb(i);
        las = newlas;
        if (pnt != minus.size())
            ans |= (1 << j);
    }
    for (int i = 1; i <= n; i++) if (b[i][0]) ans |= 1;
    if (ans & (1 << 1))
    {
        if (las.size() % 2 == 0)
            ans ^= 1;
    }

    cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}