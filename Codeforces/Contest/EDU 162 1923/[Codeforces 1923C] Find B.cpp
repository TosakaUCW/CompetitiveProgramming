#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n, a[N], q, b[N], c[N];
void solve()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + (a[i] == 1);
    for (int i = 1; i <= n; i++) c[i] = c[i - 1] + a[i];
    for (int l, r; q--; )
    {
        l = read(), r = read();
        if (l == r) { puts("NO"); continue; }
        int sum = c[r] - c[l - 1];
        int num = b[r] - b[l - 1];
        int cost = num * 2 + (r - l + 1 - num);
        puts(cost <= sum ? "YES" : "NO");
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}