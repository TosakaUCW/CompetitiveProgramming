#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;

int n, ans;
struct Node
{
    std::string name;
    int k, m, tot, idx;
    bool friend operator<(Node a, Node b) { return a.tot != b.tot ? a.tot > b.tot : a.idx < b.idx; }
} a[N];

int main()
{
    freopen("go.in", "r", stdin), freopen("go.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].name >> a[i].k >> a[i].m;
        a[i].idx = i;
        while (a[i].k <= a[i].m)
            a[i].m -= a[i].k - 2, a[i].tot++, ans++;
    }
    std::sort(a + 1, a + 1 + n);
    return std::cout << ans << '\n'
                     << a[1].name,
           0;
}