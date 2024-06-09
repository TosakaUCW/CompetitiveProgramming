#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
const int N = 1e2 + 5;
int n;
struct Node
{
    double x, y, z, r;
    void input() { std::cin >> x >> y >> z >> r; }
} a[N];
struct Edge
{
    int u, v;
    double dis;
    bool friend operator < (Edge a, Edge b) { return a.dis < b.dis; }
};
std::vector<Edge> b;
int fa[N];
int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
void solve()
{
    b.clear();
    for (int i = 1; i <= n; i++) a[i].input();
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            double dis = 0;
            dis += (a[i].x - a[j].x) * (a[i].x - a[j].x);
            dis += (a[i].y - a[j].y) * (a[i].y - a[j].y);
            dis += (a[i].z - a[j].z) * (a[i].z - a[j].z);
            dis = sqrt(dis) - a[i].r - a[j].r;
            b.push_back({i, j, std::max(dis, 0.0)});
        }
    for (int i = 0; i <= n; i++) fa[i] = i;
    std::sort(b.begin(), b.end());
    double ans = 0;
    for (int i = 0, m = b.size(); i < m; i++)
    {
        int u = b[i].u, v = b[i].v;
        int fx = find(u), fv = find(v);
        if (fx ^ fv) fa[fx] = fv, ans += b[i].dis;
    }
    printf("%.3f\n", ans);
}
signed main()
{
    // freopen("x.in", "r", stdin);
    while (~scanf("%d", &n) && n) solve();
    return 0;
}