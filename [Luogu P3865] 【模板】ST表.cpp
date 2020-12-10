#include <stdio.h>
#include <algorithm>

const int N = 1e5;
const int LOG2N = 20;

int n, m;
int a[N + 5];

struct SparseTable
{
    int log2[N + 5], st[N + 5][LOG2N + 5];

    void init()
    {
        log2[1] = 0;
        for (int i = 2; i <= n; i++)
            log2[i] = log2[i / 2] + 1;
        for (int i = 1; i <= n; i++)
            st[i][0] = a[i];
        for (int j = 1; j <= log2[n]; j++)
            for (int i = 1; i <= n - (1 << (j - 1)); i++)
            {
                int x = st[i][j - 1];
                int y = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = std::max(x, y);
            }
    }

    int query(int l, int r)
    {
        int k = log2[r - l + 1];
        int x = st[l][k];
        int y = st[r - (1 << k) + 1][k];
        return std::max(x, y);
    }
} rmq;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    rmq.init();
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = rmq.query(l, r);
        printf("%d\n", ans);
    }
    return 0;
}