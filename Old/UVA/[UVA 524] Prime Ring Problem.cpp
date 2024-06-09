#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
const int N = 50 + 5;
int n;
int a[N];
bool vis[N], ispri[N];
void print()
{
    if (!ispri[1 + a[n]]) return;
    for (int i = 1; i < n; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n]);
}
void dfs(int i)
{
    if (i == n + 1) return print(), void();
    for (int j = 2; j <= n; j++)
        if (!vis[j] and ispri[a[i - 1] + j])
            vis[j] = 1, a[i] = j, dfs(i + 1), vis[j] = 0;
}

signed main()
{
    freopen("x.in", "r", stdin);
    // freopen("x.out", "w", stdout);
    for (int i = 2; i <= 50; i++)
        if (is_prime(i))
            ispri[i] = 1;
    vis[1] = a[1] = 1;
    for (int i = 1; ~scanf("%d", &n); i++)
    {
        if (i != 1) puts("");
        printf("Case %d:\n", i);
        dfs(2);
    }
    return 0;
}