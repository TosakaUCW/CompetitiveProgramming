#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

const int N = 1e4 + 5;

int n, m, f[N];
std::vector<int> a[N];

int main()
{
    memset(f, -0x3f, sizeof f);
    f[1] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i].size() == 0)
            f[i + 1] = std::max(f[i] + 1, f[i + 1]);
        else
            for (int j = 0; j < a[i].size(); j++)
                f[i + a[i][j]] = std::max(f[i + a[i][j]], f[i]);
    }
    printf("%d", f[n + 1]);
    return 0;
}