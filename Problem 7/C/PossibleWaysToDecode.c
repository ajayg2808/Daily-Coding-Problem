#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substr(const char *src, int m, int n)
{
    int i, len = n - m;

    char *dest = (char *)malloc(sizeof(char) * (len + 1));

    for (i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }

    *dest = '\0';

    return dest - len;
}
int isAlphabet(int num)
{
    if (num > 26 || num < 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int getWaysToDecodeCount(char *code)
{
    int count = 0;
    int l = strlen(code);
    char *sub;
    if (l == 0)
        return 0;
    if (l == 1)
    {
        if (isAlphabet(atoi(code)))
        {
            count = 1;
        }
    }
    else if (l == 2)
    {
        if (code[0] != '0')
        {
            count = 1 + isAlphabet(atoi(code));
        }
    }
    else
    {
        sub = substr(code, 1, l);
        count = getWaysToDecodeCount(sub);
        free(sub);
        sub = substr(code, 0, 2);
        if (isAlphabet(atoi(sub)))
        {
            free(sub);
            sub = substr(code, 2, l);
            count += getWaysToDecodeCount(sub);
        }
        free(sub);
    }

    return count;
}

int main()
{
    char code[100];
    int result = 0;
    printf("\n Enter encoded message string : ");
    scanf("%s", &code);

    result = getWaysToDecodeCount(code);

    printf("\n Possible way to decode message : %d", result);
    return 0;
}
