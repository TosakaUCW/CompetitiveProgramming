// luogu-judger-enable-o2
#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 4e4 + 5;

int n, m, ans;
int l, r, l0, r0;
int a[N], b[N], c[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memcpy(b, a, sizeof a);
    std::sort(b + 1, b + n + 1);
    int tot = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + tot + 1, a[i]) - b;
    while (m--)
    {
        scanf("%d%d", &l0, &r0);
        l = (l0 + ans - 1) % n + 1;
        r = (r0 + ans - 1) % n + 1;
        if (l > r)
            std::swap(l, r);
        for (int i = l; i <= r; i++)
            c[a[i]]++;
        int max = 0, pos = 0;
        for (int i = 1; i <= tot; i++)
            if (max < c[i])
            {
                max = c[i];
                pos = i;
            }
        ans = b[pos];
        printf("%d\n", ans);
        memset(c, 0, sizeof c);
    }
    return 0;
}