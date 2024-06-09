#include <stdio.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

struct Splay
{
    int rt, tot;
    int fa[N], ch[N][2], val[N], cnt[N], sz[N];
    void update(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }
    bool get(int x) { return x == ch[fa[x]][1]; }
    void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0; }
    void rotate(int x)
    {
        int y = fa[x], z = fa[y], chk = get(x);
        ch[y][chk] = ch[x][chk ^ 1];
        if (ch[x][chk ^ 1])
            fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y, fa[y] = x, fa[x] = z;
        if (z)
            ch[z][y == ch[z][1]] = x;
        update(x), update(y);
    }
    void splay(int x)
    {
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f])
                rotate(get(x) == get(f) ? f : x);
        rt = x;
    }
    void ins(int k)
    {
        if (!rt)
            return val[rt = ++tot] = k, cnt[rt]++, update(rt), void();
        for (int cur = rt, f = 0; 1;)
        {
            if (val[cur] == k)
            {
                cnt[cur]++, update(cur), update(f), splay(cur);
                break;
            }
            f = cur, cur = ch[cur][val[cur] < k];
            if (!cur)
            {
                val[++tot] = k, cnt[tot]++, fa[tot] = f;
                ch[f][val[f] < k] = tot;
                update(tot), update(f);
                splay(tot);
                break;
            }
        }
    }
    int rank(int k)
    {
        for (int res = 0, cur = rt; 1;)
            if (k < val[cur])
                cur = ch[cur][0];
            else
            {
                res += sz[ch[cur][0]];
                if (k == val[cur])
                    return splay(cur), res + 1;
                res += cnt[cur], cur = ch[cur][1];
            }
    }
    int kth(int k)
    {
        for (int cur = rt; 1;)
            if (ch[cur][0] and k <= sz[ch[cur][0]])
                cur = ch[cur][0];
            else
            {
                k -= cnt[cur] + sz[ch[cur][0]];
                if (k <= 0)
                    return splay(cur), val[cur];
                cur = ch[cur][1];
            }
    }
    int pre()
    {
        int cur = ch[rt][0];
        while (ch[cur][1])
            cur = ch[cur][1];
        return splay(cur), cur;
    }
    int nxt()
    {
        int cur = ch[rt][1];
        while (ch[cur][0])
            cur = ch[cur][0];
        return splay(cur), cur;
    }
    void del(int k)
    {
        rank(k);
        if (cnt[rt] > 1)
            cnt[rt]--, update(rt);
        else if (!ch[rt][0] and !ch[rt][1])
            clear(rt), rt = 0;
        else if (!ch[rt][0] or !ch[rt][1])
        {
            int cur = rt;
            rt = ch[rt][0] | ch[rt][1], fa[rt] = 0;
            clear(cur);
        }
        else
        {
            int cur = rt;
            int x = pre();
            fa[ch[cur][1]] = x;
            ch[x][1] = ch[cur][1];
            clear(cur), update(rt);
        }
    }
} t;

int main()
{
    for (int m = read(); m--;)
    {
        int opt = read(), x = read();
        if (opt == 1)
            t.ins(x);
        if (opt == 2)
            t.del(x);
        if (opt == 3)
            printf("%d\n", t.rank(x));
        if (opt == 4)
            printf("%d\n", t.kth(x));
        if (opt == 5)
            t.ins(x), printf("%d\n", t.val[t.pre()]), t.del(x);
        if (opt == 6)
            t.ins(x), printf("%d\n", t.val[t.nxt()]), t.del(x);
    }
    return 0;
}