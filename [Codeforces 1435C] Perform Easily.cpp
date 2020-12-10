#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

const int N = 1e5 + 5;
const int m = 6;
const int M = m + 5;
const int INF = 1 << 30;

int n;
int a[M], b[N], c[N][M];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int min(std::vector<std::pair<int, int>> &V)
{
    if (V.empty())
        return 0;
    std::sort(V.begin(), V.end());
    std::vector<std::pair<int, int>> U{V[V.size() - 1]};
    for (int i = V.size() - 1; i >= 0; i--)
        if (V[i].second > U[U.size() - 1].second)
            U.emplace_back(V[i]);
    int res = std::min(U[0].first, U[U.size() - 1].second);
    for (int i = 0; i < U.size() - 1; i++)
        res = std::min(res, U[i].second + U[i + 1].first);
    return res;
}

int go(int x)
{
    std::vector<std::pair<int, int>> V;
    for (int i = 2; i <= n; i++)
    {
        int l = INF, r = INF;
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] <= x)
                l = std::min(l, x - c[i][j]);
            if (c[i][j] >= x)
                r = std::min(r, c[i][j] - x);
        }
        V.emplace_back(l, r);
    }
    return min(V);
}

int main()
{
    for (int i = 1; i <= 6; i++)
        a[i] = read();
    n = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    std::sort(a + 1, a + 1 + m);
    std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            c[i][j] = b[i] - a[j];
    int ans = INF;
    if (n == 1)
        ans = 0;
    else
        for (int i = 1; i <= m; i++)
            ans = std::min(ans, go(c[1][i]));
    return printf("%d", ans), 0;
}