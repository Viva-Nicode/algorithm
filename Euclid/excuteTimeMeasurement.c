#include <time.h>
#include <stdio.h>
#include "./Euclid_Algorithm.h"

#define OUTER_ITERATIONS_NUMBER 100
#define INNER_ITERATIONS_NUMBER 9999999
#define LARGE_PARAM 12345
#define SMALL_PARAM 6789

// 재귀 호출 실행 시간 반환
volatile double RecursiveTime()
{
    clock_t start = clock();

    for (volatile int i = 0; i < INNER_ITERATIONS_NUMBER; i++)
        Euclidean_Algorithm_Using_RecursiveCall(LARGE_PARAM, SMALL_PARAM);

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    return elapsed_time;
}

// 반복 호출 실행 시간 반환
volatile double iterationTime()
{
    clock_t start = clock();

    for (volatile int i = 0; i < INNER_ITERATIONS_NUMBER; i++)
        Euclidean_Algorithm_Using_Roop(LARGE_PARAM, SMALL_PARAM);

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    return elapsed_time;
}

int main(int argc, char const *argv[])
{
    double excuteTime = 0.0;

    for (int i = 0; i < OUTER_ITERATIONS_NUMBER; i++)
        excuteTime += RecursiveTime();

    double averageRecursive = excuteTime / OUTER_ITERATIONS_NUMBER;

    excuteTime = 0.0;

    for (int i = 0; i < OUTER_ITERATIONS_NUMBER; i++)
        excuteTime += iterationTime();

    double averageIteration = excuteTime / OUTER_ITERATIONS_NUMBER;

    printf("recursive time avg : %f\n", averageRecursive);
    printf("iteration time avg : %f\n", averageIteration);

    return 0;
}
