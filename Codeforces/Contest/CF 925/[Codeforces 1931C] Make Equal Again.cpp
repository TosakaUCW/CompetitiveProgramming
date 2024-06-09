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
const int N = 2e5 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n, a[N], b[N], c[N];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    if (n == 1) return puts("0"), void();
    int l, r, ans = n;
    l = 0, r = n + 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == a[1]) l = i;
        else break;
    for (int i = n; i >= 1; i--)
        if (a[i] == a[1]) r = i;
        else break;
    if (l == n and r == 1) return puts("0"), void();
    ans = r - l - 1;
    l = 0, r = n + 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == a[n]) l = i;
        else break;
    for (int i = n; i >= 1; i--)
        if (a[i] == a[n]) r = i;
        else break;
    ans = std::min(ans, r - l - 1);
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}