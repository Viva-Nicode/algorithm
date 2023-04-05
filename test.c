#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
#include "/opt/homebrew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"

/* 테스트할 함수: 두 수를 입력받아 더한 값을 반환하는 함수 */
int add(int a, int b)
{
    return a + b;
}

/* 테스트 함수: add 함수가 올바른 값을 반환하는지 확인 */
void test_add()
{
    CU_ASSERT_EQUAL(add(2, 3), 5);
    CU_ASSERT_EQUAL(add(5, 7), 12);
    CU_ASSERT_EQUAL(add(0, 0), 0);
}

/* 테스트 스위트 등록 */
void register_test_suite()
{
    CU_pSuite suite = CU_add_suite("Addition Test Suite", NULL, NULL); // 스위트 객체를 생성하는 팩터리 메서드
    CU_add_test(suite, "test_add", test_add);
}

/* main 함수: 테스트 실행 */
int main()
{
    /* CUnit 초기화 */
    CU_initialize_registry();

    /* 테스트 스위트 등록 */
    register_test_suite();

    /* 테스트 실행 */
    CU_basic_run_tests();

    /* CUnit 종료 */
    CU_cleanup_registry();

    return 0;
}
