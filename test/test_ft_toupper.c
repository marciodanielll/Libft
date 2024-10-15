#include "../src/libft.h"
#include "../unity/unity.h"
#include <ctype.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_toupper_valid_characters(void)
{
	int	start;

	start = 0;
	while (start <= 127)
	{
		if (start >= 'a' && start <= 'z')
			TEST_ASSERT_EQUAL_INT(start - 32, ft_toupper(start));
		else
			TEST_ASSERT_EQUAL_INT(start, ft_toupper(start));
		start++;
	}
}

void	test_ft_toupper_out_of_range(void)
{
	int	i;
	int	invalid_values[] = {-1, 128, 255, 300};

	i = 0;
	while (i < 4)
	{
		TEST_ASSERT_EQUAL_INT(invalid_values[i], ft_toupper(invalid_values[i]));
		i++;
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_toupper_valid_characters);
	RUN_TEST(test_ft_toupper_out_of_range);
	return (UNITY_END());
}
