#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"

#include "./Euclid_Algorithm.h"

int randNum[10000][2] = {};

// initialization randNum Matrix
int setup_init_randnum_Matrix(void)
{
    for (int i = 0; i < 10000; i++)
    {
        randNum[i][0] = getRandNum();
        randNum[i][1] = getRandNum();
    }
    return 0;
}

// test funciton
void EqualResultTest()
{
    for (int i = 0; i < 10000; i++)
        CU_ASSERT_EQUAL(Euclidean_Algorithm_Using_RecursiveCall(randNum[i][0], randNum[i][1]),
                        Euclidean_Algorithm_Using_Roop(randNum[i][0], randNum[i][1]));
}

/* Register Test Suite*/
void register_test_suite()
{
    // Factory method for creating a suite object
    CU_pSuite suite = CU_add_suite("Euclid Test Suite", setup_init_randnum_Matrix, NULL);
    CU_add_test(suite, "test_Euclid", EqualResultTest);
}

int main()
{
    /* CUnit init */
    CU_initialize_registry();

    register_test_suite();

    /* run test */
    CU_basic_run_tests();

    /* CUnit cleanup */
    CU_cleanup_registry();

    return 0;
}
