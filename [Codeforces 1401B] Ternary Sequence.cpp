#include <stdio.h>
#include <algorithm>

int A[3], B[3];

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

signed main()
{
    for (int T = read(); T--;)
    {
        for (int i = 0; i < 3; i++)
            A[i] = read();
        for (int i = 0; i < 3; i++)
            B[i] = read();
        int tmp = std::min(A[0], B[2]);
        A[0] -= tmp, B[2] -= tmp;
        tmp = std::min(A[2], B[2]);
        A[2] -= tmp, B[2] -= tmp;
        printf("%d\n", (std::min(A[2], B[1]) - std::min(A[1], B[2])) * 2);
    }
    return 0;
}