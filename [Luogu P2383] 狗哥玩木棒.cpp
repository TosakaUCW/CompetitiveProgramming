#include <memory.h>
#include <stdio.h>
#include <algorithm>

const int N = 20 + 5;
const int M = 2e4 + 5;

int n, tot;
int a[N];
bool used[N];
bool flag;

void dfs(int sum, int cnt)
{
    if (!flag)
        return;
    if (sum > tot / 4)
        return;
    if (sum == tot / 4)
        sum = 0, cnt++;
    if (cnt == 4)
    {
        puts("yes");
        flag = false;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
        {
            used[i] = true;
            dfs(sum + a[i], cnt);
            used[i] = false;
            if (sum == 0 or sum + a[i] == 0)
                return;
        }
}

bool cmp(int a, int b) { return a > b; }

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int max = 0;
        tot = 0;
        flag = true;
        memset(used, 0, sizeof used);
        std::sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), tot += a[i], max = std::max(max, a[i]);
        if (tot % 4 != 0 or tot / 4 < max)
            puts("no"), flag = false;
        else
            dfs(0, 0);
        if (flag)
            puts("no");
    }
    return 0;
}