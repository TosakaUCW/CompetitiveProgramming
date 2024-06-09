#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 4e7 + 5;

int a[N], b[N];
bool vis[N];

void prepare()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i]) a[++a[0]] = i;
        for (int j = 1; j <= a[0] and i * a[j] < N; j++)
        {
            vis[i * a[j]] = 1;
            if (i % a[j] == 0) break;
        }
    }
    for (int i = 1; i <= 20000001; i++)
        if (!vis[2 * i + 1]) b[++b[0]] = i;
}

int solve()
{
    int x = read(), y, z;
    if (x == 0) return 3;
    if (x < 0)
    {
        y = a[std::lower_bound(a + 1, a + 1 + a[0], 1 - x) - a];
        z = b[std::lower_bound(b + 1, b + 1 + b[0], 1 - x) - b];
        return y <= z ? 2 * y : 2 * z + 1;
    }
    if (x > 0)
    {
        if (!vis[x]) return 1;
        if (!vis[2 * x + 1] or !vis[2 * x - 1]) return 2;
        y = a[std::lower_bound(a + 1, a + 1 + a[0], x + 1) - a];
        z = b[std::lower_bound(b + 1, b + 1 + b[0], x + 1) - b];
        return y <= z ? 2 * y : 2 * z + 1;
    }
}

int main()
{
    prepare();
    for (int T = read(); T--; printf("%d\n", solve()));
    return 0;
}
