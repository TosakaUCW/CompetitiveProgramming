#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 20 + 5;

int L, R;
int a[N], f[N][2];

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

int dfs(int pos, int pre, int sta, bool limit)
{
    if (pos == -1)
        return 1;
    if (!limit and f[pos][sta] != -1)
        return f[pos][sta];
    int up = limit ? a[pos] : 9, tmp = 0;
    for (int i = 0; i <= up; i++)
    {
        if (pre == 6 and i == 2)
            continue;
        if (i == 4)
            continue;
        tmp += dfs(pos - 1, i, i == 6, limit and i == a[pos]);
    }
    if (!limit)
        f[pos][sta] = tmp;
    return tmp;
}

int solve(int x, int pos = 0)
{
    for (; x; x /= 10)
        a[pos++] = x % 10;
    return dfs(pos - 1, -1, 0, true);
}

int main()
{
    for (memset(f, -1, sizeof f); (L = read()) and (R = read());)
        printf("%d\n", solve(R) - solve(L - 1));
    return 0;
}