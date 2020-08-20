#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

const int N = 2e5 + 5;

int n;
std::string str;

int go(int L, int R, int c)
{
    if (L == R)
        return str[L] != c;
    int mid = (L + R) / 2;
    int x = 0, y = 0;
    for (int i = L; i <= mid; i++)
        if (str[i] != c)
            x++;
    for (int i = mid + 1; i <= R; i++)
        if (str[i] != c)
            y++;
    x += go(mid + 1, R, c + 1);
    y += go(L, mid, c + 1);
    return std::min(x, y);
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> str;
        printf("%d\n", go(0, n - 1, 'a'));
    }
    return 0;
}