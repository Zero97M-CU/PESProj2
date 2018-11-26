#include "../inc/main.h"
#include "CUnit/Basic.h"

/*initiating suite*/
int init_suite1(void)
{
	return 0;
}

/*Cleaning suite*/
int clean_suite1(void)
{
	return 0;
}

void test_addbuff()
{
	CU_ASSERT_EQUAL(addbuff("3 5 9 3"), EXIT_SUCCESS);
	CU_ASSERT_EQUAL(addbuff(""), EXIT_SUCCESS);
}

void test_addchar()
{
	CU_ASSERT_EQUAL(addchar("2 &"), EXIT_SUCCESS);
}

void test_remchar()
{
	CU_ASSERT_EQUAL(remchar("2"), EXIT_SUCCESS);
}

void test_rembuff()
{
	CU_ASSERT_EQUAL(rembuff("3"), EXIT_SUCCESS);
}

int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "test of addbuff", test_addbuff)))
  {
		CU_cleanup_registry();
 		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite, "test of addchar", test_addchar)))
  {
    CU_cleanup_registry();
  	return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite, "test of remchar", test_remchar)))
  {
		CU_cleanup_registry();
  	return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite, "test of rembuff", test_rembuff)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
