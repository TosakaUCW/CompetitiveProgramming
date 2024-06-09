#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e3 + 5;
const int M = 1e6 + 5;

int n, p, S, ans = -1;
int wei[N], val[N], f[M];

bool judge(int x)
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
        for (int j = S; j >= wei[i]; j--)
            if (wei[i] <= x)
                f[j] = std::max(f[j], f[j - wei[i]] + val[i]);
    return f[S] >= p;
}

int main()
{
    int L = 0, R = 0;
    scanf("%d%d%d", &n, &p, &S);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wei[i], &val[i]), R = std::max(R, wei[i]);
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    if (ans == -1)
        printf("No Solution!");
    else
        printf("%d", ans);
    return 0;
}