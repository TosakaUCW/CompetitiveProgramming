#include <math.h>
#include <stdio.h>

typedef long long ll;

int n;

int prime(int x)
{
    bool f = true;
    for (int i = 2, k = int(sqrt(x)); i <= k; i++)
        if (x % i == 0)
            f = false;
    return f;
}

int main()
{
    scanf("%d", &n);
    int tmp = n;
    if (prime(n) == true)
    {
        printf("%d\n1 ", n);
        printf("%d\n", n);
        for (int i = 1; i < n; i++)
            printf("%d %d\n", i, i + 1);
        return 0;
    }
    while (n++)
    {
        if (prime(n) == false)
            continue;
        else
        {
            printf("%d\n1 ", n);
            printf("%d\n", tmp);
            for (int i = 1; i < tmp; i++)
                printf("%d %d\n", i, i + 1);
            int cnt = 1;
            for (int i = 1; i <= n - tmp; i++)
            {
                printf("%d %d\n", cnt, cnt + 2);
                if (cnt % 2 == 0)
                    cnt++, cnt++;
                cnt++;
            }
            return 0;
        }
    }
    return 0;
}
