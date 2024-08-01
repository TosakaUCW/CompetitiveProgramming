#include <bits/stdc++.h>
// #define int long long
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
int n, m, a[N];
void solve()
{
    n = read(), m = read() * 2;
    int cnta = m, cntb = m;
    vector<int> a(n), b(n), ansa, ansb;
    for (int i = 0; i < n; i++) a[i] = read() - 1;
    for (int i = 0; i < n; i++) b[i] = read() - 1;
    vector<int> visa(n, 0), visb(n, 0), pushed(n, 0);
    for (int i = 0; i < n and cnta > 0; i++)
    {
        if (visa[a[i]] and cnta >= 2) cnta -= 2, ansa.pb(a[i]), ansa.pb(a[i]), pushed[a[i]] = 1;
        visa[a[i]] = 1;
    }
    for (int i = 0; i < n and cntb != cnta; i++)
    {
        if (visb[b[i]] and cntb >= 2) cntb -= 2, ansb.pb(b[i]), ansb.pb(b[i]), pushed[b[i]] = 1;
        visb[b[i]] = 1;
    }
    for (int i = 0; i < n and cnta > 0; i++)
        if (!pushed[a[i]]) ansa.pb(a[i]), ansb.pb(a[i]), cnta --;
    for (auto x : ansa) cout << x + 1 << ' ';
    puts("");
    for (auto x : ansb) cout << x + 1 << ' ';
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}