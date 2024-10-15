#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_ft_strlcpy_valid_strings(void)
{
	const char	*testStrings[] = {"Marcio Daniel", "1234567890", "A", "C",
			"This is a test.", "", "Longer string with spaces.",
			"Special characters: !@#$%^&*()"};
	char		dest[100];
	size_t		expectedLengths[] = {13, 10, 1, 1, 15, 0, 26, 30};
	int			numTests;
	int			i;
	size_t		result;

	numTests = sizeof(testStrings) / sizeof(testStrings[0]);
	i = 0;
	while (i < numTests)
	{
		memset(dest, 0, sizeof(dest));
		result = ft_strlcpy(dest, testStrings[i], sizeof(dest));
		TEST_ASSERT_EQUAL_STRING(testStrings[i], dest);
		TEST_ASSERT_EQUAL(expectedLengths[i], result);
		i++;
	}
}

void	test_ft_strcpy_null_source(void)
{
	char	dest[100];
	size_t	result;

	memset(dest, 0, sizeof(dest));
	result = ft_strlcpy(dest, NULL, sizeof(dest));
	TEST_ASSERT_EQUAL(0, result);
	TEST_ASSERT_EQUAL_STRING("", dest);
}

void	test_ft_strcpy_null_destination(void)
{
	size_t	result;

	result = ft_strlcpy(NULL, "Test", 0);
	TEST_ASSERT_EQUAL(4, result);
}

void	test_ft_strcpy_empty_string(void)
{
	char	dest[100];

	memset(dest, 0, sizeof(dest));
	ft_strlcpy(dest, "", sizeof(dest));
	TEST_ASSERT_EQUAL_STRING("", dest);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strlcpy_valid_strings);
	RUN_TEST(test_ft_strcpy_null_source);
	RUN_TEST(test_ft_strcpy_null_destination);
	RUN_TEST(test_ft_strcpy_empty_string);
	return (UNITY_END());
}