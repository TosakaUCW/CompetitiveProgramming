#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 100 + 5;

int n, sum, a[N];

bool judge(int x)
{
    for (int i = 2; i < x; i++) if (x % i == 0) return true;
    return false;
}

void solve()
{
    n = read(), sum = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) sum += a[i];
    if (judge(sum))
    {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) printf("%d ", i);
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (judge(sum - a[i]))
        {
            printf("%d\n", n - 1);
            for (int j = 1; j <= n; j++)
                if (j ^ i) printf("%d ", j);
            puts("");
            return;
        }
    }
}

signed main()
{
    for (int T = read(); T--; solve());
    return 0;
}
