#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 5e5 + 5;

int n, m, ans;
int sum[N];
std::deque<int> Q;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &sum[i]), sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++)
    {
        while (!Q.empty() and Q.front() + m < i)
            Q.pop_front();
        ans = std::max(ans, sum[i] - sum[Q.front()]);
        while (!Q.empty() and sum[Q.back()] >= sum[i])
            Q.pop_back();
        Q.push_back(i);
    }
    printf("%d", ans);
    return 0;
}