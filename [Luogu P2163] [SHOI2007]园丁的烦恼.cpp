#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

#define lowbit(x) (x & -x)

const int N = 1e7 + 5;

int n, m;
int c[N];
int ans[N][5];

struct Node
{
    int x, y, pos, idx;
    bool friend operator<(Node a, Node b)
    {
        if (a.x ^ b.x)
            return a.x < b.x;
        if (a.y ^ b.y)
            return a.y < b.y;
        return a.pos < b.pos;
    }
} a[N * 5];

void add(int x, int k)
{
    for (; x <= n; x += lowbit(x))
        c[x] += k;
}

int query(int x)
{
    int res = 0;
    for (; x >= 1; x -= lowbit(x))
        res += c[x];
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), m = read();
    for (int i = 1, x, y; i <= n; i++)
        x = read(), y = read(), a[i] = {x, y, 0};
    for (int i = 1, x1, x2, y1, y2; i <= m; i++)
    {
        x1 = read(), y1 = read(), x2 = read(), y2 = read();
        a[++n] = {x1 - 1, y1 - 1, i, 1};
        a[++n] = {x1 - 1, y2, i, 2};
        a[++n] = {x2, y1 - 1, i, 3};
        a[++n] = {x2, y2, i, 4};
    }
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        if (a[i].pos)
            ans[a[i].pos][a[i].idx] = query(a[i].y + 1);
        else
            add(a[i].y + 1, 1);
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i][4] - ans[i][3] - ans[i][2] + ans[i][1]);
    return 0;
}