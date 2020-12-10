#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 3e5 + 5;

int n, x1, x2;

struct Node
{
    int idx, val;
    bool friend operator<(Node a, Node b) { return a.val > b.val; }
} c[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int main()
{
    n = read(), x1 = read(), x2 = read();
    for (int i = 1; i <= n; i++)
        c[i].val = read(), c[i].idx = i;
    std::sort(c + 1, c + 1 + n);
    for (int i = 1; i < n; i++)
    {
        int cnt1 = i, k1 = x1 / cnt1 + (x1 % cnt1 != 0);
        if (c[i].val >= k1)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int cnt2 = j - i, k2 = x2 / cnt2 + (x2 % cnt2 != 0);
                if (c[j].val >= k2)
                {
                    printf("Yes\n%d %d\n", cnt1, cnt2);
                    for (int k = 1; k <= cnt1; k++)
                        printf("%d ", c[k].idx);
                    puts("");
                    for (int k = cnt1 + 1; k <= cnt1 + cnt2; k++)
                        printf("%d ", c[k].idx);
                    return 0;
                }
            }
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int cnt1 = i, k1 = x2 / cnt1 + (x2 % cnt1 != 0);
        if (c[i].val >= k1)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int cnt2 = j - i;
                int k2 = x1 / cnt2 + (x1 % cnt2 != 0);
                if (c[j].val >= k2)
                {
                    printf("Yes\n%d %d\n", cnt2, cnt1);
                    for (int k = cnt1 + 1; k <= cnt1 + cnt2; k++)
                        printf("%d ", c[k].idx);
                    puts("");
                    for (int k = 1; k <= cnt1; k++)
                        printf("%d ", c[k].idx);
                    return 0;
                }
            }
            break;
        }
    }
    return puts("No"), 0;
}