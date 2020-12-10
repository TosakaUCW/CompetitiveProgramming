#include <stdio.h>

const int N = 1e5 + 5;

int n, m;

class Seg
{
#define ls (p << 1)
#define rs (p << 1 | 1)

private:
    struct Node
    {
        int k;
    } t[N << 2];
    void push_down(int p)
    {
        if (t[p].k)
            t[ls].k ^= 1, t[rs].k ^= 1, t[p].k = 0;
    }

public:
    void modify(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
        {
            t[p].k ^= 1;
            return;
        }
        push_down(p);
        int mid = (l + r) >> 1;
        if (x <= mid)
            modify(ls, l, mid, x, y);
        if (mid < y)
            modify(rs, mid + 1, r, x, y);
    }
    int query(int p, int l, int r, int x)
    {
        if (l == r)
            return (t[p].k % 2);
        push_down(p);
        int mid = (l + r) >> 1;
        if (x <= mid)
            query(ls, l, mid, x);
        else
            query(rs, mid + 1, r, x);
    }
} T;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int opt;
        scanf("%d", &opt);
        if (opt == 1)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            T.modify(1, 1, n, l, r);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", T.query(1, 1, n, x));
        }
    }
    return 0;
}