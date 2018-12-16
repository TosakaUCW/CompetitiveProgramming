#include <memory.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 50;
const int M = 1e5;

int n, m;
int f[M + 5];

int main()
{
    int T;
    scanf("%d", &T);
    Rep(cas, 1, T)
    {
        memset(f, 0x8f, sizeof(f));
        scanf("%d%d", &n, &m);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int v;
            scanf("%d", &v);
            for (int j = m - 1; j >= v; j--)
                f[j] = std::max(f[j], f[j - v] + 1);
        }
        int ans = m;
        for (int i = m - 1; i >= 0; i--)
            if (f[i] > f[ans] or (f[i] == f[ans] and i > ans))
                ans = i;
        printf("Case %d: %d %d\n", cas, f[ans] + 1, ans + 678);
    }
    return 0;
}