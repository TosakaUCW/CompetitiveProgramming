#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

const int N = 100 + 5;

int n, m, sum, repeat = 2e5;
int a[N], b[N];
double ans = 1 << 30;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum += a[i];
    double adv = 1.0 * sum / m;
    while (repeat--)
    {
        memset(b, 0, sizeof b);
        std::random_shuffle(a + 1, a + 1 + n);
        int t = 1;
        double res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 2; j <= m; j++)
                if (b[j] < b[t])
                    t = j;
            b[t] += a[i];
            t = 1;
        }
        for (int i = 1; i <= m; i++)
            res += pow(adv - b[i], 2);
        res /= m;
        ans = std::min(ans, res);
    }
    printf("%.2lf", sqrt(ans));
    return 0;
}