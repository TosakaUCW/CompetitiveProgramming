#include <stdio.h>
#include <iostream>
#include <string>

int n, m;
std::string s, t;

int main()
{
    std::cin >> s >> t;
    n = s.length();
    m = t.length();
    if (n != m)
    {
        puts("No");
        return 0;
    }
    for (int i = 0; i < n; i++)
        if ((s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') and !(t[i] == 'a' or t[i] == 'e' or t[i] == 'i' or t[i] == 'o' or t[i] == 'u'))
        {
            puts("No");
            return 0;
        }
        else if (!(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') and (t[i] == 'a' or t[i] == 'e' or t[i] == 'i' or t[i] == 'o' or t[i] == 'u'))
        {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}