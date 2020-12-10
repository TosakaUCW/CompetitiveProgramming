#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;
const int INF = 0x7f7f7f7f7f7f7f7f;

int n, k;
int a[N], b[105];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

signed main()
{
    for (int T = read(); T--;)
    {
        n = read(), k = read();
        int ans = INF;
        for (int i = 1; i <= n; i++)
            a[i] = read(), b[a[i]]++;
        for (int col = 1; col <= 100; col++)
            if (b[col])
            {
                int sum = 0;
                for (int i = 1; i <= n; i = i + k)
                {
                    while (a[i] == col && i <= n)
                        i++;
                    if (i != n + 1)
                        sum++;
                }
                ans = std::min(ans, sum);
            }
        printf("%lld\n", ans);
    }
    return 0;
}