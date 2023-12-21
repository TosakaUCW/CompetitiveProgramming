#include <stdio.h>
#include <algorithm>
#include <string.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 16e6 + 5;
typedef unsigned long long ull;
int n, m, a[N];
char s[N];
bool map[N];
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    n = read(), m = read(), gets(s);
    int len = strlen(s);
    for (int i = 0, j = 0; i < len and j < m; i++)
        if (!a[s[i]])
            a[s[i]] = ++j;
    ull base = 1, sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum * m + a[s[i]], base *= m;
    map[sum] = 1;
    int ans = 1;
    for (int i = n; i < len; i++)
    {
        sum = sum * m + a[s[i]] - a[s[i - n]] * base;
        ans += !map[sum];
        map[sum] = 1;
    }
    printf("%d", ans);
    return 0;
}