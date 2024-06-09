#include <stdio.h>
#include <algorithm>

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, q;
int ch[N][2], f[N], siz[N];

#define ls ch[p][0]
#define rs ch[p][1]
#define get(x) (ch[f[x]][1] == x)
#define isRoot(x) (ch[f[x]][0] != x and ch[f[x]][1] != x)
void pushUp(int p)
{
    siz[p] = siz[ls] + siz[rs] + 1;
}
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
    for (int fa; fa = f[x], !isRoot(x); Rotate(x))
        if (!isRoot(fa))
            Rotate(get(x) == get(fa) ? fa : x);
    pushUp(x);
}
int Access(int x, int p = 0)
{
    for (p = 0; x; p = x, x = f[x])
        Splay(x), ch[x][1] = p, pushUp(x);
    return p;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1, x; i <= n; i++)
    {
        siz[i] = 1, x = read();
        if (i + x <= n)
            f[i] = i + x;
    }
    for (q = read(); q--;)
    {
        int opt = read(), x = read() + 1;
        Access(x), Splay(x);
        if (opt == 1)
            printf("%d\n", siz[x]);
        else
        {
            int y = read();
            ch[x][0] = f[ch[x][0]] = 0;
            if (x + y <= n)
                f[x] = x + y;
            pushUp(x);
        }
    }
    return 0;
}