
#include <stdio.h>

int Euclid(int a, int b)
{
    printf("(%d, %d)\n", a, b);
    if (b <= 0)
        return a;
    return Euclid(b, a % b);
}

int main(int argc, char const *argv[])
{
    printf("%d", Euclid(90, 5));
    return 0;
}

