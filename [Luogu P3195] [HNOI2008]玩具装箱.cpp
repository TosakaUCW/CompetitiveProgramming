#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, L;
int Q[N], head = 1, tail;
double A[N], B[N], sum[N], dp[N];

double X(int x) { return B[x]; }

double Y(int x) { return dp[x] + B[x] * B[x]; }

double slope(int a, int b) { return (Y(a) - Y(b)) / (X(a) - X(b)); }

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

int main()
{
    n = read(), L = read();
    for (int i = 1; i <= n; i++)
        sum[i] = read() + sum[i - 1], A[i] = sum[i] + i, B[i] = sum[i] + i + L + 1;
    B[0] = L + 1, Q[++tail] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head < tail and slope(Q[head], Q[head + 1]) < 2 * A[i])
            ++head;
        int j = Q[head];
        dp[i] = dp[j] + (A[i] - B[j]) * (A[i] - B[j]);
        while (head < tail and slope(i, Q[tail - 1]) < slope(Q[tail - 1], Q[tail]))
            --tail;
        Q[++tail] = i;
    }
    return printf("%lld", (long long)dp[n]), 0;
}