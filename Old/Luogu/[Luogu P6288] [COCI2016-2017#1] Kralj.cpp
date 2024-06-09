#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <set>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e5 + 5;
const int INF = 2147483647;

int n;
int ans, min = INF, pos;
int a[N], p[N], sum[N];
std::vector<int> G[N];
std::set<int> set;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), sum[a[i]]++;
    for (int i = 1; i <= n; i++)
        p[i] = read();
    for (int i = 1; i <= n; i++)
        G[a[i]].push_back(read()), sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++)
        if (sum[i] - i < min)
            min = sum[i] - i, pos = i;
    pos = pos % n + 1;
    std::set<int>::iterator it;
    for (int i = 1; i <= n; i++, pos = pos % n + 1)
    {
        for (auto j : G[pos])
            set.insert(j);
        it = set.upper_bound(p[pos]);
        if (it == set.end())
            set.erase(set.begin());
        else
            ans++, set.erase(it);
    }
    return printf("%d", ans), 0;
}