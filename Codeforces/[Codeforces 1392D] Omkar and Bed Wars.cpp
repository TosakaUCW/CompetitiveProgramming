#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>
#include <math.h>

const int N = 4e5 + 5;

int n;
int a[N];
std::string str;

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
        memset(a, 0, sizeof a);
        str.clear();
        std::cin >> n >> str;
        for (int i = 0; i < n; i++)
            a[i + 1] = str[i];
        bool flag = false;
        for (int i = 1; i <= n; i++)
            if (i != 1 and a[i] != a[i - 1])
            {
                flag = true;
                break;
            }
        if (!flag)
            printf("%d\n", int(ceil(1.0 * n / 3)));
        else
        {
            int cnt = 0, ans = 0;
            int p, q;
            for (p = 1; a[p] == a[n]; p++)
                ;
            for (q = n; a[q] == a[1]; q--)
                ;
            ans += (n - q - 1 + p) / 3;
            cnt = 0;
            for (int i = p; i <= q; i++)
                if (a[i] != a[i - 1])
                    ans += cnt / 3, cnt = 1;
                else
                    cnt++;
            ans += cnt / 3;
            printf("%d\n", ans);
        }
    }
    return 0;
}