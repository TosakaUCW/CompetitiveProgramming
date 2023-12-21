#include <stdio.h>
#include <algorithm>
#include <vector>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 4e3 + 5;
int n, ans, a[4][N];
std::vector<int> v;
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 4; j++)
            a[j][i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            v.emplace_back(a[0][i] + a[1][j]);
    std::sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x = a[2][i] + a[3][j];
            ans += std::upper_bound(v.begin(), v.end(), -x) - std::lower_bound(v.begin(), v.end(), -x);
        }
    printf("%d\n", ans);
    return 0;
}