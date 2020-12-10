#include <stdio.h>
#include <math.h>

int n;

bool isprime(int p)
{
    if (p == 1)
        return false;
    if (p == 2 || p == 3)
        return true;
    if (p % 6 != 1 && p % 6 != 5)
        return false;
    for (int i = 5; i <= sqrt(p); i += 6)
        if (p % i == 0 || p % (i + 2) == 0)
            return false;
    return true;
}

bool is_pow_2(int n)
{
    int cnt = 0;
    while (n >= 1 and n % 2 == 0)
        n /= 2, cnt++;
    return n == 1 and cnt > 1;
}

bool is_prime_2(int n)
{
    if (n % 2 != 0)
        return false;
    n /= 2;
    return isprime(n);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n == 1 or is_pow_2(n) or is_prime_2(n))
            puts("FastestFinger");
        else
            puts("Ashishgup");
    }
    return 0;
}