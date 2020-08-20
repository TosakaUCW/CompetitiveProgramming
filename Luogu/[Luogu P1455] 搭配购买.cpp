#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int M = 1e5 + 5;

int n, m, w;
int wei[N], val[N];
int fa[N], f[M];

int find(int x) { return fa[x] != x ? fa[x] = find(fa[x]) : x; }

void merge(int x, int y) { fa[find(x)] = find(y); }

int main()
{
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wei[i], &val[i]), fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (fa[i] != i)
            wei[find(i)] += wei[i], val[find(i)] += val[i], wei[i] = val[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = w; j >= wei[i]; j--)
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    printf("%d", f[w]);
    return 0;
}