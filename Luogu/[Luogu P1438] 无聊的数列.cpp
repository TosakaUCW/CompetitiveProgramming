#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, m;
int a[N];

struct Node
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define lazy(p) (t[p].lazy)
#define sum(p) (t[p].sum)
    int lazy, sum;
} t[N << 2];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void push_down(int p, int L, int R)
{
    if (!lazy(p))
        return;
    int mid = L + R >> 1;
    lazy(ls) += lazy(p), lazy(rs) += lazy(p);
    sum(ls) += lazy(p) * (mid - L + 1), sum(rs) += lazy(p) * (R - mid);
    lazy(p) = 0;
}

void modify(int p, int x, int y, int L, int R, int val)
{
    if (x <= L and R <= y)
    {
        lazy(p) += val, sum(p) += val * (R - L + 1);
        return;
    }
    push_down(p, L, R);
    int mid = L + R >> 1;
    if (x <= mid)
        modify(ls, x, y, L, mid, val);
    if (mid + 1 <= y)
        modify(rs, x, y, mid + 1, R, val);
    sum(p) = sum(ls) + sum(rs);
}

int query(int p, int x, int y, int L, int R)
{
    if (x <= L and R <= y)
        return sum(p);
    push_down(p, L, R);
    int mid = L + R >> 1, res = 0;
    if (x <= mid)
        res += query(ls, x, y, L, mid);
    if (mid + 1 <= y)
        res += query(rs, x, y, mid + 1, R);
    return res;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int L, R, k, d, opt; m; m--)
    {
        opt = read();
        if (opt == 1)
        {
            L = read(), R = read(), k = read(), d = read();
            modify(1, L, L, 1, n, k), modify(1, L + 1, R, 1, n, d);
            if (R + 1 <= n)
                modify(1, R + 1, R + 1, 1, n, -(R - L) * d - k);
        }
        else
            k = read(), printf("%d\n", a[k] + query(1, 1, k, 1, n));
    }
    return 0;
}