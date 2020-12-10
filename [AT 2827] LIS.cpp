#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, ans, f[N];

struct Binary_Indexed_Tree
{
    int c[N];
    int lowbit(int x) { return x & (-x); }
    void add(int k, int x)
    {
        for (int i = k; i <= n; i += lowbit(i))
            c[i] = std::max(c[i], x);
    }
    int query(int k)
    {
        int res = 0;
        for (int i = k; i; i -= lowbit(i))
            res = std::max(res, c[i]);
        return res;
    }
} BIT;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        f[i] = BIT.query(x) + 1;
        BIT.add(x, f[i]);
    }
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, f[i]);
    printf("%d", ans);
    return 0;
}