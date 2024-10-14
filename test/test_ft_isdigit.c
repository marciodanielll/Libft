#include "../src/libft.h"
#include "../unity/unity.h"


void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_isdigit_valid_digits(void)
{
	char init = '0';

	while(init <= '9')
	{
		TEST_ASSERT_TRUE(ft_isdigit(init));
		init +=  1;
	}
}

void	test_ft_isdigit_invalid_chars(void)
{
	TEST_ASSERT_FALSE(ft_isdigit('a'));
	TEST_ASSERT_FALSE(ft_isdigit('-'));
	TEST_ASSERT_FALSE(ft_isdigit(' '));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isdigit_valid_digits);
	RUN_TEST(test_ft_isdigit_invalid_chars);
	return (UNITY_END());
}
