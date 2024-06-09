#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
int n, a[N];

void solve()
{
    n = read();
    int max = 1e9 + 5, min = 0;
    std::set<int> s;
    for (int i = 1; i <= n; i++)
    {
        int opt = read(), x = read();
        if (opt == 1) min = std::max(min, x);
        else if (opt == 2) max = std::min(max, x);
        else s.insert(x);
    }
    int ans = max - min + 1;
    for (auto x : s)
        if (min <= x and x <= max)
            ans --;
    ans = std::max(ans, 0);
    printf("%d\n", ans);
}

int main()
{
    // freopen("A.in", "r", stdin);
    for (int T = read(); T--; solve());
    return 0;
}