#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_strnstr_substring_found_within_limit(void)
{
	const char	*big = "Hello World";
	const char	*little = "World";

	TEST_ASSERT_EQUAL_PTR(&big[6], ft_strnstr(big, little, 12));
}

void	test_strnstr_substring_not_found_within_limit(void)
{
	const char	*big = "Hello World";
	const char	*little = "Planet";

	TEST_ASSERT_NULL(ft_strnstr(big, little, 11));
}

void	test_strnstr_empty_substring(void)
{
	const char	*big = "Hello World";

	TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, "", 11));
	TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, "", 0));
}

void	test_strnstr_empty_haystack(void)
{
	const char	*little = "World";

	TEST_ASSERT_NULL(ft_strnstr("", little, 11));
}

void	test_strnstr_substring_found_at_start(void)
{
	const char	*big = "Hello World";
	const char	*little = "Hello";

	TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, little, 5));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_strnstr_substring_found_within_limit);
    RUN_TEST(test_strnstr_substring_not_found_within_limit);
	RUN_TEST(test_strnstr_empty_substring);
	RUN_TEST(test_strnstr_empty_haystack);
	RUN_TEST(test_strnstr_substring_found_at_start);
	return (UNITY_END());
}
