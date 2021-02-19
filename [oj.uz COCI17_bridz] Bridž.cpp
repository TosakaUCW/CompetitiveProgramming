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

int ans;

int main()
{
    for (int T = read(); T--;)
    {
        char s[13];
        scanf("%s", s);
        for (int i = 0; i < 13; i++)
            if (s[i] == 'A')
                ans += 4;
            else if (s[i] == 'K')
                ans += 3;
            else if (s[i] == 'Q')
                ans += 2;
            else if (s[i] == 'J')
                ans += 1;
    }
    return printf("%d", ans), 0;
}