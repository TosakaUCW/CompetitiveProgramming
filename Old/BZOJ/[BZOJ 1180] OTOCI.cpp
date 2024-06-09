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

const int N = 3e4 + 5;

int n, val[N];
int ch[N][2], f[N], sum[N], tag[N];

#define ls (ch[p][0])
#define rs (ch[p][1])
#define get(x) (ch[f[x]][1] == x)
#define isRoot(p) (ch[f[p]][0] != p and ch[f[p]][1] != p)
void pushDown(int p)
{
    if (tag[p])
    {
        swap(ch[ls][0], ch[ls][1]);
        swap(ch[rs][0], ch[rs][1]);
        tag[ls] ^= 1, tag[rs] ^= 1, tag[p] ^= 1;
    }
}
void update(int p)
{
    if (!isRoot(p))
        update(f[p]);
    pushDown(p);
}
void pushUp(int p) { sum[p] = sum[ls] + sum[rs] + val[p]; }
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
    update(x);
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
void Cut(int x, int p) { Split(x, p), ls = f[x] = 0; }
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
    n = read();
    for (int i = 1; i <= n; i++)
        val[i] = read();
    for (int q = read(); q--;)
    {
        static char opt[20];
        scanf("%s", opt);
        int x = read(), y = read();
        if (opt[0] == 'b')
        {
            int dx = Find(x), dy = Find(y);
            if (dx != dy)
                puts("yes"), Link(x, y);
            else
                puts("no");
        }
        else if (opt[0] == 'p')
            Split(x, x), val[x] = sum[x] = y;
        else
        {
            int dx = Find(x), dy = Find(y);
            if (dx != dy)
                puts("impossible");
            else
                Split(x, y), printf("%d\n", sum[y]);
        }
    }
    return 0;
}