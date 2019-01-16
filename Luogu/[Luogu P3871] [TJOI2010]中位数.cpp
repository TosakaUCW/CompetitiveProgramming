#include <stdio.h>
#include <stdlib.h>

const int SIZE = 1e5 + 5;
const int INF = 2147483647;

int n, m;

struct Binary_Search_Tree_Treap
{
    int tot, root;
    struct Node
    {
        int l, r;
        int val, dat;
        int cnt, size;
    } a[SIZE];
    int New(int val)
    {
        a[++tot].val = val;
        a[tot].dat = rand();
        a[tot].cnt = a[tot].size = 1;
        return tot;
    }
    void Update(int p)
    {
        a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
    }
    void Build()
    {
        New(-INF), New(INF);
        root = 1, a[1].r = 2;
        Update(root);
    }
    void Zig(int &p)
    {
        int q = a[p].l;
        a[p].l = a[q].r, a[q].r = p, p = q;
        Update(a[p].r), Update(p);
    }
    void Zag(int &p)
    {
        int q = a[p].r;
        a[p].r = a[q].l, a[q].l = p, p = q;
        Update(a[p].l), Update(p);
    }
    void Insert(int &p, int val)
    {
        if (p == 0)
        {
            p = New(val);
            return;
        }
        if (val == a[p].val)
        {
            a[p].cnt++, Update(p);
            return;
        }
        if (val < a[p].val)
        {
            Insert(a[p].l, val);
            if (a[p].dat < a[a[p].l].dat)
                Zig(p);
        }
        else
        {
            Insert(a[p].r, val);
            if (a[p].dat < a[a[p].r].dat)
                Zag(p);
        }
        Update(p);
    }
    int GetVal(int p, int rank)
    {
        if (p == 0)
            return INF;
        if (a[a[p].l].size >= rank)
            return GetVal(a[p].l, rank);
        if (a[a[p].l].size + a[p].cnt >= rank)
            return a[p].val;
        return GetVal(a[p].r, rank - a[a[p].l].size - a[p].cnt);
    }
} Treap;

int main()
{
    Treap.Build();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        Treap.Insert(Treap.root, x);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        char opt[3];
        scanf("%s", opt);
        switch (opt[0])
        {
        case 'a':
            int x;
            scanf("%d", &x);
            Treap.Insert(Treap.root, x);
            n++;
            break;
        case 'm':
            x = (n + 1) / 2;
            printf("%d\n", Treap.GetVal(Treap.root, x + 1));
            break;
        }
    }
    return 0;
}