#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 4e5 + 5;
const int M = 8e5 + 5;

int n, m;
int a[N];

class Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)

  private:
    struct Node
    {
        int l, r;
        long long sum, lazy;
    } t[N << 2];
    void push_up(int p) { t[p].sum = t[ls].sum + t[rs].sum; }
    void push_down(int p)
    {
        if (t[p].lazy)
        {
            t[ls].sum += t[p].lazy * (t[ls].r - t[ls].l + 1);
            t[rs].sum += t[p].lazy * (t[rs].r - t[rs].l + 1);
            t[ls].lazy += t[p].lazy;
            t[rs].lazy += t[p].lazy;
            t[p].lazy = 0;
        }
    }

  public:
    void build(int p, int l, int r)
    {
        t[p].l = l, t[p].r = r;
        if (t[p].l == t[p].r)
        {
            t[p].sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int val)
    {

        if (x <= l and r <= y)
        {
            t[p].sum += val * (r - l + 1);
            t[p].lazy += val;
            return;
        }
        push_down(p);
        int mid = (l + r) >> 1;
        if (x <= mid)
            modify(ls, l, mid, x, y, val);
        if (mid < y)
            modify(rs, mid + 1, r, x, y, val);
        push_up(p);
    }
    ll query(int p, int l, int r, int x, int y)
    {
        if (x <= l and r <= y)
            return t[p].sum;
        push_down(p);
        int mid = (l + r) >> 1;
        long long ans = 0;
        if (x <= mid)
            ans += query(ls, l, mid, x, y);
        if (mid < y)
            ans += query(rs, mid + 1, r, x, y);
        return ans;
    }
} T;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    T.build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
        {
            int k;
            scanf("%d", &k);
            T.modify(1, 1, n, x, y, k);
        }
        else
        {
            ll ans = T.query(1, 1, n, x, y);
            printf("%lld\n", ans);
        }
    }
    return 0;
}