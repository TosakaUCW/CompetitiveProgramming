#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, W;
int wei[N], val[N], cnt;
int f[N];

int main()
{
    scanf("%d%d", &n, &W);
    for (int i = 1; i <= n; i++)
    {
        int v, w, m;
        scanf("%d%d%d", &v, &w, &m);
        for (int j = 1; j <= m; j <<= 1)
        {
            wei[++cnt] = j * w;
            val[cnt] = j * v;
            m -= j;
        }
        if (m)
            wei[++cnt] = m * w, val[cnt] = m * v;
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = W; j >= wei[i]; j--)
            f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    printf("%d", f[W]);
    return 0;
}