#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_strchr_success(void)
{
	const char	*testString = "Marcio Daniel";
	size_t		length;
	size_t		i;
	char		*charPointers[sizeof(testString) - 1];
	char		*result;

	length = sizeof(testString) - 1;
	i = 0;
	while (i < length)
	{
		charPointers[i] = (char *)&testString[i];
		i++;
	}
	i = 0;
	while (i < length)
	{
		result = ft_strchr(testString, *charPointers[i]);
		TEST_ASSERT_EQUAL(*charPointers[i], *result);
		i++;
	}
}

void	test_ft_strchr_error(void)
{
	const char	*testString = "Marcio Daniel";
	char		charsToTest[] = {'x', 'y', 'z', '!', '@', '1'};
	size_t		i;
	char		*result;

	i = 0;
	while (i < sizeof(charsToTest))
	{
		result = ft_strchr(testString, charsToTest[i]);
		TEST_ASSERT_NULL(result);
		i++;
	}
}

void	test_ft_strchr_null_pointer(void)
{
	char	*result;

	result = ft_strchr(NULL, 'x');
	TEST_ASSERT_NULL(result);
}

void	test_ft_strchr_null_character(void)
{
	const char	*testString = "Marcio Daniel";
	char		*result;

	result = ft_strchr(testString, '\0');
	TEST_ASSERT_EQUAL_PTR(result, testString + sizeof("Marcio Daniel") - 1);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strchr_success);
	RUN_TEST(test_ft_strchr_error);
	RUN_TEST(test_ft_strchr_null_pointer);
	RUN_TEST(test_ft_strchr_null_character);
	return (UNITY_END());
}
