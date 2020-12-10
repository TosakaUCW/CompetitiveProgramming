#include <stdio.h>
#include <algorithm>
#include <stack>

const int N = 3e6 + 5;

int n;
int a[N], f[N];
int S[N], top;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; S[++top] = i++)
        while (top and a[i] > a[S[top]])
            f[S[top--]] = i;
    for (int i = 1; i <= n; i++)
        printf("%d ", f[i]);
    return 0;
}