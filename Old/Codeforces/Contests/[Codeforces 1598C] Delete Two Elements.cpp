#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, k, ans;
int a[N];
std::unordered_map<int, int> b;

void solve()
{
    n = read(), k = ans = 0, b.clear();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[a[i]]++, k += a[i];
    if (2 * k % n)
        return puts("0"), void();
    k = 2 * k / n;
    for (int i = 1; i <= n; i++)
        b[a[i]]--, ans += b[k - a[i]];
    printf("%lld\n", ans);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}