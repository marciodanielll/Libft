#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_strrchr_success(void)
{
	const char	*str = "Marcio Daniel";
	int			num_chars;

	num_chars = strlen(str);
	while (num_chars)
	{
		printf("%d\n", str[num_chars]);
		TEST_ASSERT_EQUAL_PTR(ft_strrchr(str, str[num_chars]), strrchr(str,
				str[num_chars]));
		num_chars--;
	}
}

void	test_ft_strrchr_error(void)
{
	const char	*str = "Marcio Daniel";

	TEST_ASSERT_EQUAL_PTR(NULL, ft_strrchr(str, 'z'));
}

void	test_ft_strrchr_find_null_terminator(void)
{
	const char	*str = "Marcio Daniel";
	char		*result;

	result = ft_strrchr(str, '\0');
	TEST_ASSERT_EQUAL_PTR(&str[strlen(str)], result);
}

void	test_ft_strrchr_only_null_terminator(void)
{
	const char	*str = "";
	char		*result;

	result = ft_strrchr(str, '\0');
	TEST_ASSERT_EQUAL_PTR(str, result);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strrchr_success);
	RUN_TEST(test_ft_strrchr_error);
	RUN_TEST(test_ft_strrchr_find_null_terminator);
	RUN_TEST(test_ft_strrchr_only_null_terminator);
	return (UNITY_END());
}
