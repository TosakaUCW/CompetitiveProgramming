#include <stdio.h>
#include <algorithm>
#include <iostream>

#define int long long
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
const int P = 51061;

int n, q;
int ch[N][2], f[N], siz[N], val[N], sum[N], rev[N], add[N], mul[N];
#define ls ch[p][0]
#define rs ch[p][1]
#define get(x) (ch[f[x]][1] == x)
#define isRoot(x) (ch[f[x]][0] != x and ch[f[x]][1] != x)
void pushUp(int p)
{
    siz[p] = siz[ls] + siz[rs] + 1,
    sum[p] = (sum[ls] + sum[rs] + val[p]) % P;
}
void MUL(int p, int c)
{
    sum[p] = sum[p] * c % P, val[p] = val[p] * c % P,
    mul[p] = mul[p] * c % P, add[p] = add[p] * c % P;
}
void ADD(int p, int c)
{
    sum[p] = (sum[p] + c * siz[p] % P) % P,
    val[p] = (val[p] + c) % P, add[p] = (add[p] + c) % P;
}
void pushDown(int p)
{
    if (mul[p] != 1)
        MUL(ls, mul[p]), MUL(rs, mul[p]), mul[p] = 1;
    if (add[p])
        ADD(ls, add[p]), ADD(rs, add[p]), add[p] = 0;
    if (rev[p])
    {
        swap(ch[ls][0], ch[ls][1]), swap(ch[rs][0], ch[rs][1]);
        rev[ls] ^= 1, rev[rs] ^= 1, rev[p] ^= 1;
    }
}
void Update(int x)
{
    if (!isRoot(x))
        Update(f[x]);
    pushDown(x);
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
void makeRoot(int p) { p = Access(p), swap(ch[p][0], ch[p][1]), rev[p] ^= 1; }
void Link(int x, int p) { makeRoot(x), Splay(x), f[x] = p; }
void Split(int x, int p) { makeRoot(x), Access(p), Splay(p); }
void Cut(int x, int p)
{
    Split(x, p);
    if (ls == x and !ch[x][1])
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

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin), freopen("x.out", "w", stdout);
#endif // !ONLINE_JUDGE
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        val[i] = siz[i] = mul[i] = 1;
    for (int i = 1, u, v; i < n; i++)
        if (Find(u = read()) != Find(v = read()))
            Link(u, v);
    for (int u, v, c; q--;)
    {
        char opt;
        std::cin >> opt >> u >> v;
        if (opt == '+')
            Split(u, v), ADD(v, read());
        if (opt == '-')
            Cut(u, v), u = read(), v = read(), Link(u, v);
        if (opt == '*')
            Split(u, v), MUL(v, read());
        if (opt == '/')
            Split(u, v), printf("%lld\n", sum[v]);
    }
    return 0;
}