#include <stdio.h>
#include <algorithm>
#include <unordered_map>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

#define int long long

const int N = 3e5 + 5;

int n, P, k, ans;

std::unordered_map<int, int> map;

signed main()
{
    n = read(), P = read(), k = read();
    for (int i = 1, x; i <= n; i++)
        x = read() % P, x = (x * x % P * x % P * x % P + P - k * x % P) % P,
        ans += map[x]++;
    return printf("%lld", ans), 0;
}