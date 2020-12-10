#include <stdio.h>

const int P = 1e9 + 7;
long long n, k;

long long quick_pow(long long a, long long b)
{
    long long ans = 1;
    a %= P;
    while (b)
    {
        if (b & 1)
            ans = ans * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return ans;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    long long a = quick_pow(k, k - 1);
    long long b = quick_pow(n - k, n - k);
    printf("%lld", a * b % P);
    return 0;
}