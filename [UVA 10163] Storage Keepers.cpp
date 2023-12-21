#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
int n, m, p[N], f[N];

bool judge(int x, int res = 0){
	if (!x) return 1;
    for (int i = 1; i <= m; i++) res += p[i] / x;
	return res >= n;
}

int find(int x)
{
    if (!x) return 0;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = n; j >= 1; j--)
            for(int k = 1; k <= j; k++)
                if (p[i] / k >= x)
                    f[j] = std::min(f[j], f[j - k] + p[i]);
    return f[n];
}

void solve()
{
    if (!(n + m)) return;
    int L = 0, R = 0, ans = 0;
    for (int i = 1; i <= m; i++) p[i] = read(), R = std::max(R, p[i]);
    while (L <= R)
    {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    printf("%d %d\n", ans, find(ans));
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    do { n = read(), m = read(), solve(); } while (n + m);
    return 0;
}