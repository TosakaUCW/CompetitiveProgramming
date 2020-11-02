#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

const int N = 1e5 + 5;

int ans, len, cnt[N];
std::string str;

int main()
{
    std::cin >> str;
    len = str.length();
    for (int i = 0; i < len; i++)
        cnt[str[i]]++;
    for (int i = 'a'; i <= 'z'; i++)
        ans = std::max(ans, cnt[i]);
    printf("%d", ans);
    return 0;
}