#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

std::vector<int> go(int x)
{
    std::vector<int> res;
    if (x == 2) res.push_back(0);
    else if (x & 1)
        res = go(x - 1),
        res.push_back(*std::min_element(res.begin(), res.end()) - 1);
    else
        res = go(x / 2),
        res.push_back(*std::max_element(res.begin(), res.end()) + 1);
    return res;
}

void solve()
{
    auto ans = go(read());
    std::cout << ans.size() << '\n';
    for (auto x : ans) std::cout << x << ' ';
    puts("");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}