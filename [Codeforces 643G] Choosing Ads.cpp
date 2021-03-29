#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 15e4 + 5;

int n, m, p;

struct Seg_Tree
{
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

    struct Node
    {
        int num, tag, val[5], cnt[5];
        Node operator=(Node x) { return num = x.num, tag = 0, memcpy(val, x.val, sizeof val), memcpy(cnt, x.cnt, sizeof cnt), *this; }
    } t[N << 2];

    Node friend operator+(Node x, Node y)
    {
        Node res = y;
        for (int i = 0; i < x.num; i++)
        {
            bool flag = false;
            for (int j = 0; j < res.num and !flag; j++)
                if (x.val[i] == res.val[j])
                    res.cnt[j] += x.cnt[i], flag = true;
            if (flag)
                continue;
            if (res.num < p)
            {
                res.val[res.num] = x.val[i], res.cnt[res.num++] = x.cnt[i];
                continue;
            }
            int k = 0;
            for (int j = 1; j < res.num; j++)
                if (res.cnt[j] < res.cnt[k])
                    k = j;
            if (x.cnt[i] < res.cnt[k])
                for (int j = 0; j < res.num; j++)
                    res.cnt[j] -= x.cnt[i];
            else
            {
                int tmp = res.cnt[k];
                res.val[k] = x.val[i], res.cnt[k] = x.cnt[i];
                for (int j = 0; j < res.num; j++)
                    res.cnt[j] -= tmp;
            }
        }
        return res;
    }

    void maintain(int p, int len, int val) { t[p].num = 1, t[p].tag = t[p].val[0] = val, t[p].cnt[0] = len; }

    void push_up(int p) { t[p] = t[ls] + t[rs]; }

    void push_down(int p, int len)
    {
        if (t[p].tag)
            maintain(ls, len - len / 2, t[p].tag), maintain(rs, len / 2, t[p].tag), t[p].tag = 0;
    }

    void build(int p, int l, int r)
    {
        if (l == r)
            return t[p].val[0] = read(), t[p].cnt[0] = t[p].num = 1, void();
        build(ls, l, mid), build(rs, mid + 1, r), push_up(p);
    }
    void modify(int p, int l, int r, int x, int y, int val)
    {
        if (l == x and r == y)
            return maintain(p, r - l + 1, val), void();
        push_down(p, r - l + 1);
        if (x <= mid)
            modify(ls, l, mid, x, std::min(mid, y), val);
        if (mid < y)
            modify(rs, mid + 1, r, std::max(mid + 1, x), y, val);
        push_up(p);
    }
    Node query(int p, int l, int r, int x, int y)
    {
        if (l == x and r == y)
            return t[p];
        push_down(p, r - l + 1);
        if (y <= mid)
            return query(ls, l, mid, x, y);
        else if (mid < x)
            return query(rs, mid + 1, r, x, y);
        else
            return query(ls, l, mid, x, mid) + query(rs, mid + 1, r, mid + 1, y);
    }
    void getans(int l, int r)
    {
        Node ans = query(1, 1, n, l, r);
        printf("%d ", ans.num);
        for (int i = 0; i < ans.num; i++)
            printf("%d ", ans.val[i]);
        puts("");
    }
} T;

int main()
{
    n = read(), m = read(), p = 100 / read(), T.build(1, 1, n);
    for (; m--;)
    {
        int opt = read(), l = read(), r = read();
        if (opt == 1)
            T.modify(1, 1, n, l, r, read());
        else
            T.getans(l, r);
    }
    return 0;
}