#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// helper functions
int indexOf(char* str, char c);

// algorithms
bool checkBrace(char* str, char o, char c);
bool recursiveCheckBraces(char* str, char* o, char* c);

//==<<Checking single type of braces>>==//

/* Time:    O(n)
 * Memory:  O(1)
 */
bool checkBrace(char *str, char o, char c)
{
    int i = 0;

    for (; *str; str++)
    {
        i += (*str == o) - (*str == c);

        if (i < 0)
            return false;
    }

    return i == 0;
}

//==<<Checking multiple types of braces recursively>>==//

int _recursiveCheckBraces(char* str, char* o, char* c, int* ci);

/* Time:    O(n)
 * Memory:  O(1)
 * TCO:     no
 */
// wrapper for _recursiveCheckBraces
bool recursiveCheckBraces(char* str, char* o, char* c)
{
    int ci;
    return _recursiveCheckBraces(str, o, c, &ci) == -1;
}

int _recursiveCheckBraces(char *str, char *o, char *c, int* ci)
{
    int pos = -1;
    int i;

    for (i = 0; str[i]; i++)
    {
        if ((*ci = indexOf(c, str[i])) >= 0)
            return i;
        
        if ((pos = indexOf(o, str[i])) == -1)
            continue;

        int adv = _recursiveCheckBraces(str + i + 1, o, c, ci);

        if (adv < 0)
            return -2;

        if (*ci != pos)
            return -2;

        i += adv + 1;
    }

    return -1;
}

//==<<Testing and implementation of helper functions>>==//

int main()
{
    const int len = 4;
    char* s[] = { "hklasd(f[d] {sa}ú)" ,"fads)lk(jh" ,"fdaskjh(afsd" ,"falkjha(fdah{adf)adsf}fda" };

    for (int i = 0; i < len; i++)
    {
        //bool res = checkBrace(s[i], '(', ')');
        bool res = recursiveCheckBraces(s[i], "([{", ")]}");
        printf("%hhu\n", res);
    }

    return EXIT_SUCCESS;
}

int indexOf(char* str, char c)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == c)
            return i;
    }

    return -1;
}