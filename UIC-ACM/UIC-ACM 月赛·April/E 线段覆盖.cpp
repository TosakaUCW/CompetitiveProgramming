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
int n, k;
int a[5];
void solve()
{
    n = read(), k = read();
    a[0] = a[1] = a[2] = a[3] = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = read(), r = read();
        if (l >= k + 1 or r <= k - 1) continue;
        if (l <= k - 1 and k + 1 <= r) continue;
        if (l == r and l == k) a[0]++;
        else if (l <= k - 1 and r == k) a[2]++;
        else if (l == k and k + 1 <= r) a[3]++;
    }
    // cout << x << y << z << '\n';
    if (a[0] != 0) puts("YES");
    else if (a[2] != 0 and a[3] != 0) puts("YES");
    else puts("NO");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}