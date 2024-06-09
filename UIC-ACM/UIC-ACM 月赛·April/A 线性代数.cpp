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
const int P = 1e9 + 7;
int n, m, c;
int a[N][N];
int dis(int a, int b, int c, int d) { return abs(a - c) + abs(b - d); }
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read() % P;
    bool f1 = 1, f2 = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i > j and a[i][j] != 0) f1 = 0;
            if (i < j and a[i][j] != 0) f2 = 0;
            if (i == j) ans *= a[i][j], ans %= P;
        }
    if (!f1 and !f2) puts("Arknights!");
    else cout << ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("F.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}