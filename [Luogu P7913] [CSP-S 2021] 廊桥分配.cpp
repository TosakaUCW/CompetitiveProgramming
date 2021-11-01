#include <stdio.h>
#include <algorithm>
#include <set>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int n, m1, m2;
int a1[N], b1[N], a2[N], b2[N];
int ans, f1[N], f2[N];
std::set<std::pair<int, int>> S;

void solve(int m, int a[], int b[], int f[])
{
#define ins insert
    S.clear();
    for (int i = 1; i <= m; i++)
        S.ins({a[i], b[i]});
    for (int i = 1; i <= n; i++)
    {
        for (int cur = 0; 1;)
        {
            auto it = S.upper_bound({cur, 0});
            if (it == S.end())
                break;
            cur = it->second, S.erase(it);
            f[i]++;
        }
        f[i] += f[i - 1];
    }
}

int main()
{
    n = read(), m1 = read(), m2 = read();
    for (int i = 1; i <= m1; i++)
        a1[i] = read(), b1[i] = read();
    for (int i = 1; i <= m2; i++)
        a2[i] = read(), b2[i] = read();
    solve(m1, a1, b1, f1), solve(m2, a2, b2, f2);
    for (int i = 0; i <= n; i++)
        ans = std::max(ans, f1[i] + f2[n - i]);
    printf("%d", ans);
    return 0;
}
