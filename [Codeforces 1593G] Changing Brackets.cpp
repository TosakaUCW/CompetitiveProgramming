#include <stdio.h>
#include <algorithm>
#include <mem.h>
#include <vector>
#include <iostream>
#include <string>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;

int a[N];
std::string s;

void solve()
{
    std::cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1];
        if (s[i] == '(' or s[i] == ')')
            a[i] += i & 1 ? -1 : 1;
    }
    for (int q = read(), l, r; q--;)
        l = read(), r = read(), printf("%d\n", abs(a[r] - a[l - 1]));
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}