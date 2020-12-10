#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e3 + 5;

int n, m, k;
int a[N], b[N], c[N];
int last[N], ans, sum;
std::vector<int> P[N];
std::priority_queue<int> Q;

int main()
{
    n = read(), m = read(), sum = k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read(), c[i] = read(), last[i] = i;
    for (int u, v; m--;)
        u = read(), v = read(), last[v] = std::max(last[v], u);
    for (int i = 1; i <= n; i++)
        P[last[i]].push_back(c[i]);
    for (int i = 0; i <= n; i++)
    {
        sum += b[i];
        for (auto v : P[i])
            sum--, Q.push(-v);
        while (!Q.empty() and sum < a[i + 1])
            sum++, Q.pop();
        if (sum < a[i + 1])
            return puts("-1"), 0;
    }
    while (!Q.empty())
        ans += -Q.top(), Q.pop();
    return printf("%d", ans), 0;
}