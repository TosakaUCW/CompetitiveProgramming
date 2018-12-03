#include <math.h>
#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int n, m;

bool is_prime(int num)
{
    if (num == 2 or num == 3)
        return true;
    if (num == 1 or (num % 6 != 1 and num % 6 != 5))
        return false;
    int k = sqrt(num);
    for (int i = 5; i <= k; i += 6)
        if (num % i == 0 or num % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, m)
    {
        int num;
        scanf("%d", &num);
        if (is_prime(num))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
