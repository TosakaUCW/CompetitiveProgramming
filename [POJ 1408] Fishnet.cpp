#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
const int N = 1e2 + 5;
int n;
double a[N], b[N], c[N], d[N];
struct Node { double x, y; } p[N][N];
Node calc(double x1, double x2, double y1, double y2)
{
    double a1 = 1, b1 = x1 - x2, c1 = -x1;
    double a2 = y2 - y1, b2 = -1, c2 = y1;
    double k = a1 * b2 - a2 * b1;
    return Node{(b1 * c2 - b2 * c1) / k, (a2 * c1 - a1 * c2) / k};
}
double cross(Node a, Node b, Node c){ return fabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)); }
void solve()
{
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];
    for (int i = 1; i <= n; i++) std::cin >> c[i];
    for (int i = 1; i <= n; i++) std::cin >> d[i];
    a[0] = b[0] = c[0] = d[0] = 0;
    a[n + 1] = b[n + 1] = c[n + 1] = d[n + 1] = 1;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            p[i][j] = calc(a[i], b[i], c[j], d[j]);
    double ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            double res = 0;
            res += cross(p[i][j], p[i][j + 1], p[i + 1][j]);
            res += cross(p[i + 1][j + 1], p[i][j + 1], p[i + 1][j]);
            ans = std::max(ans, res / 2.0);
        }
    printf("%.6f\n", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    while (std::cin >> n && n) solve();
    return 0;
}