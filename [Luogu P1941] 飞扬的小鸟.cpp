#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;
const int M = 1e3 + 5;
const int INF = 1 << 30;

int n, m, k;
int lift[N], down[N];
int f[N][M];

struct Node
{
    int pos, up, low;
} pip[N];

bool cmp(Node a, Node b) { return a.pos < b.pos; }

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &lift[i], &down[i]);
    for (int i = 1; i <= k; i++)
        scanf("%d%d%d", &pip[i].pos, &pip[i].low, &pip[i].up);
    std::sort(pip + 1, pip + 1 + k, cmp);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[i][j] = INF;
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
    int nump = 1;
    for (int i = 1; i <= n; i++)
    {
        int lower = 1, upper = m;
        if (pip[nump].pos == i)
            upper = pip[nump].up - 1, lower = pip[nump++].low + 1;
        for (int j = 1; j <= upper; j++)
            for (int k = j - lift[i - 1]; k <= m; k++)
            {
                if (k > j - lift[i - 1] and j < m)
                    break;
                if (k >= 1)
                    f[i][j] = std::min(f[i][j], std::min(f[i - 1][k], f[i][k]) + 1);
            }
        for (int j = lower; j <= upper; j++)
            if (j + down[i - 1] <= m)
                f[i][j] = std::min(f[i][j], f[i - 1][j + down[i - 1]]);
        for (int j = 1; j < lower; j++)
            f[i][j] = INF;
    }
    int min = INF;
    bool flag = false;
    for (int i = n; i; i--)
    {
        for (int j = 1; j <= m; j++)
            if (f[i][j] != INF)
                flag = true, min = std::min(min, f[i][j]);
        if (flag)
            if (i == n)
            {
                printf("1\n%d", min);
                return 0;
            }
            else
                for (int j = k; j; j--)
                    if (i >= pip[j].pos)
                    {
                        printf("0\n%d", j);
                        return 0;
                    }
    }
    printf("0\n0");
    return 0;
}