#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, len, cnt;
int a[N], pre[N], suf[N], pos[N];
bool flag;

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        pre[i] = a[i] > a[i - 1] ? pre[i - 1] + 1 : 1;
    for (int i = n; i >= 1; i--)
        suf[i] = a[i] > a[i + 1] ? suf[i + 1] + 1 : 1;
    for (int i = 1; i <= n; i++)
        len = std::max(len, std::max(pre[i], suf[i]));
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == len)
            ++cnt;
        if (suf[i] == len)
            ++cnt;
        if (i + len - 1 <= n and i - len + 1 >= 1 and suf[i] == len and pre[i] == len)
            flag = true;
    }
    if (cnt == 2 and flag)
        printf("%d", len & 1);
    else
        puts("0");
    return 0;
}