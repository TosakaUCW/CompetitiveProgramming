#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <iostream>
#include <vector>

#define int long long
#define calc(x) (x * (x + 1) / 2)

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e3 + 5;

int n, m, ans;
int up[N][N];
bool map[N][N];

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("strah.in", "r", stdin);
    freopen("strah.out", "w", stdout);
#endif // !ONLINE_JUDGE
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            std::cin >> ch;
            map[i][j] = ch == '.';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            up[i][j] = map[i][j];
            if (i > 1 and map[i][j])
                up[i][j] += up[i - 1][j];
        }
    for (int i = 1; i <= n; i++)
    {
        std::stack<std::pair<int, int>> S;
        std::vector<std::vector<int>> tmp(m + 1);
        for (int j = m; j >= 1; j--)
        {
            if (!map[i][j])
            {
                while (!S.empty())
                    S.pop();
                continue;
            }
            int a = 0, b = 0, w = 1;
            while (!S.empty() and S.top().first > up[i][j])
                w += tmp[S.top().second][0], S.pop();
            if (!S.empty())
            {
                int p = S.top().second;
                b += tmp[p][2], a += tmp[p][1] + tmp[p][2] * (p - j);
            }
            a += calc(up[i][j]) * calc(w);
            b += calc(up[i][j]) * w;
            ans += a;
            tmp[j] = {w, a, b};
            S.push({up[i][j], j});
        }
    }
    return printf("%lld", ans), 0;
}