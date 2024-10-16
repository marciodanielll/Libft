#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_ft_strlen_valid_strings(void)
{
	const char	*testStrings[] = {
        "Marcio Daniel",
        "1234567890",
        "A",
        "C",
		"This is a test.",
        "", 
        "Longer string with spaces.",
	    "Special characters: !@#$%^&*()"};
	const int	expectedLengths[] = {13, 10, 1, 1, 15, 0, 26, 30};
	int			numTests;
	int			i;

	numTests = sizeof(testStrings) / sizeof(testStrings[0]);
	i = 0;
	while (i < numTests)
	{
		TEST_ASSERT_EQUAL(expectedLengths[i], ft_strlen(testStrings[i]));
		i++;
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strlen_valid_strings);
	return (UNITY_END());
}
