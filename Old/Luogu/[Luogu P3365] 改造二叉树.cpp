#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, ans = 1;
int a[N], b[N], c[N];
int son[2][N];

int read(int x = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return x;
}

void dfs(const int &u)
{
    if (son[0][u])
        dfs(son[0][u]);
    b[++b[0]] = a[u] - b[0];
    if (son[1][u])
        dfs(son[1][u]);
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 2, fa; i <= n; i++)
        fa = read(), son[read()][fa] = i;
    dfs(1), c[1] = b[1];
    for (int i = 2; i <= n; i++)
        if (c[ans] < b[i])
            c[++ans] = b[i];
        else
        {
            int res;
            for (int L = 1, R = ans, mid; L <= R;)
                if (c[mid = (L + R) / 2] >= b[i])
                    res = mid, R = mid - 1;
                else
                    L = mid + 1;
            c[res] = b[i];
        }
    return printf("%d", n - ans), 0;
}