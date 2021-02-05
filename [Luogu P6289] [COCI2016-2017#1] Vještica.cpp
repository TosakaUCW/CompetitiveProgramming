#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n;
int f[N];
int pre[N][30], sum[20][30];
char str[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    memset(f, 0x3f, sizeof f), memset(pre, 0x3f, sizeof pre);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str + 1);
        sum[i][0] = strlen(str + 1);
        for (int j = 1; j <= sum[i][0]; j++)
            sum[i][str[j] - 'a' + 1]++;
        f[1 << i - 1] = sum[i][0];
    }
    for (int s = 1; s < (1 << n); s++)
    {
        for (int i = 1; i <= n; i++)
            if ((s >> i - 1) & 1)
                for (int j = 1; j <= 26; j++)
                    pre[s][j] = std::min(pre[s][j], sum[i][j]);
        pre[s][0] = 0;
        for (int i = 1; i <= 26; i++)
            pre[s][0] += pre[s][i];
        for (int S = s & (s - 1); S; S = (S - 1) & s)
            f[s] = std::min(f[s], f[S] + f[S ^ s] - pre[s][0]);
    }
    return printf("%d", f[(1 << n) - 1] + 1), 0;
}