#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>

const int N = 5e3 + 5;

int n, ans_k, ans = 2147483647;
int c[N], a[N];

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        std::cin >> ch;
        a[i] = ch == 'F';
    }
    for (int k = 1; k <= n; k++)
    {
        memset(c, 0, sizeof c);
        bool flag = 1;
        int tot = 0, now = 0;
        for (int i = 1; i <= n; i++)
        {
            now ^= c[i];
            if (a[i] ^ now == 0)
            {
                if (i + k - 1 > n)
                {
                    flag = false;
                    break;
                }
                tot++;
                now ^= 1, c[i + k] ^= 1;
            }
        }
        if (flag)
            if (tot < ans)
                ans = tot, ans_k = k;
    }
    printf("%d %d", ans_k, ans);
    return 0;
}