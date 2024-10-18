#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_strchr_success(void)
{
	const char	*str = "Marcio Daniel";
	const char	*chars = "Marcio Daniel";
	int			count;
	int			num_chars;

	count = 0;
	num_chars = strlen(chars);
	while (count <= num_chars)
	{
		TEST_ASSERT_EQUAL_PTR(ft_strchr(str, chars[num_chars]),
			&str[num_chars]);
		count++;
	}
}

void	test_ft_strchr_error(void)
{
	const char	*str = "Marcio Daniel";
	int			count;
	int			num_chars;

	count = 0;
	while (count <= num_chars)
		while (num_chars--)
		{
			TEST_ASSERT_EQUAL_PTR(NULL, ft_strchr(str, 'z'));
			count++;
		}
}

void	test_ft_strchr_find_null_terminator(void)
{
	const char	*str = "Marcio Daniel";
	char		*result;

	result = ft_strchr(str, '\0');
	TEST_ASSERT_EQUAL_PTR(&str[strlen(str)], result);
}

void	test_ft_strchr_only_null_terminator(void)
{
	char	*result;

	const char *str = ""; 
	result = ft_strchr(str, '\0');
	TEST_ASSERT_EQUAL_PTR(str, result);
}

void	test_ft_strchr_with_large_value(void)
{
	char	*result;

	const char *str = "teste";
	int large_value = 1024;

	result = ft_strchr(str, large_value);
	TEST_ASSERT_EQUAL_PTR(str + 5, result);
}


int	main(void)
{
	UNITY_BEGIN();
/* 	RUN_TEST(test_ft_strchr_success);
	RUN_TEST(test_ft_strchr_error);
	RUN_TEST(test_ft_strchr_find_null_terminator);
	RUN_TEST(test_ft_strchr_only_null_terminator); */
	RUN_TEST(test_ft_strchr_with_large_value);
	return (UNITY_END());
}
