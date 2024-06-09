#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m, a[N], b[N];
std::string s[N];

void solve()
{
    n = read(), m = read(), b[0] = 0, memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++) std::cin >> s[i], s[i] = " " + s[i];
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (s[i][j - 1] == 'X' and s[i - 1][j] == 'X')
                a[j] = 1;
    for (int i = 1; i <= m; i++) b[i] = b[i - 1] + a[i];
    for (int q = read(), x, y; q--; ) x = read(), y = read(), puts(b[y] <= b[x] ? "YES" : "NO");
}

int main()
{
    solve();
    return 0;
}
