#include <stdio.h>
#include <iostream>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

int n, ans;
std::string str;
__gnu_pbds::cc_hash_table<std::string, bool> hash;

int main()
{
    scanf("%d", &n);
    ans = n;
    Rep(i, 1, n)
    {
        std::cin >> str;
        if (hash[str])
            ans--;
        else
            hash[str] = true;
    }
    printf("%d", ans);
    return 0;
}