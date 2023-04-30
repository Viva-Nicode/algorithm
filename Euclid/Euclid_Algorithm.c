#include <stdio.h>
#include <time.h>
#include <stdlib.h>

volatile int Euclidean_Algorithm_Using_RecursiveCall(int a, int b)
{
    if (b <= 0)
        return a;
    return Euclidean_Algorithm_Using_RecursiveCall(b, a % b);
}

volatile int Euclidean_Algorithm_Using_Roop(int a, int b)
{
    int n;

    if (a < b)
        a ^= b ^= a ^= b;

    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int getRandNum()
{
    srand(time(NULL));
    return rand() % 100000 + 1;
}
