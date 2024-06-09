#include <stdio.h>
#include <algorithm>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e5 + 5;
int n, m, T, a[N], b[N];
signed main()
{
    n = read(), m = read(), T = read();
    for (int i = 2; i <= n; i++) a[i] = read();
    for (int x; m--; ) x = read(), b[x] = read();
    T += b[1];
    for (int i = 2; i <= n; i++)
        if (T - a[i] > 0) T += b[i] - a[i];
        else return puts("No"), 0;
    return puts("Yes"), 0;
}