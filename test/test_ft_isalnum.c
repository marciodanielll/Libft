#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_isalnum_valid_digits(void)
{
	char	init;
	char	alphaLower;
	char	alphaUpper;

	init = '0';
	alphaLower = 'a';
	alphaUpper = 'A';
	while (init <= '9')
	{
		TEST_ASSERT_TRUE(ft_isalnum(init));
		init += 1;
	}
	while (alphaLower <= 'z')
	{
		TEST_ASSERT_TRUE(ft_isalnum(alphaLower));
		alphaLower += 1;
	}
	while (alphaUpper <= 'Z')
	{
		TEST_ASSERT_TRUE(ft_isalnum(alphaUpper));
		alphaUpper += 1;
	}
}

void	test_ft_isalnum_valid_invalids(void)
{
	char	invalidChars[] = {' ', '!', '@', '#', '$', '%', '^', '&', '*', '(',
			')', '-', '_', '=', '+', '{', '}', '[', ']', ':', ';', '"', '\'',
			'<', '>', ',', '.', '?', '/', '\\', '|', '`', '~'};

	int numInvalidChars = sizeof(invalidChars) / sizeof(invalidChars[0]);

	for (int i = 0; i < numInvalidChars; i++)
	{
		TEST_ASSERT_FALSE(ft_isalnum(invalidChars[i]));
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isalnum_valid_digits);
	RUN_TEST(test_ft_isalnum_valid_invalids);
	return (UNITY_END());
}
