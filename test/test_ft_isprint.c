#include "../src/libft.h"
#include "../unity/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ft_isprint_valid_chars(void)
{
    char start = 32;
    while (start <= 126)
    {
        TEST_ASSERT_TRUE(ft_isprint(start));
        start += 1;
    }
}

void test_ft_isprint_invalid_chars(void)
{
    char start = 1;
    while (start <= 31)
    {
        TEST_ASSERT_FALSE(ft_isprint(start));
        start += 1;
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_ft_isprint_valid_chars);
    RUN_TEST(test_ft_isprint_invalid_chars);
    return UNITY_END();
}
