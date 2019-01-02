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
    int query(int k)
    {
        int res = 0;
        for (int i = k; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
} BIT;

int main()
{
    scanf("%d%d", &n, &m);
    static int now, last;
    Rep(i, 1, n)
    {
        scanf("%d", &now);
        BIT.add(i, now - last);
        last = now;
    }
    Rep(i, 1, m)
    {
        int opt, x, y, k;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            scanf("%d%d%d", &x, &y, &k);
            BIT.add(x, k);
            BIT.add(y + 1, -k);
            break;
        case 2:
            scanf("%d", &x);
            printf("%d\n", BIT.query(x));
            break;
        }
    }
    return 0;
}