#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>

#define FUCK                  \
    do                        \
    {                         \
        return puts("NE"), 0; \
    } while (0)

const int N = 1e5 + 5;

int n, cnt;
int a[N], b[N], fa[N], num[N];
std::unordered_map<std::string, int> map;

int read(int res = 0)
{
    std::string str;
    std::cin >> str;
    if (isdigit(str[0]))
        for (auto s : str)
            res = res * 10 + s - '0';
    else
    {
        if (map[str])
            res = -map[str];
        else
            res = -(map[str] = ++cnt);
    }
    return res;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("zamjena.in", "r", stdin);
    freopen("zamjena.out", "w", stdout);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1; i <= n * 2; i++)
        num[i] = -1, fa[i] = i;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    for (int i = 1; i <= n; i++)
        if (a[i] > 0 and b[i] > 0 and a[i] != b[i])
            FUCK;
        else if (a[i] > 0 and b[i] < 0)
        {
            int q = find(-b[i]);
            if (num[q] != -1 and num[q] != a[i])
                FUCK;
            else if (num[q] == -1)
                num[q] = a[i];
        }
        else if (a[i] < 0 and b[i] > 0)
        {
            int p = find(-a[i]);
            if (num[p] != -1 and num[p] != b[i])
                FUCK;
            else if (num[p] == -1)
                num[p] = b[i];
        }
        else if (a[i] < 0 and b[i] < 0)
        {
            int p = find(-a[i]), q = find(-b[i]);
            if (num[p] != -1 or num[q] != -1)
                if (num[p] != -1 and num[q] != -1)
                {
                    if (num[p] != num[q])
                        FUCK;
                }
                else
                {
                    if (num[p] != -1)
                        fa[q] = p;
                    else
                        fa[p] = q;
                }
            else
                fa[p] = q;
        }
    return puts("DA"), 0;
}