#include <stdio.h>
#include <algorithm>

#define ls (u << 1)
#define rs (u << 1 | 1)

const int N = 1e3 + 5;
const int M = 3e3 + 5;

int m;
int wei[N << 2], val[N];
int f[N][M];

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

void build(int u)
{
    wei[u] = read(), wei[u] <<= 1, val[u] = read();
    if (!val[u])
        build(ls), build(rs);
}

void dfs(int u, int time)
{
    if (!val[u])
    {
        dfs(ls, time + wei[ls]), dfs(rs, time + wei[rs]);
        for (int i = 0; i + time <= m; i++)
            for (int j = 0; i + j + time <= m; j++)
                f[u][time + i + j] = std::max(f[u][time + i + j], f[ls][time + i] + f[rs][time + j]);
    }
    else
    {
        for (int i = 1; i <= val[u]; i++)
        {
            int now = time + i * 5;
            if (now > m)
                break;
            f[u][now] = f[u][now - 5] + 1;
        }
    }
}

int main()
{
    m = read(), m--;
    build(1);
    dfs(1, wei[1]);
    printf("%d", f[1][m]);
    return 0;
}