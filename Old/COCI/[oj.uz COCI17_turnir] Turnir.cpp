#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int main()
{
    freopen("turnir.in", "r", stdin), freopen("turnir.out", "w", stdout);
    int n = read();
    std::vector<int> b(1 << n);
    std::vector<std::pair<int, int>> a(1 << n);
    for (int i = 0; i < (1 << n); i++)
        a[i] = {read(), i}, b[i] = a[i].first;
    std::sort(a.begin(), a.end());
    std::unordered_map<int, int> ans;
    for (int i = 0; i < (1 << n); i++)
        ans[a[i].first] = std::max(ans[a[i].first], int(floor(log2(i + 1))));
    for (int i = 0; i < (1 << n); i++)
        printf("%d ", n - ans[b[i]]);
    return 0;
}