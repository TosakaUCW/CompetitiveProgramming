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

const int N = 5e5 + 5;

int n, d, ans;
struct Node
{
    int s, a, b;
    void in() { s = read(), a = read(), b = std::max(s, a); }
    bool friend operator<(Node a, Node b) { return a.b == b.b ? (a.s == b.s ? a.a < b.a : a.s < b.s) : a.b < b.b; }
} a[N];

#define fi first
#define se second

int main()
{
    n = read(), d = read();
    for (int i = 1; i <= n; i++)
        a[i].in();
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        if (a[i].s >= d)
            d = std::max(d, a[i].a), ans++;
    printf("%d", ans);
    return 0;
}