#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
int n, a[N], ans;

void judge(int k)
{
    int cnt = 0, x = 0;
    for (int i = 1; i <= k; i++)
        for (int j = i + k; j <= n; j += k)
        {
            int val = abs(a[j] - a[j - k]);
            if (!val) continue;
            if (!x) x = val, cnt = 1;
            else x = std::gcd(x, val);
        }
    if (x >= 2 or cnt == 0) ans++;
}

void solve()
{
    n = read(), ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i * i <= n; i++)
            if (n % i == 0)
            {
                judge(n / i);
                if (n / i != i) judge(i);
            }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}