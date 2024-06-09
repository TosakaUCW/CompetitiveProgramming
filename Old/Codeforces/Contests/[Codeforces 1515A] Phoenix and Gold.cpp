#include <stdio.h>
#include <algorithm>

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

int n, x, sum;
int a[N];

void solve()
{
    n = read(), x = read(), sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (a[i] = read());
    std::sort(a + 1, a + 1 + n);
    if (sum == x)
        return puts("NO"), void();
    puts("YES");
    std::sort(a + 1, a + 1 + n, [](int a, int b) { return a > b; });
    for (int i = 1, tot = 0; i <= n; i++)
    {
        if (tot + a[i] == x)
            std::swap(a[i], a[i + 1]);
        tot += a[i];
        printf("%d ", a[i]);
    }
    puts("");
}

int main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
