#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;

int n, m, k, ans, sum;
int a[N], b[N], c[N];

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
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
        a[i] = read(), b[i] = read();
    for (int L = 1, R = k, sum = 0; R <= n; sum = 0, L++, R++)
    {
        for (int i = 1, len; i <= m; i++)
        {
            sum += (len = std::max(std::min(R, b[i]) - std::max(L, a[i]) + 1, 0LL));
            if (std::min(b[i] - a[i] + 1, k) > len)
            {
                c[a[i] + len]++;
                c[std::min(a[i] + k, b[i] + 1)]--;
                c[std::max(a[i] + k, b[i] + 1)]--;
                c[b[i] + k - len + 1]++;
            }
        }
        for (int i = 1; i <= n; i++)
            c[i] += c[i - 1];
        for (int i = 1; i <= n; i++)
            c[i] += c[i - 1];
        for (int i = 1; i <= n; i++)
            ans = std::max(ans, sum + c[i]), c[i] = 0;
    }
    return printf("%lld", ans), 0;
}