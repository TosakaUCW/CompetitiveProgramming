#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e3 + 5;

int n;
int a[N], b[N], ans[N];

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
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int ans_val = 0, ans_col;
        memset(b, 0, sizeof b);
        for (int j = i; j <= n; j++)
        {
            b[a[j]]++;
            if (ans_val < b[a[j]] or (ans_col > a[j] and ans_val == b[a[j]]))
                ans_val = b[a[j]], ans_col = a[j];
            ans[ans_col]++;
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}