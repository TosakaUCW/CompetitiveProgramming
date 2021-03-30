#include <stdio.h>
#include <algorithm>
#include <memory.h>

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, q, val[N];
int ch[N][2], f[N], sum[N], tag[N];

#define ls ch[p][0]
#define rs ch[p][1]
#define get(x) (ch[f[x]][1] == x)
#define isRoot(x) (ch[f[x]][0] != x and ch[f[x]][1] != x)
void pushDown(int p)
{
    if (tag[p])
    {
        swap(ch[ls][0], ch[ls][1]);
        swap(ch[rs][0], ch[rs][1]);
        tag[ls] ^= 1, tag[rs] ^= 1, tag[p] ^= 1;
    }
}
void Update(int p)
{
    if (!isRoot(p))
        Update(f[p]);
    pushDown(p);
}
void pushUp(int p) { sum[p] = sum[ls] ^ sum[rs] ^ val[p]; }
void Rotate(int x)
{
    int y = f[x], z = f[y], k = get(x);
    if (!isRoot(y))
        ch[z][ch[z][1] == y] = x;
    ch[y][k] = ch[x][!k], f[ch[y][k]] = y;
    ch[x][!k] = y, f[y] = x, f[x] = z;
    pushUp(y), pushUp(x);
}
void Splay(int x)
{
    Update(x);
    for (int fa; fa = f[x], !isRoot(x); Rotate(x))
        if (!isRoot(fa))
            Rotate(get(x) == get(fa) ? fa : x);
}
int Access(int x, int p = 0)
{
    for (p = 0; x; p = x, x = f[x])
        Splay(x), ch[x][1] = p, pushUp(x);
    return p;
}
void makeRoot(int p) { p = Access(p), swap(ch[p][0], ch[p][1]), tag[p] ^= 1; }
void Link(int x, int p) { makeRoot(x), Splay(x), f[x] = p; }
void Split(int x, int p) { makeRoot(x), Access(p), Splay(p); }
void Cut(int x, int p)
{
    Split(x, p);
    if (ls == x && !ch[x][1])
        ls = f[x] = 0;
}
int Find(int p)
{
    Access(p), Splay(p);
    while (ls)
        pushDown(p), p = ls;
    Splay(p);
    return p;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        val[i] = read();
    for (int opt, x, y; q--;)
    {
        opt = read(), x = read(), y = read();
        if (opt == 0)
            Split(x, y), printf("%d\n", sum[y]);
        if (opt == 1)
        {
            int dx = Find(x), dy = Find(y);
            if (dx != dy)
                Link(x, y);
        }
        if (opt == 2)
            Cut(x, y);
        if (opt == 3)
            Split(x, x), val[x] = sum[x] = y;
    }
    return 0;
}