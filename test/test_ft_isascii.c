#include "../src/libft.h"
#include "../unity/unity.h"

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft__(void)
{
	int	start;

	start = 0;
	while (start <= 127)
	{
		TEST_ASSERT_TRUE(ft_(start));
		start++;
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft__);
	return (UNITY_END());
}
