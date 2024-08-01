#include <bits/stdc++.h>
using i64 = long long;
#define int i64
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
int n, c;
int a[N], sum[N], ans[N];
void solve()
{
    int n = read(), c = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    a[1] += c;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];   
    std::priority_queue<int> Q;
    for (int i = n; i >= 1; i--)
    {
        int x = sum[i];
        std::vector<int> tmp;
        int res = i - 1;
        while (!Q.empty() and x < Q.top())
        {
            tmp.pb(Q.top());
            x += Q.top(); Q.pop();
            res++;
        }
        ans[i] = res;
        for (auto x : tmp) Q.push(x);
        Q.push(a[i]);
    }
    for (int i = 1; i <= n; i++) if (a[i] == Q.top()) { ans[i] = 0; break; }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
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