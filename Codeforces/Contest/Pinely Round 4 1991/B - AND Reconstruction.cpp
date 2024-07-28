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
    int n = read();
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i < n; i++) b[i] = read();
    
    for (int j = 0; j <= 30; j++)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            if (b[i] >> j & 1)
            {
                a[i] |= (1 << j);
                a[i + 1] |= (1 << j);
            }
            else
            {
                // if (a[i + 1] >> j & 1)
                    // a[i + 1] ^= (1 << j);
                if (a[i] >> j & 1)
                    a[i] ^= (1 << j);
            }
        }
        
        for (int i = n - 1; i >= 1; i--)
        {
            int x = b[i] >> j & 1;
            int y = a[i] >> j & 1;
            int z = a[i + 1] >> j & 1;
            // cout << x << y << z << '\n';
            if (x != (y & z))
                return puts("-1"), void();
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    puts(""); 
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
/*
b1 = a1 & a2
b2 = a2 & a3

110
011
*/