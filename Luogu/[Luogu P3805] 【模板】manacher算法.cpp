#include <stdio.h>
#include <string.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 3e7;

int n, ans, p[N + 5];
char s[N + 5], str[N + 5];

void Manacher()
{
    str[0] = str[1] = '#';
    int n = strlen(s);
    Rep(i, 1, n)
    {
        str[2 * i] = s[i - 1];
        str[2 * i + 1] = '#';
    }
    n = 2 * n + 2;
    int mid = 1, mx = 1;
    p[1] = 1;
    Rep(i, 2, n - 1)
    {
        if (i < mx)
            p[i] = std::min(p[2 * mid - i], p[mid] + mid - i);
        else
            p[i] = 1;
        while (str[i - p[i]] == str[i + p[i]])
            p[i]++;
        if (mx < i + p[i])
        {
            mx = i + p[i];
            mid = i;
        }
        if (ans < p[i])
            ans = p[i];
    }
    ans--;
}

int main()
{
    scanf("%s", s);
    Manacher();
    printf("%d", ans);
    return 0;
}