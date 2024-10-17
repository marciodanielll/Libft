#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft__strlcpy_success(void)
{
	const char	*src[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank",
			"Grace", "Hannah", "Isaac", "Jack"};
	char		dst[10];
	size_t		count_src;
	size_t		result;

	count_src = sizeof(src) / sizeof(src[0]);
	while (count_src--)
	{
		memset(dst, 'o', sizeof(dst) - 1);
		dst[9] = '\0';
		result = ft_strlcpy(dst, src[count_src], sizeof(dst));
		TEST_ASSERT_EQUAL_STRING(src[count_src], dst);
		TEST_ASSERT_EQUAL_INT(result, strlen(src[count_src]));
	}
}

void	test_ft__strlcpy_error(void)
{
	const char	*src = "Alice";
	char		dst[2];
	size_t		result;	TEST_ASSERT_EQUAL_INT(result, strlen(src));

	memset(dst, 'o', sizeof(dst) - 1);
	dst[sizeof(dst)] = '\0';
	result = ft_strlcpy(dst, src, sizeof(dst));
	TEST_ASSERT_EQUAL_STRING("A", dst);
	TEST_ASSERT_EQUAL_INT(result, strlen(src));
}

void	test_ft__strlcpy_error_with_size_zero(void)
{
	const char	*src = "Alice";
	char		dst[1];
	size_t		result;

	dst[sizeof(dst)] = '\0';
	result = ft_strlcpy(dst, src, 0);
	TEST_ASSERT_EQUAL_STRING("", dst);
	TEST_ASSERT_EQUAL_INT(result, strlen(src));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft__strlcpy_success);
	RUN_TEST(test_ft__strlcpy_error);
	RUN_TEST(test_ft__strlcpy_error_with_size_zero);
	return (UNITY_END());
}
