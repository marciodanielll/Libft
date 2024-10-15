#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_ft_strncmp_equal_strings(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("test", "test", 4));
}

void	test_ft_strncmp_first_greater(void)
{
	TEST_ASSERT_TRUE(ft_strncmp("testb", "testa", 5) > 0);
}

void	test_ft_strncmp_second_greater(void)
{
	TEST_ASSERT_TRUE(ft_strncmp("testa", "testb", 5) < 0);
}

void	test_ft_strncmp_n_is_zero(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp("test", "test", 0));
}

void	test_ft_strncmp_empty_string(void)
{
	TEST_ASSERT_TRUE(ft_strncmp("", "test", 4) < 0);
	TEST_ASSERT_TRUE(ft_strncmp("test", "", 4) > 0);
}


void	test_ft_strncmp_null_string(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strncmp(NULL, NULL, 0));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strncmp_equal_strings);
	RUN_TEST(test_ft_strncmp_first_greater);
	RUN_TEST(test_ft_strncmp_second_greater);
	RUN_TEST(test_ft_strncmp_n_is_zero);
	RUN_TEST(test_ft_strncmp_empty_string);
	RUN_TEST(test_ft_strncmp_null_string);
	return (UNITY_END());
}
