#include <bits/stdc++.h>
// #define int long long
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
int a[N];
void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int p = 1, q = n, ans = 0;
    while (p <= n and a[p] != 1) p++;
    while (q >= 1 and a[q] != 1) q--;
    for (int i = p; i <= q; i++) ans += a[i] == 0;
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}