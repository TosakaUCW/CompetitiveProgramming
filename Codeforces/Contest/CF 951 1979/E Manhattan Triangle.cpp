#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5;
const int M = 2e5 + 5;

std::set<pii> s[M << 1];
void solve()
{
    int n = read(), d = read();
    vector<pii> a(n);
    std::map<std::pair<int, int>, int> map;
    
    for (int i = 1; i <= n; i++)
    {
        int x = read(), y = read();
        a[i - 1] = {x, y};
        map[{x, y}] = i;
        s[y - x + N].insert({x + y, i});
    }
    bool flag = 0;
    for (auto [x1, y1] : a)
    {
        int x2 = x1 - d / 2, y2 = y1 - d / 2;
        if (flag) break; 
        if (map.find({x2, y2}) != map.end())
        {
            int b = y1 - x1 + N;
            if (b + d <= 4e5)
            {
                auto it = s[b + d].lower_bound({x2 + y2, 0});
                if (it != s[b + d].end() and it->first <= x1 + y1)
                {
                    flag = 1;
                    printf("%d %d %d\n", map[{x1, y1}], map[{x2, y2}], it -> second);
                    break;
                }
            }
            if (b - d >= 0)
            {
                auto it = s[b - d].lower_bound({x2 + y2, 0});
                if (it != s[b - d].end() and it->first <= x1 + y1)
                {
                    flag = 1;
                    printf("%d %d %d\n", map[{x1, y1}], map[{x2, y2}], it -> second);
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        auto [x, y] = a[i - 1];
        s[y - x + N].erase({x + y, i});
    }
    for (int i = 1; i <= n; i++)
    {
        auto [x, y] = a[i - 1];
        s[y + x + N].insert({y - x, i});
    }
    
    for (auto [x1, y1] : a)
    {
        int x2 = x1 - d / 2, y2 = y1 + d / 2;
        if (flag) break;
        if (map.find({x2, y2}) != map.end())
        {
            int b = y1 + x1 + N;
            if (b + d <= 4e5)
            {
                auto it = s[b + d].lower_bound({y1 - x1, 0});
                if (it != s[b + d].end() and it->first <= y2 - x2)
                {
                    flag = 1;
                    printf("%d %d %d\n", map[{x1, y1}], map[{x2, y2}], it -> second);
                    break;
                }
            }
            if (b - d >= 0)
            {
                auto it = s[b - d].lower_bound({y1 - x1, 0});
                if (it != s[b - d].end() and it->first <= y2 - x2)
                {
                    flag = 1;
                    printf("%d %d %d\n", map[{x1, y1}], map[{x2, y2}], it -> second);
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        auto [x, y] = a[i - 1];
        s[y + x + N].erase({y - x, i});
    }
    
    if (!flag) puts("0 0 0");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}