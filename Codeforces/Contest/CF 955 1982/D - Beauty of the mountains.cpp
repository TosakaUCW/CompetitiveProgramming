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
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 5e2 + 5;

int sum[N][N], a[N][N];
string c[N];

void solve() 
{ 
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++) cin >> c[i], c[i] = ' ' + c[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (c[i][j] == '0' ? -1 : 1);
            
    int gcd = 0;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++)
        {
            int tmp = abs(sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k]);
            gcd = std::__gcd(gcd, tmp);
            
        }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (c[i][j] == '0' ? a[i][j] : 0);
    int x = sum[n][m];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (c[i][j] == '1' ? a[i][j] : 0);
    int y = sum[n][m];
    
    int tot = x - y;
    
    if (tot == 0 or (gcd != 0 and abs(tot) % gcd == 0)) puts("YES");
    else puts("NO");
    // puts(abs(x - y) % gcd == 0 ? "YES" : "NO");
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