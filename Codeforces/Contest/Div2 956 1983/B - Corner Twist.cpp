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

const int N = 2e5 + 5;

void solve()
{
    int n = read(), m = read();
    vector<string> s(n), t(n);
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m)); 
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = s[i][j] - '0';
            
    for (int i = 0; i < n; i++)
        cin >> t[i];
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = t[i][j] - '0';
        
    // for (int i = 0; i < n; i++, puts(""))
    //     for (int j = 0; j < m; j++)
    //         cout << b[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            
            if (i + 1 >= n or j + 1 >= m) continue;
            if (a[i][j] == b[i][j]) continue;
            
            int d = (b[i][j] - a[i][j] + 3) % 3;
            int k = (6 - d) % 3;
            // printf("%d %d\n", i, j);
            a[i][j] += d, a[i + 1][j + 1] += d;
            // printf("%d\n", a[i][j]);
            a[i + 1][j] += k, a[i][j + 1] += k;
            
            a[i][j] %= 3, a[i + 1][j + 1] %= 3;
            a[i + 1][j] %= 3, a[i][j + 1] %= 3;
        }
        
        
    // for (int i = 0; i < n; i++, puts(""))
    //     for (int j = 0; j < m; j++)
    //         cout << a[i][j];
        
    bool flag = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j])
            {
                flag = 0;
                break;
            }
            
        
    puts(flag ? "YES" : "NO");
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