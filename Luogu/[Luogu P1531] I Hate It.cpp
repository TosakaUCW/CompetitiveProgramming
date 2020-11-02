#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

const int N = 2e5 + 5;

int n, m;
int a[N];

struct Node
{
#define ls (p << 1)
#define rs (p << 1 | 1)
    int max[N << 2];
    void push_up(int p) { max[p] = std::max(max[ls], max[rs]); }
    void build(int p, int l, int r)
    {
        if (l == r)
        {
            max[p] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return max[p];
        int res = 0, mid = (l + r) / 2;
        if (x <= mid)
            res = std::max(res, query(ls, l, mid, x, std::min(mid, y)));
        if (mid < y)
            res = std::max(res, query(rs, mid + 1, r, std::max(mid + 1, x), y));
        return res;
    }
    void modify(int p, int l, int r, int x, int y, int k)
    {
        if (l == x and r == y)
        {
            max[p] = std::max(max[p], k);
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), k);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, k);
        push_up(p);
    }
} T;

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

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    T.build(1, 1, n);
    while (m--)
    {
        char ch;
        int x, y;
        std::cin >> ch >> x >> y;
        if (ch == 'Q')
            printf("%d\n", T.query(1, 1, n, x, y));
        else
            T.modify(1, 1, n, x, x, y);
    }
    return 0;
}