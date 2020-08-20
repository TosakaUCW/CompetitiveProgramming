#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;

int n, m;
int a[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while (m--)
        std::next_permutation(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}