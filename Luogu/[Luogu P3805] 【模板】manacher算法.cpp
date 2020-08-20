#include <stdio.h>
#include <algorithm>
#include <string.h>

const int N = 1e8 + 5;

int n, ans, p[N];
char str[N], s[N];

void Manacher()
{
    str[0] = str[1] = '#';
    for (int i = 1; i <= n; i++)
        str[2 * i] = s[i - 1], str[2 * i + 1] = '#';
    n = 2 * n + 2;
    int id = 1, mx = 1;
    p[1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (i < mx)
            p[i] = std::min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        while (str[i - p[i]] == str[i + p[i]])
            p[i]++;
        if (mx < i + p[i])
            mx = i + p[i], id = i;
    }
}

int main()
{
    scanf("%s", s);
    n = strlen(s);
    Manacher();
    for (int i = 2; i < n; i++)
        ans = std::max(ans, p[i] - 1);
    printf("%d", ans);
    return 0;
}