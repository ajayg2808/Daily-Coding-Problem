#include <stdio.h>
#include <stdlib.h>

typedef int (*f_ptr)(int a, int b);
typedef int (*pair_ptr)(f_ptr);

static int pairA, pairB;

pair_ptr cons(int a, int b)
{
    pairA = a;
    pairB = b;

    int pair(f_ptr f)
    {
        return (f)(pairA, pairB);
    }
    return pair;
}

int car(pair_ptr fun)
{
    int f(int a, int b)
    {
        return a;
    }
    return fun(f);
}

int cdr(pair_ptr fun)
{
    int f(int a, int b)
    {
        return b;
    }
    return fun(f);
}

int main()
{
    int a = 3;
    int b = 4;
    printf("\n %d", car(cons(a, b)));
    printf("\n %d", cdr(cons(a, b)));
    return 0;
}
