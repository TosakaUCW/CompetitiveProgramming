#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
int n, a[N], b[N], s[N], t[N], nxt[N];

void get_next()
{
    nxt[0] = -1;
    for (int now = -1, i = 0; i < n; )
        if (now == -1 or t[i] == t[now])
            nxt[++i] = ++now;
        else
            now = nxt[now];
}
void search()
{
    for (int i = 0, j = 0; i < 2 * n; )
    {
        if (j == -1 or s[i] == t[j]) i++, j++;
        else j = nxt[j];
        if (j == n)
        {
            printf("possible"), exit(0);
            j = nxt[j];
        }
    }
}

int main()
{
    n = read();
    for (int i = 0; i < n; i++) a[i] = read();
    for (int i = 0; i < n; i++) b[i] = read();
    std::sort(a, a + n), std::sort(b, b + n);
    for (int i = 0; i < n; i++) s[i] = i == n - 1 ? (360000 - a[n - 1] + a[0]) : a[i + 1] - a[i];
    for (int i = 0; i < n; i++) t[i] = i == n - 1 ? (360000 - b[n - 1] + b[0]) : b[i + 1] - b[i];
    for (int i = 0; i < n; i++) s[i + n] = s[i];
    // for (int i = 0; i < 2 * n; i++) printf("%d ", s[i]);
    // puts("");
    // for (int i = 0; i < 2 * n; i++) printf("%d ", t[i]);
    // puts("");
    get_next(), search(), printf("impossible");
    return 0;
}