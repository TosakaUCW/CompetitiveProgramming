#include <stdio.h>
#include <stdlib.h>

const int SIZE = 1e5 + 5;
const int INF = 2147483647;

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
    void Delete(int &p, int val)
    {
        if (p == 0)
            return;
        if (val == a[p].val)
        {
            if (a[p].cnt > 1)
            {
                a[p].cnt--, Update(p);
                return;
            }
            if (a[p].l or a[p].r)
            {
                if (a[p].r == 0 or a[a[p].l].dat > a[a[p].r].dat)
                    Zig(p), Delete(a[p].r, val);
                else
                    Zag(p), Delete(a[p].l, val);
                Update(p);
            }
            else
                p = 0;
            return;
        }
        val < a[p].val ? Delete(a[p].l, val) : Delete(a[p].r, val);
        Update(p);
    }
    int GetPre(int val)
    {
        int ans = 1;
        int p = root;
        while (p)
        {
            if (val == a[p].val)
            {
                if (a[p].l > 0)
                {
                    p = a[p].l;
                    while (a[p].r > 0)
                        p = a[p].r;
                    ans = p;
                }
                break;
            }
            if (a[p].val < val and a[p].val > a[ans].val)
                ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
    int GetNext(int val)
    {
        int ans = 2;
        int p = root;
        while (p)
        {
            if (val == a[p].val)
            {
                if (a[p].r > 0)
                {
                    p = a[p].r;
                    while (a[p].l > 0)
                        p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val and a[p].val < a[ans].val)
                ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
    int GetRank(int p, int val)
    {
        if (p == 0)
            return 0;
        if (val == a[p].val)
            return a[a[p].l].size + 1;
        if (val < a[p].val)
            return GetRank(a[p].l, val);
        return GetRank(a[p].r, val) + a[a[p].l].size + a[p].cnt;
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
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
        case 1:
            Treap.Insert(Treap.root, x);
            break;
        case 2:
            Treap.Delete(Treap.root, x);
            break;
        case 3:
            printf("%d\n", Treap.GetRank(Treap.root, x) - 1);
            break;
        case 4:
            printf("%d\n", Treap.GetVal(Treap.root, x + 1));
            break;
        case 5:
            printf("%d\n", Treap.GetPre(x));
            break;
        case 6:
            printf("%d\n", Treap.GetNext(x));
            break;
        }
    }
    return 0;
}