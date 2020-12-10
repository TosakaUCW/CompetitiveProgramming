#include <stdio.h>
#include <algorithm>

const int N = 5e5 + 5;

int n;
long long ans;

struct Binary_Indexed_Tree
{
    int c[N];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void add(int k, int x)
    {
        for (int i = k; i <= n; i += lowbit(i))
            c[i] += x;
    }
    int query(int k)
    {
        int res = 0;
        for (int i = k; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
} BIT;

struct Node
{
    int val, pos;
} a[N];

bool cmp(Node a, Node b)
{
    if (a.val != b.val)
        return a.val > b.val;
    return a.pos > b.pos;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].val), a[i].pos = i;
    std::sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans += BIT.query(a[i].pos);
        BIT.add(a[i].pos, 1);
    }
    printf("%lld", ans);
    return 0;
}