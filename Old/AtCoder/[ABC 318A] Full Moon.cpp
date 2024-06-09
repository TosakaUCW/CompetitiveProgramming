#include <stdio.h>
#include <algorithm>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

int main()
{
    int n = read(), m = read(), p = read();
    if (n < m)
        return puts("0"), 0;
    printf("%d\n", (n - m) / p + 1);
    return 0;
}