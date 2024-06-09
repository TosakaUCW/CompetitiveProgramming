#include <bits/stdc++.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == '-', ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e3 + 5;

int n, k;
int a[N], sum[N];
int f[N], pre[N][N], suf[N][N];
bool vis[N];

void solve()
{
    std::string s;
    std::cin >> n >> k >> s;
    s = '*' + s;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + s[i] - '0',
        s[i] = s[i] - '0',
        vis[i] = f[i] = 0;
    for (int i = 0; i <= k; i++)
        suf[n + 1][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, pos = i - 1;
        for (int j = 0; j <= k; j++)
        {
            while (cnt <= j and pos <= n)
            {
                pos++;
                if (s[pos] == 0)
                    cnt++;
            }
            suf[i][j] = pos - i;
        }
    }
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= k; j++)
            suf[i][j] = std::max(suf[i][j], suf[i + 1][j]);

    for (int i = n; i >= 1; i--)
    {
        int cnt = 0, pos = i + 1;
        for (int j = 0; j <= k; j++)
        {
            while (cnt <= j and pos >= 1)
            {
                pos--;
                if (s[pos] == 0)
                    cnt++;
            }
            pre[i][j] = i - pos;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            pre[i][j] = std::max(pre[i][j], pre[i - 1][j]);

    vis[0] = 1;
    f[0] = std::max(pre[n][k], suf[1][k]);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int l0 = j - i + 1;
            int k0 = k - (sum[j] - sum[i - 1]);
            if (k0 < 0)
                break;
            f[l0] = std::max(f[l0], pre[i - 1][k0]);
            f[l0] = std::max(f[l0], suf[j + 1][k0]);
            vis[l0] = 1;
        }

    for (int a = 1; a <= n; a++)
    {
        int ans = 0;
        for (int l0 = 0; l0 <= n; l0++)
            if (vis[l0])
                ans = std::max(ans, a * l0 + f[l0]);
        printf("%d ", ans);
    }
}

int main()
{
    for (int T = read(); T--; solve(), putchar('\n'))
        ;
    return 0;
}