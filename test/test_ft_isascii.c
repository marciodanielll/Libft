#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_isascii_valid_digits(void)
{
	int	start;

	start = 0;
	while (start <= 127)
	{
		TEST_ASSERT_TRUE(ft_isascii(start));
		start++;
	}
}

void	test_ft_isascii_valid_invalids(void)
{
	TEST_ASSERT_FALSE(ft_isascii(-1));
	TEST_ASSERT_FALSE(ft_isascii(128));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isascii_valid_digits);
	RUN_TEST(test_ft_isascii_valid_invalids);
	return (UNITY_END());
}
