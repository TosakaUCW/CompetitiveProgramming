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
int n, q, a[N], b[N];
void solve1()
{
    for (int x, ans; q--; )
    {
        x = read(), ans = 0;
        for (int sta = 0; sta < (1 << n); sta++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
                if ((sta >> j) & 1 == 1)
                    sum += a[j + 1];
            if (sum % x == 0) ans++;
        }
        cout << ans << '\n';
    }
}
void solve2()
{
    for (int x, ans; q--; )
    {
        x = read(), ans = 0;
        for (int i = 1; i <= n; i++) b[(a[i] % x + x) % x]++;

    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
#endif
    n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    if (n <= 10) solve1();
    else if (n <= 100) solve2();
    return 0;
}