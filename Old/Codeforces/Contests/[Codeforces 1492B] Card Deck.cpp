#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n;
int b[N];
bool vis[N];

struct Node
{
    int val, pos;
    bool friend operator<(Node a, Node b) { return a.val > b.val; }
} a[N];

signed main()
{
    for (int T = read(); T--;)
    {
        n = read();
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++)
            a[i].val = b[i] = read(), a[i].pos = i;
        std::sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            int p = a[i].pos;
            while (p <= n and !vis[p])
                printf("%lld ", b[p]), vis[p] = true, p++;
        }
    }
    return 0;
}