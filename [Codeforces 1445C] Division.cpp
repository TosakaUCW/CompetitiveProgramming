#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long
#define print(x) printf("%lld\n", x)

const int N = 1e5 + 5;

int prime[N], v[N], num_prime;
bool vis[N];

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

void Euler(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[++num_prime] = i;
        for (int j = 1; j <= num_prime; j++)
        {
            if (v[i] < prime[j] or prime[j] > n / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}

signed main()
{
    Euler(1e5);
    for (int T = read(); T--;)
    {
        int a = read(), b = read(), bb = b;
        if (a % b)
            print(a);
        else
        {
            int ans = 1;
            for (int j = 1; j <= num_prime; j++)
                if (b % prime[j] == 0)
                {
                    int tmp = a;
                    while (tmp % bb == 0)
                        tmp /= prime[j];
                    ans = std::max(ans, tmp);
                    while (b % prime[j] == 0)
                        b /= prime[j];
                }
            int tmp = a;
            if (b != 1)
            {
                while (tmp % bb == 0)
                    tmp /= b;
                ans = std::max(ans, tmp);
            }
            print(ans);
        }
    }
    return 0;
}