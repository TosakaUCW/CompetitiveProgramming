#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, m;
double a[N];

struct Node
{
    int L, R;
    double sum, sqr, lazy;
#define ls (p << 1)
#define rs (p << 1 | 1)
} t[N << 2];

void push_up(int p)
{
    t[p].sum = t[ls].sum + t[rs].sum;
    t[p].sqr = t[ls].sqr + t[rs].sqr;
}

void push_down(int p)
{
    if (!t[p].lazy)
        return;
    t[ls].sqr += 2 * t[p].lazy * t[ls].sum + t[p].lazy * t[p].lazy * (t[ls].R - t[ls].L + 1);
    t[rs].sqr += 2 * t[p].lazy * t[rs].sum + t[p].lazy * t[p].lazy * (t[rs].R - t[rs].L + 1);
    t[ls].sum += t[p].lazy * (t[ls].R - t[ls].L + 1);
    t[ls].lazy += t[p].lazy;
    t[rs].sum += t[p].lazy * (t[rs].R - t[rs].L + 1);
    t[rs].lazy += t[p].lazy;
    t[p].lazy = 0;
}

void build(int p, int L, int R)
{
    t[p].L = L, t[p].R = R;
    if (L == R)
    {
        t[p].sum = a[L], t[p].sqr = a[L] * a[L];
        return;
    }
    int mid = (L + R) / 2;
    build(ls, L, mid), build(rs, mid + 1, R);
    push_up(p);
}

void modify_add(int p, int L, int R, double val)
{
    if (L <= t[p].L and t[p].R <= R)
    {
        t[p].sqr += 2 * val * t[p].sum + val * val * (t[p].R - t[p].L + 1);
        t[p].sum += val * (t[p].R - t[p].L + 1);
        t[p].lazy += val;
        return;
    }
    push_down(p);
    int mid = (t[p].L + t[p].R) / 2;
    if (L <= mid)
        modify_add(ls, L, R, val);
    if (mid + 1 <= R)
        modify_add(rs, L, R, val);
    push_up(p);
}

double query_sum(int p, int L, int R)
{
    double res = 0;
    if (L <= t[p].L and t[p].R <= R)
        return t[p].sum;
    push_down(p);
    int mid = (t[p].L + t[p].R) / 2;
    if (L <= mid)
        res += query_sum(ls, L, R);
    if (mid + 1 <= R)
        res += query_sum(rs, L, R);
    return res;
}

double query_sqr(int p, int L, int R)
{
    double res = 0;
    if (L <= t[p].L and t[p].R <= R)
        return t[p].sqr;
    push_down(p);
    int mid = (t[p].L + t[p].R) / 2;
    if (L <= mid)
        res += query_sqr(ls, L, R);
    if (mid + 1 <= R)
        res += query_sqr(rs, L, R);
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        switch (opt)
        {
        case 1: // segment_add
            double k;
            scanf("%lf", &k);
            modify_add(1, x, y, k);
            break;
        case 2: // query sum/len
            printf("%.4lf\n", query_sum(1, x, y) / (y - x + 1));
            break;
        case 3: //query
            double a = query_sqr(1, x, y) / (y - x + 1);
            double b = query_sum(1, x, y) / (y - x + 1);
            printf("%.4lf\n", a - b * b);
            break;
        }
    }
    return 0;
}