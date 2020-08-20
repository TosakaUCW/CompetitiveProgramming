#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int n, k;
int a[N], b[N], c[N], an, bn, cn;
int ans;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        //printf("%d %d %d\n", an, bn, cn);
        if (y == 1 and z == 1)
            c[++cn] = x;
        else if (y == 1)
            a[++an] = x;
        else if (z == 1)
            b[++bn] = x;
    }

    std::sort(a + 1, a + 1 + an);
    std::sort(b + 1, b + 1 + bn);
    for (int i = 1; i <= std::min(an, bn); i++)
        c[++cn] = a[i] + b[i];
    std::sort(c + 1, c + 1 + cn);
    //for (int i = 1; i <= cn; i++)
    //    printf("%d ", c[i]);
    for (int i = 1; i <= k; i++)
        ans += c[i];
    printf("%d", cn < k ? -1 : ans);
    return 0;
}