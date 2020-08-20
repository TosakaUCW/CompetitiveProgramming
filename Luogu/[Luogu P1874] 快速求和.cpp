#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>
#include <stdlib.h>

const int N = 50 + 5;
const int INF = 2147483647;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int tar, ans = INF;
int n, a[N];
std::string str;

int val(int L, int R)
{
    int res = 0;
    for (int i = L; i <= R; i++)
        res = res * 10 + a[i];
    return res;
}

int val_only(int L, int R)
{
    int res = 0;
    for (int i = L; i <= R; i++)
        res += a[i];
    return res;
}

void dfs(int sum, int pos, int depth)
{
    if (depth >= ans or sum + val(pos + 1, n) < tar or sum + val_only(pos + 1, n) > tar)
        return;
    if (sum + val(pos + 1, n) == tar)
    {
        ans = std::min(ans, depth);
        return;
    }
    for (int i = pos + 1; i <= n; i++)
        dfs(sum + val(pos + 1, i), i, depth + 1);
}

int main()
{
    std::cin >> str >> tar;
    n = str.length();
    for (int i = 0; i < n; i++)
        a[i + 1] = str[i] - '0';
    if (val_only(1, n) > tar)
    {
        puts("-1");
        return 0;
    }
    dfs(0, 0, 0);
    printf("%d", ans == INF ? -1 : ans);
    return 0;
}