#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 50 + 5;
const int base = 1e5;
const double eps = 1e-5;

int n, L, R;
int a[N];
bool vis[N];
std::vector<int> ans;

bool check(int x)
{
    for (int p = L % x ? L - L % x + x : L; p <= R; p += x)
        if (p != *std::lower_bound(a + 1, a + 1 + n, p))
            return false;
    return true;
}

signed main()
{
    n = read(), L = read() * base, R = read() * base;
    for (int i = 1; i <= n; i++)
    {
        double x;
        scanf("%lf", &x);
        a[i] = x * base + eps;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            std::vector<int> fac;
            for (int j = 1; j * j <= a[i]; j++)
                if (a[i] % j == 0)
                    fac.push_back(j), fac.push_back(a[i] / j);
            std::sort(fac.begin(), fac.end());
            fac.resize(std::unique(fac.begin(), fac.end()) - fac.begin());
            for (auto x : fac)
                if (check(x))
                {
                    for (int j = i; j <= n; j++)
                        if (a[j] % x == 0)
                            vis[j] = true;
                    ans.push_back(x);
                    break;
                }
        }
    for (auto x : ans)
        printf("%f\n", x * 1.0 / base);
    return 0;
}