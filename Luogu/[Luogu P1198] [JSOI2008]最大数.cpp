#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int m, P;
int k, ans;

struct Binary_Indexed_Tree
{
    int c[N];
    int lowbit(int x) { return x & (-x); }
    void modify(int x, int val)
    {
        for (int i = x; i; i -= lowbit(i))
            c[i] = std::max(c[i], val);
    }
    int query(int x)
    {
        int res = 0;
        for (int i = x; i <= k; i += lowbit(i))
            res = std::max(res, c[i]);
        return res;
    }
} BIT;

int main()
{
    scanf("%d%d\n", &m, &P);
    for (int i = 1; i <= m; i++)
    {
        char ch;
        int x;
        scanf("%c%d\n", &ch, &x);
        if (ch == 'A')
            BIT.modify(++k, (x + ans) % P);
        else
        {
            ans = BIT.query(k - x + 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}