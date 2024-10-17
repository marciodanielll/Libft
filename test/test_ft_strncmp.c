#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_strncmp_success_with_equal(void)
{
	int	result;

	result = ft_strncmp("Daniel", "Daniel", 6);
	TEST_ASSERT_EQUAL_INT(0, result);
	result = ft_strncmp("Danilo", "Daniel", 4);
	TEST_ASSERT_EQUAL_INT(0, result);
}


void	test_ft__ft_strncmp_success_not_equal(void)
{
	int	result;

	result = ft_strncmp("Danielo", "Daniele", 8);
	TEST_ASSERT_EQUAL_INT(10, result);
	result = ft_strncmp("Daniele", "Danielo", 8);
	TEST_ASSERT_EQUAL_INT(-10, result);
	result = ft_strncmp("Daniele", "Danielo", 0);
	TEST_ASSERT_EQUAL_INT(0, result);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strncmp_success_with_equal);
	RUN_TEST(test_ft__ft_strncmp_success_not_equal);
	return (UNITY_END());
}
