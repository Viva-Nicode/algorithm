#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"

#include "./Euclid_Algorithm.h"

int randNum[10000][2] = {};

// 랜덤 변수 행렬 초기화
int setup_init_randnum_Matrix(void)
{
    for (int i = 0; i < 10000; i++)
    {
        randNum[i][0] = getRandNum();
        randNum[i][1] = getRandNum();
    }
    return 0;
}

// assert가 포함된 테스트 함수
void EqualResultTest()
{
    for (int i = 0; i < 10000; i++)
        CU_ASSERT_EQUAL(Euclidean_Algorithm_Using_RecursiveCall(randNum[i][0], randNum[i][1]),
                        Euclidean_Algorithm_Using_Roop(randNum[i][0], randNum[i][1]));
}

// 테스트 스위트 등록
void register_test_suite()
{
    // 아마도 스위트 객체를 반환하는 팩토리 메서드
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
