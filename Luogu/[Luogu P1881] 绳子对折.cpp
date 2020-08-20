#include <stdio.h>
#include <algorithm>

const int N = 1e2 + 5;
const int L = 2e4 + 5;

int n, len, ans;
bool point[L];

int main()
{
    scanf("%d%d", &n, &len);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        point[tmp * 2] = true;
    }
    for (int i = 1; i < 2 * len; i++)
    {
        bool flag = true;
        for (int k = 0; i - k >= 0 and i + k <= 2 * len; k++)
            if (point[i - k] != point[i + k])
            {
                flag = false;
                break;
            }
        if (flag)
            ans++;
    }
    printf("%d", ans);
    return 0;
}