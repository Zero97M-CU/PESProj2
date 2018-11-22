/* --------------------------------------------
 * File: Unit Test
 * Authors: Mohit & Suman
 *
 * Unit testing the functionality of each functions declared in main
 * --------------------------------------------
*/

 void test_addbuff()
{
	CU_ASSERT_EQUAL(addbuff("2 78 97"),0);
	CU_ASSERT_EQUAL(addbuff("1"),1);
}

void test_addchar()
{
	CU_ASSERT_EQUAL(addchar("1 a"),0);
	CU_ASSERT_EQUAL(addchar("23 g"), 1);
}

void remchar()
{
	CU_ASSERT_EQUAL(remchar("2"),0);
	CU_aSSERT_EQUAL(remchar("23"),1);
}
