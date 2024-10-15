#include "../src/libft.h"
#include "../unity/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ft_strcpy_valid_strings(void)
{
    const char *testStrings[] = {
        "Marcio Daniel",
        "1234567890",
        "A",
        "C",
        "This is a test.",
        "", 
        "Longer string with spaces.",
        "Special characters: !@#$%^&*()"
    };
    
    char dest[100];
    int numTests = sizeof(testStrings) / sizeof(testStrings[0]);
    int i = 0;

    while (i < numTests)
    {
        ft_strcpy(dest, testStrings[i]);
        TEST_ASSERT_EQUAL_STRING(testStrings[i], dest);
        i++;
    }
}

void test_ft_strcpy_null_source(void)
{
    char dest[100];
    TEST_ASSERT_NULL(ft_strcpy(dest, NULL));
}

void test_ft_strcpy_null_destination(void)
{
    TEST_ASSERT_NULL(ft_strcpy(NULL, "Test"));
}

void test_ft_strcpy_empty_string(void)
{
    char dest[100];
    ft_strcpy(dest, "");
    TEST_ASSERT_EQUAL_STRING("", dest);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_ft_strcpy_valid_strings);
    RUN_TEST(test_ft_strcpy_null_source);
    RUN_TEST(test_ft_strcpy_null_destination);
    RUN_TEST(test_ft_strcpy_empty_string);
    return UNITY_END();
}
