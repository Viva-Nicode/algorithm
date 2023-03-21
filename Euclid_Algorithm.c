#include <stdio.h>

int Euclid(int a, int b)
{
    printf("(%d, %d)\n", a, b);
    if (b <= 0)
        return a;
    return Euclid(b, a % b);
}

void assertInt(int (*fp)(int, int), int a, int b, int expectation)
{
    if (fp(a, b) == expectation)
        printf("suc");
    else
        printf("fail");
}

int main(int argc, char const *argv[])
{
    assertInt(Euclid, 24, 14, 2);
    return 0;
}