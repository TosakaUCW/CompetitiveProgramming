#include <stdio.h>

const int N = 100 + 5;

int n;
int a[N], b[N], sum;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sum += a[i];
    int ave = sum / 2 + 1;
    int alice = a[1], cnt = a[1], k = 1;
    b[1] = 1;
    if (cnt >= ave)
    {
        printf("1\n1");
        return 0;
    }
    for (int i = 2; i <= n; i++)
        if (a[i] <= alice / 2)
        {
            cnt += a[i], k++, b[k] = i;
            if (cnt >= ave)
                break;
        }
    if (cnt >= ave)
    {
        printf("%d\n", k);
        for (int i = 1; i <= k; i++)
            printf("%d ", b[i]);
    }
    else
        printf("0\n");
    return 0;
}