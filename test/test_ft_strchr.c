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
	size_t		length = sizeof(testString) - 1;
	size_t		i;
	char		*charPointers[length];
	char		*result;

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

void test_ft_strchr_error(void)
{
    const char *testString = "Marcio Daniel";
    char charsToTest[] = {'x', 'y', 'z', '!', '@', '1', ' '};
    size_t i = 0;
    char *result;

    while (i < sizeof(charsToTest))
    {
        result = ft_strchr(testString, charsToTest[i]);
        TEST_ASSERT_NULL(result);
        i++;
    }
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strchr_success);
	RUN_TEST(test_ft_strchr_error);
	return (UNITY_END());
}
