#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <unordered_map>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e5 + 5;

int n, m, maxp, minp;
int s[N];
long double a[N], max, min, k;

void solve()
{
    scanf("%Lf%Lf%Lf", &a[0], &a[1], &k);
    if (!a[0] and !a[1]) return printf("%d %d\n", s[1], s[1]), void();
    max = std::max(a[0], a[1]), maxp = s[1];
    min = std::min(a[0], a[1]), minp = s[1];
    for (int i = 2; i <= 100000; i++)
    {
        a[i] = k * a[i - 1] + a[i - 2];
        if (a[i] > a[i - 1] and a[i - 1] >= 0 and a[i] > max)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[j] > i) { maxp = s[n]; break; }
                if (a[s[j]] > a[maxp]) maxp = s[j];
                if (a[s[j]] < a[minp]) minp = s[j];
            }
            return printf("%d %d\n", maxp, minp), void();
        }
        if (a[i] < a[i -1] and a[i - 1] < 0 and a[i] < min)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[j] > i) { minp = s[n]; break; }
                if (a[s[j]] > a[maxp]) maxp = s[j];
                if (a[s[j]] < a[minp]) minp = s[j];
            }
            return printf("%d %d\n", maxp, minp), void();
        }
        max = std::max(max, a[i]), min = std::min(min, a[i]);
    }
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++) s[i] = read();
    for (int T = read(); T--; solve());
    return 0;
}
