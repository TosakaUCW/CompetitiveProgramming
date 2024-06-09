#include <stdio.h>

const int a[6][3] = {{0, 1, 2}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}, {0, 2, 1}};

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d", a[n % 6][m]);
    return 0;
}