#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define ls (p << 1)
#define rs (p << 1 | 1)

const int N = 1e5 + 5;

int n, m;
struct Node
{
    int sum, lazy, L, R;
} tree[N << 2];

void push_up(int p) { tree[p].sum = tree[ls].sum + tree[rs].sum; }

void push_down(int p)
{
    if (tree[p].lazy == 0)
        return;
    tree[ls].sum += tree[p].lazy * (tree[ls].R - tree[ls].L + 1);
    tree[rs].sum += tree[p].lazy * (tree[rs].R - tree[rs].L + 1);
    tree[ls].lazy += tree[p].lazy, tree[rs].lazy += tree[p].lazy;
    tree[p].lazy = 0;
}

void build(int p, int L, int R)
{
    tree[p].L = L, tree[p].R = R;
    if (L == R)
        return;
    int mid = (L + R) / 2;
    build(ls, L, mid), build(rs, mid + 1, R);
    push_up(p);
}

void add(int p, int L, int R, int x, int y, int val)
{
    if (x <= L and R <= y)
    {
        tree[p].sum += val * (R - L + 1);
        tree[p].lazy += val;
        return;
    }
    int mid = (L + R) / 2;
    if (x <= mid)
        add(ls, L, mid, x, y, val);
    if (mid + 1 <= y)
        add(rs, mid + 1, R, x, y, val);
    push_up(p);
}

int query_sum(int p, int L, int R, int x, int y)
{
    int res = 0;
    if (x <= L and R <= y)
        return tree[p].sum;
    push_down(p);
    int mid = (L + R) / 2;
    if (x <= mid)
        res += query_sum(ls, L, mid, x, y);
    if (mid + 1 <= y)
        res += query_sum(rs, mid + 1, R, x, y);
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    for (int i = 1, a, b; i <= m; i++)
    {
        char opt;
        std::cin >> opt >> a >> b;
        if (opt == 'x')
            add(1, 1, n, a, a, b);
        else
            printf("%d\n", query_sum(1, 1, n, a, b));
    }
    return 0;
}