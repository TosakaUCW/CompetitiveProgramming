#include <bits/stdc++.h>

int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3000 + 5;
int n;
int a[N][N], L[N][N], R[N][N];

void solve()
{
    n = read();
    int ans = 0;
    // memset(L, 0, sizeof L);
    // memset(R, 0, sizeof R);
    for (int i = 1; i <= n; i++)
    {
        std::string str;
        std::cin >> str;
        L[i][0] = L[i][n + 1] = R[i][0] = R[i][n + 1] = 0;
        for (int j = 1; j <= n; j++)
            a[i][j] = str[j - 1] - 48,
            L[i][j] = R[i][j] = 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n + 1; j++)
        {
            sum ^= L[i][j] ^ R[i][j];
            // printf("%d ", sum);
            if (a[i][j] ^ sum and 1 <= j and j <= n)
            {
                L[i + 1][std::max(0, j - 1)] ^= 1,
                    R[i + 1][std::min(n + 1, j + 2)] ^= 1, ans++;
                // std::cout << i << ' ' << j << '\n';
            }
            L[i + 1][std::max(0, j - 1)] ^= L[i][j];
            R[i + 1][std::min(n + 1, j + 1)] ^= R[i][j];
        }

    printf("%d\n", ans);
}

int main()
{
    // freopen("tmp.in", "r", stdin);
    for (int T = read(); T; T--)
        solve();
    return 0;
}
/*
1 2
1 4
1 6
2 3
3 1
3 4
3 5
4 3
4 6
5 1
5 3
5 4
5 6
6 3
6 5
15
*/