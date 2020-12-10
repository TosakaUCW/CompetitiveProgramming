#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e4;

int n, a[N + 5];
__gnu_pbds::cc_hash_table<int, bool> hash;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        Rep(i, 1, n)
        {
            scanf("%d", &a[i]);
            hash[a[i]] = true;
        }
        Rep(i, 1, n)
        {
            if (hash[a[i]])
            {
                hash[a[i]] = false;
                printf("%d ", a[i]);
            }
        }
        printf("\n");
        hash.clear();
    }
    return 0;
}