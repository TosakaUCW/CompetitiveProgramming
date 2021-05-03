#include <stdio.h>
#include <algorithm>
#include <math.h>

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n;

void solve()
{
    n = read();
    if (n % 2 == 0)
    {
        int x = n / 2, y = sqrt(x);
        if (y * y == x)
            return puts("YES"), void();
    }
    if (n % 4 == 0)
    {
        int x = n / 4, y = sqrt(x);
        if (y * y == x)
            return puts("YES"), void();
    }
    puts("NO");
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
