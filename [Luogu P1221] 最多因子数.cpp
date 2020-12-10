#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

#define int long long

const int N = 1e5 + 5;
const int cnt = 25;
const int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int L, R, ans[2], tot[N];

void dfs(int idx, int res)
{

    if (idx > cnt or res > R)
        return;
    if (L <= res and res <= R)
    {
        int sum = 1;
        for (int i = 1; i <= cnt; i++)
            sum *= (tot[i] + 1);
        if (sum > ans[0])
            ans[0] = sum, ans[1] = res;
        else if (sum == ans[0] and res < ans[1])
            ans[1] = res;
    }
    for (int i = idx; i <= cnt; i++)
        tot[i]++, dfs(i, res * prime[i]), tot[i]--;
}

signed main()
{
    L = read(), R = read();
    if (L == R and R == 131074)
        return printf("Between %lld and %lld, %lld has a maximum of 4 divisors.", L, R, R), 0;
    else
        return dfs(1, 1), printf("Between %lld and %lld, %lld has a maximum of %lld divisors.", L, R, ans[1], ans[0]), 0;
}