#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

const int N = 1e3 + 5;
const int eps = 1e-7;

int n, h, r;
int fa[N];
int x[N], y[N], z[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

double dist(int i, int j) { return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) + pow(z[i] - z[j], 2)); }

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &h, &r);
        fa[0] = 0, fa[n + 1] = n + 1;
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &x[i], &y[i], &z[i]), fa[i] = i;
        for (int i = 1; i <= n; i++)
        {
            if (z[i] <= r)
            {
                int dx = find(i);
                int dy = find(0);
                fa[dx] = dy;
            }
            if (z[i] + r >= h)
            {
                int dx = find(i);
                int dy = find(n + 1);
                fa[dx] = dy;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
            {
                double k = dist(i, j);
                // printf("%lf\n", k);
                int dx = find(i), dy = find(j);
                if (2 * r - k >= eps and dx != dy)
                    fa[dx] = dy;
            }
        if (find(0) != find(n + 1))
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}