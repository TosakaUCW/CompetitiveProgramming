#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 200;
const int prime[46] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                       29, 31, 37, 41, 43, 47, 53, 59, 61,
                       67, 71, 73, 79, 83, 89, 97, 101, 103,
                       107, 109, 113, 127, 131, 137, 139, 149,
                       151, 157, 163, 167, 173, 179, 181, 191,
                       193, 197, 199};
int n, f[N + 5];

int main()
{
    f[0] = 1;
    Rep(i, 0, 45)
        Rep(j, prime[i], N)
            f[j] += f[j - prime[i]];
    while (~scanf("%d", &n))
        printf("%d\n", f[n]);
    return 0;
}