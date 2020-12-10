#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <iostream>
#include <vector>

const int N = 15 + 5;
const double eps = 0.0000001;

int n;
double x[N], y[N];
double dis[N][N];
double f[N][1 << 15 + 1];
double ans;

// double dis(int x1, int y1, int x2, int y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }

int main()
{
    memset(f, 127, sizeof f);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
        f[i][1 << (i - 1)] = sqrt(pow(x[i], 2) + pow(y[i], 2));
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    for (int s = 1; s < (1 << n); s++)
    {
        std::vector<int> Q;
        Q.clear();
        for (int k = 1; k <= n; k++)
            if (((1 << (k - 1)) & s) == 0)
                Q.push_back(k);
        for (int i = 1; i <= n; i++)
        {
            if (abs(f[i][s] - f[0][0]) < eps)
                continue;
            for (int k = 0; k < Q.size(); k++)
                f[Q[k]][s | (1 << (Q[k] - 1))] = std::min(f[Q[k]][s | (1 << (Q[k] - 1))], f[i][s] + dis[Q[k]][i]);
        }
    }
    ans = f[0][0];
    for (int i = 1; i <= n; i++)
        ans = std::min(ans, f[i][(1 << n) - 1]);
    printf("%.2lf", ans);
    return 0;
}