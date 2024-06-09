#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int P = 1e9 + 7;

int pow(int x, int k, int res = 1)
{
    for (x = (x + P) % P; k; k >>= 1, x = x * x % P)
        if (k & 1) res = res * x % P;
    return res;
}

void solve()
{
    int n  = read(), m = read(), k = read();
    int sum = 0, ans = 0;
    for (int i = 1; i <= m; i++)
        read(), read(), sum = (sum + read()) % P;
    int all = pow(n * (n - 1) / 2, P - 2), p = m * all % P;
    for (int i = 1; i <= k; i++)
        ans = (ans + sum * all) % P, sum = (sum + p) % P;
    std::cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}