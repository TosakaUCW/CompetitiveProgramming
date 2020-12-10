#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int long long

const int N = 1e3 + 5;
const int INF = 0x7f7f7f7f7f7f7f7f;

int n, m, k, p, ans = -INF;
int a[N][N], x[N * N], y[N * N], sum_x[N], sum_y[N];

std::priority_queue<int> Qx, Qy;

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
    n = read(), m = read(), k = read(), p = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read(), sum_x[i] += a[i][j], sum_y[j] += a[i][j];
    for (int i = 1; i <= n; i++)
        Qx.push(sum_x[i]);
    for (int j = 1; j <= m; j++)
        Qy.push(sum_y[j]);
    for (int i = 1, sum; i <= k; i++)
        sum = Qx.top(), Qx.pop(), x[i] = x[i - 1] + sum, Qx.push(sum - m * p);
    for (int i = 1, sum; i <= k; i++)
        sum = Qy.top(), Qy.pop(), y[i] = y[i - 1] + sum, Qy.push(sum - n * p);
    for (int i = 0; i <= k; i++)
        ans = std::max(ans, x[i] + y[k - i] - i * (k - i) * p);
    return printf("%lld", ans), 0;
}