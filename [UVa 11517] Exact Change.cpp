#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1 << 30;
int n, m, sum;
int a[N], f[N];
void solve()
{
    m = read(), n = read(), sum = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read(), sum += a[i] * (sum < m);
    for (int i = 1; i <= sum; i++) f[i] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j >= a[i]; j--)
            f[j] = std::min(f[j], f[j - a[i]] + 1);
    int x = m;
    for (; x < sum and f[x] == INF; x++);
    printf("%d %d\n", x, f[x]);
}
signed main()
{
    for (int T = read(); T--; solve());
    return 0;
}