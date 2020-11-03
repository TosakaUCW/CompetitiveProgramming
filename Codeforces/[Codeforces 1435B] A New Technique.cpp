#include <stdio.h>
#include <algorithm>

const int N = 5e2 + 5;

int n, m;

struct Node
{
    int x, y, num;
    bool friend operator<(Node a, Node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
} a[N * N];

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
    for (int T = read(); T--;)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1, k; j <= m; j++)
                k = read(), a[k].y = j, a[k].num = k;
        for (int j = 1; j <= m; j++)
            for (int i = 1, k; i <= n; i++)
                k = read(), a[k].x = i;
        std::sort(a + 1, a + 1 + n * m);
        for (int k = 1; k <= n * m; k++)
        {
            printf("%d ", a[k].num);
            if (k % m == 0)
                puts("");
        }
    }
    return 0;
}
