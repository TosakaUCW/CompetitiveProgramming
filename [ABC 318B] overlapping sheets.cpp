#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e2 + 5;

int n;
int map[N][N];

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        std::cin >> x1 >> x2 >> y1 >> y2;
        for (int k = x1; k < x2; k++)
            for (int j = y1; j < y2; j++)
                map[k][j] = 1;
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            ans += map[i][j];
    printf("%d", ans);
    return 0;
}