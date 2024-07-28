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
std::vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0), primes.clear();
    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes)
        {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}
const int N = 2e5 + 5;

void solve()
{
    int n = read();
    
    vector<vector<pii>> a(2 * n + 5);
    
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (minp[i ^ j] == (i ^ j))
            {
                a[i ^ j].pb({i, j});
            }
                // cout << i << ' ' << j  << ' ' << (i ^ j) << '\n';
    for (int i = 1; i <= n; i++)
        if (a[i].size())
        {
            // cout << i << ":\n";
            
            #define bin(x) (std::bitset<sizeof(x) * 2>(x))
            for (auto [x, y] : a[i])
                // cout << "   " << bin(x) << ' ' << bin(y) << '\n';
                cout << "   " << x << ' ' << y << '\n';
        }
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("x.in", "r", stdin);
#endif
    sieve(2e5 + 5);
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}