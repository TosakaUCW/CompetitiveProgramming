#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

#define int long long
typedef unsigned long long ull;

const int N = 5e5 + 5;
const ull base = 131;

int n;
ull pow[N], sum[N];
char str[N];
std::vector<int> a;
int cnt, prime[N], max[N];
bool vis[N];

void Euler()
{
    for (int i = 2; i <= N - 5; i++)
    {
        if (!vis[i])
            prime[++cnt] = i, max[i] = i;
        for (int j = 1; j <= cnt and i * prime[j] <= N - 5; j++)
        {
            vis[i * prime[j]] = true, max[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

ull hash(int L, int R) { return sum[R] - sum[L - 1] * pow[R - L + 1]; }

signed main()
{
    n = read(), pow[0] = 1, Euler(), scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        pow[i] = pow[i - 1] * base, sum[i] = sum[i - 1] * base + str[i];
    for (int q = read(), L, R, len; q--; printf("%lld\n", len))
    {
        a.clear(), L = read(), R = read(), len = R - L + 1;
        for (int tmp = len; tmp ^ 1;)
            a.push_back(max[tmp]), tmp /= max[tmp];
        for (auto x : a)
            if (hash(L, R - len / x) == hash(L + len / x, R))
                len /= x;
    }
    return 0;
}