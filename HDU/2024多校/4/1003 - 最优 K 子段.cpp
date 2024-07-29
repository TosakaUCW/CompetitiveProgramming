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
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) minp[i] = i, primes.push_back(i);
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}
void solve()
{
    int n = read(), k = read();
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();
    
    if (k + k > n) {
        puts("impossible");
        return;
    }
    
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    
    auto judge = [&](int lim) {
        int res = 0;
        std::set<std::pair<int, int>> s{{0, 0}};
        for (int i = 1; i <= n; i++) {
            for (auto [x, y] : s) {
                if (sum[i] - x < lim) { 
                    break;
                }
                else if (minp[i - y] == i - y) {
                    ++res;
                    s.clear();
                    break;
                }
            }
            s.insert({sum[i], i});
        }
        return res >= k;
    };
    
    int ans = 0;
    for (int L = -2e3, R = 1e7; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    sieve(200000);
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}