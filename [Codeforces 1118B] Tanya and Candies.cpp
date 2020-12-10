#include <stdio.h>

const int N = 2e5 + 5;

int n, ans;
int a[N];
int even[N], odd[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (i == 1)
            odd[i] = a[i];
        else if (i % 2 == 1)
            odd[i] = odd[i - 2] + a[i];
        else
            even[i] = even[i - 2] + a[i];
    }
    for (int i = 1; i <= n; i++)
        if (n % 2 == 0 and i % 2 == 1 and odd[i - 2] + even[n] - even[i - 1] == even[i - 1] + odd[n - 1] - odd[i])
            ans++;
        else if (n % 2 == 0 and i % 2 == 0 and odd[i - 1] + even[n] - even[i] == even[i - 2] + odd[n - 1] - odd[i - 1])
            ans++;
        else if (n % 2 == 1 and i % 2 == 1 and odd[i - 2] + even[n - 1] - even[i - 1] == even[i - 1] + odd[n] - odd[i])
            ans++;
        else if (n % 2 == 1 and i % 2 == 0 and odd[i - 1] + even[n - 1] - even[i] == even[i - 2] + odd[n] - odd[i - 1])
            ans++;
    printf("%d", ans);
    return 0;
}