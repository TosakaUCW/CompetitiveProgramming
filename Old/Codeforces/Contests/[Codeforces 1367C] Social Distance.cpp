#include <stdio.h>
#include <string>
#include <iostream>

int T, n, k;
std::string str;

int main()
{
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        str.clear();
        std::cin >> str;
        int ans = 0;
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n and str[j] != '1')
                j++;
            int left = str[i] == '1' ? k : 0;
            int right = str[j] == '1' and j < n ? k : 0;
            int len = j - i;
            if (left == k)
                len--;
            len -= left + right;
            if (len > 0)
                ans += (len + k) / (k + 1);
            //0 0 0 0 0 0 0 0 0 0
            //0 1 2 3 4 5 6 7 8 9
            //0 10
            i = j;
        }
        printf("%d\n", ans);
    }
}