#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, T, ans;
int col[N], f[N];
int siz[N], hd[N], nxt[N], st[N];

void solve()
{
    int opt = read();
    if (opt == 1)
    {
        int x = read(), y = read();
        if (siz[f[x]] > siz[f[y]]) std::swap(f[x], f[y]);
        if (!siz[f[x]] or f[x] == f[y]) return;
        x = f[x], y = f[y];
        for (int i = hd[x]; i; i = nxt[i]) ans -= (col[i - 1] == y) + (col[i + 1] == y);
        for (int i = hd[x]; i; i = nxt[i]) col[i] = y;
        nxt[st[x]] = hd[y], hd[y] = hd[x], siz[y] += siz[x];
        hd[x] = st[x] = siz[x] = 0;
    }
    else
        printf("%d\n", ans);
}

int main()
{
    freopen("P3201_1.in", "r", stdin);
    freopen("b.out", "w", stdout);
    n = read(), T = read();
    for (int i = 1; i <= n; i++)
    {
        col[i] = read(), f[col[i]] = col[i];
        if (col[i] != col[i - 1]) ans++;
        if (!hd[col[i]]) st[col[i]] = i;
        ++siz[col[i]], nxt[i] = hd[col[i]], hd[col[i]] = i;
    }
    for (; T--; solve());
    return 0;
}
