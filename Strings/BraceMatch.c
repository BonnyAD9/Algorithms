#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS
#include <stdbool.h> // bool

#include "../helpers.h" // indexOf

// algorithms
bool checkBrace(char* str, char o, char c);
bool checkBraces(char* str, char* o, char* c);


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

int _checkBraces(char* str, char* o, char* c, int* ci);

/* Time:    O(n)
 * Memory:  O(1)
 * TCO:     no
 * Depth:   same as braces depth
 */
// wrapper for _recursiveCheckBraces
bool checkBraces(char* str, char* o, char* c)
{
    int ci;
    return _checkBraces(str, o, c, &ci) == -1;
}

int _checkBraces(char *str, char *o, char *c, int* ci)
{
    int pos = -1;
    int i;

    for (i = 0; str[i]; i++)
    {
        if ((*ci = indexOf(c, str[i])) >= 0)
            return i;
        
        if ((pos = indexOf(o, str[i])) == -1)
            continue;

        int adv = _checkBraces(str + i + 1, o, c, ci);

        if (adv < 0)
            return -2;

        if (*ci != pos)
            return -2;

        i += adv + 1;
    }

    return -1;
}


//============<<Testing>>============//

int main()
{
    const int len = 4;
    char* s[] = { "hklasd(f[d] {sa}ú)" ,"fads)lk(jh" ,"fdaskjh(afsd" ,"falkjha(fdah{adf)adsf}fda" };

    for (int i = 0; i < len; i++)
    {
        //bool res = checkBrace(s[i], '(', ')');
        bool res = checkBraces(s[i], "([{", ")]}");
        printf("%hhu\n", res);
    }

    return EXIT_SUCCESS;
}