#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft__(void)
{
	int		numbers[] = {1, 2, 3, 4, 5, 6, 7};
	int		len_number;
	char	str[50];

	len_number = sizeof(numbers) / sizeof(numbers[0]);
	while (len_number--)
	{
		memset(str, 'r', numbers[len_number]);
		str[numbers[len_number]] = '\0';
		TEST_ASSERT_EQUAL_INT(numbers[len_number], ft_strlen(str));
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft__);
	return (UNITY_END());
}
