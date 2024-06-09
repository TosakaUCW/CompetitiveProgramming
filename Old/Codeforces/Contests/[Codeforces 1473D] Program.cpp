#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, m;
int a[N];
char str[N];

struct Node
{
    int sum, min, max;
    Node(int _sum = 0, int _min = 0, int _max = 0) { sum = _sum, min = _min, max = _max; }
    Node friend operator+(Node a, Node b)
    {
        return Node{
            a.sum + b.sum,
            std::min(0LL, std::min(a.min, a.sum + b.min)),
            std::max(0LL, std::max(a.max, a.sum + b.max)),
        };
    }
} node[N << 2];

struct Segment_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
    void clear()
    {
        memset(node, 0, sizeof node);
    }
    void push_up(int p)
    {
        node[p] = node[ls] + node[rs];
    }
    void build(int p, int l, int r)
    {
        if (l == r)
            return node[p] = {a[l], a[l], a[l]}, void();
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    Node query(int p, int l, int r, int x, int y)
    {
        if (y < l or r < x)
            return Node{0, 0, 0};
        if (x <= l and r <= y)
            return node[p];
        return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
    }
} T;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    for (int cas = read(); cas--;)
    {
        n = read(), m = read();
        std::cin >> str;
        for (int i = 1; i <= n; i++)
            a[i] = str[i - 1] == '+' ? 1 : -1;
        T.clear(), T.build(1, 1, n);
        for (int l, r; m--;)
        {
            l = read(), r = read();
            if (l == 1 and r == n)
                puts("1");
            else
            {
                Node t = T.query(1, 1, n, 1, l - 1) + T.query(1, 1, n, r + 1, n);
                printf("%lld\n", t.max - t.min + 1);
            }
        }
#ifndef ONLINE_JUDGE
        puts("----");
#endif // !ONLINE_JUDGE
    }
    return 0;
}