#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
const int N = 1e5 + 5;
int n, d;
struct Node { double l, r; } a[N];
bool cmp (Node a, Node b) { return a.r < b.r; }
int solve()
{
    bool flag = 0;
    for (int i = 0, x, y; i < n; i++)
    {
        std::cin >> x >> y;
        if (y > d) flag = 0;
        flag |= (y > d);
        double len = sqrt(1.0 * d * d - y * y);
        a[i].l = x - len, a[i].r = x + len;
    }
    if (flag) return -1;
    std::sort(a, a + n, cmp);
    int res = 1;
    double las = a[0].r;
    for (int i = 1; i < n; i++)
        if (las < a[i].l)
            res++, las = a[i].r;
    return res;
}
int main()
{
    for (int cas = 1; std::cin >> n >> d and n and d; cas++)
        printf("Case %d: %d\n", cas, solve());
    return 0;
}