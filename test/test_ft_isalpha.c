#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_isalpha_valid_chars(void)
{
	char alphaLower = 'a';
     char alphaUpper = 'A';
		while (alphaLower <= 'z')
	{
		TEST_ASSERT_TRUE(ft_isalpha(alphaLower));
		alphaLower += 1;
	}
	while (alphaUpper <= 'Z')
	{
		TEST_ASSERT_TRUE(ft_isalpha(alphaUpper));
		alphaUpper += 1;
	}
}

void	test_ft_isalpha_invalid_chars(void)
{
	char	invalidChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			' ', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_',
			'=', '+', '{', '}', '[', ']', ':', ';', '"', '\'', '<', '>', ',',
			'.', '?', '/', '\\', '|', '`', '~'};
	int		numInvalidChars;

	numInvalidChars = sizeof(invalidChars) / sizeof(invalidChars[0]);
	for (int i = 0; i < numInvalidChars; i++)
	{
		TEST_ASSERT_FALSE(ft_isalpha(invalidChars[i]));
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isalpha_valid_chars);
	RUN_TEST(test_ft_isalpha_invalid_chars);
	return (UNITY_END());
}
