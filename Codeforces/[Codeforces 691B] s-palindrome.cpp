#include <stdio.h>
#include <string.h>

const int S = 1e3 + 5;

char f[255], s[S];

int main()
{
    f['A'] = 'A', f['H'] = 'H', f['I'] = 'I', f['M'] = 'M', f['O'] = 'O', f['T'] = 'T', f['U'] = 'U', f['V'] = 'V', f['W'] = 'W';
    f['X'] = 'X', f['Y'] = 'Y', f['b'] = 'd', f['d'] = 'b', f['o'] = 'o', f['p'] = 'q', f['q'] = 'p', f['v'] = 'v', f['w'] = 'w', f['x'] = 'x';
    scanf("%s", s);
    for (int i = 0, j = strlen(s) - 1; i <= j; ++i, --j)
        if (f[s[i]] != s[j])
        {
            puts("NIE");
            return 0;
        }
    puts("TAK");
    return 0;
}