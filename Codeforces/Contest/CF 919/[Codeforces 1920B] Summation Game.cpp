#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
int n, k, x, a[N], pre[N];

void solve()
{
    n = read(), k = read(), x = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    std::sort(a + 1, a + 1 + n, [](int a, int b){return a > b;});
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = -1e9 + 5;
    for (int i = 0; i <= k; i++)
    {
        int p = std::min(i + x, n);
        ans = std::max(ans, -(pre[p] - pre[i]) + pre[n] - pre[p]);
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("A.in", "r", stdin);
    for (int T = read(); T--; solve());
    return 0;
}