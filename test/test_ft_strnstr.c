#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_strnstr_erro_little_empty(void)
{
	const char	*big = "Meu lindo dia";
	char		*little;

	little = "";
	TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, little, strlen(big)));
}

void	test_ft_strnstr_erro(void)
{
	const char	*big = "Meu lindo dia";
	char		*little = "lindo";

	TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, little, strlen(big)));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strnstr_erro_little_empty);
	RUN_TEST(test_ft_strnstr_erro);
	return (UNITY_END());
}
