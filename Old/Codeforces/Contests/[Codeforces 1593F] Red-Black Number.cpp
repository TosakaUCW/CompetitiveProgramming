#include <stdio.h>
#include <algorithm>
#include <mem.h>
#include <iostream>
#include <string>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 40 + 5;

int n, A, B;
std::string s;
int f[N][N][N][N], g[N][N][N][N];
bool dp[N][N][N][N], ans[N];

void print(int j)
{
    int a = 0, b = 0;
    for (int i = n; i >= 1; i--)
        if (f[i][j][a][b] != -1)
            b = f[i][j][a][b], ans[i] = 1, j--;
        else
            a = g[i][j][a][b], ans[i] = 0;
    for (int i = 1; i <= n; i++)
        putchar(ans[i] ? 'B' : 'R');
    puts("");
}

void solve()
{
    std::cin >> n >> A >> B >> s;
    memset(dp, 0, sizeof dp), memset(f, -1, sizeof f), memset(g, -1, sizeof g);
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            for (int a = 0; a < A; a++)
                for (int b = 0; b < B; b++)
                    if (dp[i - 1][j][a][b])
                    {
                        dp[i][j + 1][a][(b * 10 + s[i - 1] - '0') % B] = 1;
                        f[i][j + 1][a][(b * 10 + s[i - 1] - '0') % B] = b;
                        dp[i][j][(a * 10 + s[i - 1] - '0') % A][b] = 1;
                        g[i][j][(a * 10 + s[i - 1] - '0') % A][b] = a;
                    }
    int ans = 999;
    for (int j = 1; j < n; j++)
        if (dp[n][j][0][0] and abs(n - j - j) < abs(n - ans - ans))
            ans = j;
    if (ans == 999)
        puts("-1");
    else
        print(ans);
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}