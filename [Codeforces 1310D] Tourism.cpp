#include <stdio.h>
#include <algorithm>
#include <time.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 80 + 5;
const int K = 10 + 5;
const int INF = 0x3f3f3f3f;

int n, k, ans = INF;
int col[N];
int dis[N][N], f[K][N];

int main()
{
    srand(unsigned(time(NULL)));
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = read();
    for (int T = 5000; T--;)
    {
        for (int i = 1; i <= n; i++)
            col[i] = rand() & 1, f[0][i] = INF;
        f[0][1] = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 1; j <= n; j++)
                f[i + 1][j] = INF;
            for (int u = 1; u <= n; u++)
                for (int v = 1; v <= n; v++)
                    if (col[u] ^ col[v])
                        f[i + 1][v] = std::min(f[i + 1][v], f[i][u] + dis[u][v]);
        }
        ans = std::min(ans, f[k][1]);
    }
    return printf("%d", ans), 0;
}