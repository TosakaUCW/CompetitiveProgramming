#include <stdio.h>

const int N = 1e5 + 5;

int n, k;
char str[N];

int main()
{
    scanf("%d%d%s", &n, &k, &str);
    for (int i = 0; i < n and k; i++)
    {
        if (str[i] == '4' and str[i + 1] == '7' and str[i + 2] == '7' and !(i & 1))
            k = k % 2;
        if (k and str[i] == '4' and str[i + 1] == '7')
        {
            if (i & 1)
                str[i] = str[i + 1];
            else
                str[i + 1] = str[i];
            i -= 2;
            k--;
        }
    }
    printf("%s", str);
    return 0;
}