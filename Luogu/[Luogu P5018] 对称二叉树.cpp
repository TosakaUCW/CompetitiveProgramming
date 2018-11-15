#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e6;

int n, ans;
int v[N + 5], l[N + 5], r[N + 5];
bool flag;

int dfs(int x, int y, int tot)
{
    if (x == -1 and y == -1)
        return 0;
    if (v[x] != v[y])
    {
        flag = false;
        return 0;
    }
    if (x == -1 or y == -1)
    {
        flag = false;
        return 0;
    }
    return dfs(l[x], r[y], 2) + dfs(r[x], l[y], 2) + tot;
}

int main()
{
    scanf("%d", &n);
    Rep(i, 1, n)
        scanf("%d", &v[i]);
    Rep(i, 1, n)
        scanf("%d%d", &l[i], &r[i]);
    ans = 1;
    Rep(i, 1, n)
    {
        flag = true;
        int tot = dfs(l[i], r[i], 3);
        if (tot > ans and flag)
            ans = tot;
    }
    printf("%d", ans);
    return 0;
}