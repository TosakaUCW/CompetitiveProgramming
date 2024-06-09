#include <stdio.h>
#include <algorithm>

const int N = 1e5;
const int LOG2N = 17;

int n, m;
int a[N + 5];

struct SparseTable
{
    int log2[N + 5], st[N + 5][LOG2N + 5];

    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            int k = 0;
            while ((1 << (k + 1)) <= i)
                k++;
            log2[i] = k;
        }

        for (int i = 1; i <= n; i++)
            st[i][0] = a[i];

        for (int j = 1; j <= log2[n]; j++)
            for (int i = 1; i <= n; i++)
                if (i + (1 << (j - 1)) <= n)
                    st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                else
                    st[i][j] = st[i][j - 1];
    }

    int query(int l, int r)
    {
        int k = log2[r - l];
        return std::min(st[l][k], st[r - (1 << k) + 1][k]);
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
        printf("%d ", ans);
    }
    return 0;
}