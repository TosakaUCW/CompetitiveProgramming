#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e5 + 5;

int n, m;

struct Binary_Indexed_Tree
{
    int c[N];
    int lowbit(int x) { return x & (-x); }
    void add(int k, int x)
    {
        for (int i = k; i <= n; i += lowbit(i))
            c[i] += x;
    }
    int find(int k)
    {
        int res = 0;
        for (int i = k; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
    int query_sum(int l, int r)
    {
        return find(r) - find(l - 1);
    }
} BIT;

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
    {
        int a;
        scanf("%d", &a);
        BIT.add(i, a);
    }
    Rep(i, 1, m)
    {
        int opt, x, k;
        scanf("%d%d%d", &opt, &x, &k);
        switch (opt)
        {
        case 1:
            BIT.add(x, k);
            break;
        case 2:
            printf("%d\n", BIT.query_sum(x, k));
            break;
        }
    }
    return 0;
}