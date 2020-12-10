#include <stdio.h>

const int pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int a, b, c;

int solve(int x)
{
    int ans = 0, i = 0;
    while (x > 0)
        if (x % 10 != 0)
            ans += (x % 10) * pow[i++],
                x /= 10;
        else
            x /= 10;
    return ans;
}

int main()
{
    scanf("%d%d", &a, &b);
    c = a + b;
    a = solve(a);
    b = solve(b);
    c = solve(c);
    if (a + b == c)
        printf("YES");
    else
        printf("NO");
    return 0;
}