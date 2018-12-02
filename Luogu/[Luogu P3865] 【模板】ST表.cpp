#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

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
        Rep(i, 2, n)
            log2[i] = log2[i / 2] + 1;
        Rep(i, 1, n)
            st[i][0] = a[i];
        Rep(j, 1, log2[n])
            Rep(i, 1, n - (1 << (j - 1)))
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
    Rep(i, 1, n)
        scanf("%d", &a[i]);
    rmq.init();
    Rep(i, 1, m)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = rmq.query(l, r);
        printf("%d\n", ans);
    }
    return 0;
}
