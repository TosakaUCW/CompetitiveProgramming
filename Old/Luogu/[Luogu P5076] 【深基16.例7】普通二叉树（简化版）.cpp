#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>

const int N = 1e5 + 5;
const int INF = 2147483647;

int root, num_node;

struct Treap_Node
{
#define ls(p) t[p].ls
#define rs(p) t[p].rs
#define val(p) t[p].val
#define rnd(p) t[p].rnd
#define size(p) t[p].size
    int ls, rs, rnd, val, size;
} t[N];

void update_size(int p) { size(p) = size(ls(p)) + size(rs(p)) + 1; }

void new_node(int &k, int val)
{
    val(++num_node) = val;
    size(num_node) = 1;
    rnd(num_node) = rand();
    ls(num_node) = rs(num_node) = 0;
    k = num_node;
}

int merge(int x, int y)
{
    if (!x or !y)
        return x | y;
    if (rnd(x) < rnd(y))
    {
        rs(x) = merge(rs(x), y);
        update_size(x);
        return x;
    }
    else
    {
        ls(y) = merge(x, ls(y));
        update_size(y);
        return y;
    }
}

void split(int p, int k, int &x, int &y)
{
    if (!p)
    {
        x = y = 0;
        return;
    }
    if (val(p) <= k)
    {
        x = p;
        split(rs(x), k, rs(x), y);
        update_size(x);
    }
    else
    {
        y = p;
        split(ls(y), k, x, ls(y));
        update_size(y);
    }
}

void pop(int &root, int val)
{
    int x = 0, y = 0, z = 0;
    split(root, val, x, z);
    split(x, val - 1, x, y);
    y = merge(ls(y), rs(y));
    root = merge(merge(x, y), z);
} // delete a node (val(node) = val)

void push(int &root, int val)
{
    int x = 0, y = 0, z = 0;
    split(root, val, x, y);
    new_node(z, val);
    root = merge(merge(x, z), y);
}

int query_val_by_rank(int p, int rank)
{
    if (rank == size(ls(p)) + 1)
        return val(p);
    else if (rank <= size(ls(p)))
        return query_val_by_rank(ls(p), rank);
    else
        return query_val_by_rank(rs(p), rank - size(ls(p)) - 1);
}

int query_rank_by_val(int &root, int val)
{
    int x = 0, y = 0;
    split(root, val - 1, x, y);
    int rank = size(x) + 1;
    root = merge(x, y);
    return rank;
}

int query_prev(int &root, int val)
{
    int x = 0, y = 0, k = 0, prev = 0;
    split(root, val - 1, x, y);
    if (!x)
        return -INF;
    k = size(x);
    prev = query_val_by_rank(x, k);
    root = merge(x, y);
    return prev;
}

int query_next(int &root, int val)
{
    int x = 0, y = 0, next = 0;
    split(root, val, x, y);
    if (!y)
        return INF;
    next = query_val_by_rank(y, 1);
    root = merge(x, y);
    return next;
}

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
    int n = read();
    while (n--)
    {
        int opt = read(), x = read();
        switch (opt)
        {
        case 5:
            push(root, x);
            break;
        case 1:
            printf("%d\n", query_rank_by_val(root, x));
            break;
        case 2:
            printf("%d\n", query_val_by_rank(root, x));
            break;
        case 3:
            printf("%d\n", query_prev(root, x));
            break;
        case 4:
            printf("%d\n", query_next(root, x));
            break;
        }
    }
    return 0;
}