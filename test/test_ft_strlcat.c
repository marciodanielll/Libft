#include "../src/libft.h"
#include "../unity/unity.h"
#include <string.h>

void	setUp(void)
{
}
void	tearDown(void)
{
}

void	test_ft_strlcat_normal_case(void)
{
	char	dst[30] = "Buongiorno, ";
	char	src[] = "amore mio!";
	size_t	result;

	result = ft_strlcat(dst, src, 30);
	TEST_ASSERT_EQUAL_STRING("Buongiorno, amore mio!", dst);
	TEST_ASSERT_EQUAL_INT(strlen("Buongiorno, ") + strlen("amore mio!"),
		result);
}

void	test_ft_strlcat_no_space_to_concat(void)
{
	char	dst[15] = "Buongiorno";
	char	src[] = ", amore mio!";
	size_t	result;

	result = ft_strlcat(dst, src, 10);
	TEST_ASSERT_EQUAL_STRING("Buongiorno", dst);
	TEST_ASSERT_EQUAL_INT(10 + strlen(src), result);
}
void	test_ft_strlcat_exact_fit(void)
{
	char	dst[20] = "Buona";
	char	src[] = " giornata";
	size_t	result;

	result = ft_strlcat(dst, src, 20);
	TEST_ASSERT_EQUAL_STRING("Buona giornata", dst);
	TEST_ASSERT_EQUAL_INT(strlen("Buona giornata"), result);
}

void	test_ft_strlcat_empty_src(void)
{
	char	dst[15] = "Bella";
	char	src[] = "";
	size_t	result;

	result = ft_strlcat(dst, src, 15);
	TEST_ASSERT_EQUAL_STRING("Bella", dst);
	TEST_ASSERT_EQUAL_INT(strlen("Bella"), result);
}

void	test_ft_strlcat_empty_dst(void)
{
	char	dst[20] = "";
	char	src[] = "Vita bella";
	size_t	result;

	result = ft_strlcat(dst, src, 20);
	TEST_ASSERT_EQUAL_STRING("Vita bella", dst);
	TEST_ASSERT_EQUAL_INT(strlen("Vita bella"), result);
}

void	test_ft_strlcat_zero_size(void)
{
	char	dst[20] = "Vita";
	char	src[] = " meravigliosa";
	size_t	result;

	result = ft_strlcat(dst, src, 0);
	TEST_ASSERT_EQUAL_INT(strlen(src), result);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strlcat_normal_case);
	RUN_TEST(test_ft_strlcat_no_space_to_concat);
	RUN_TEST(test_ft_strlcat_exact_fit);
	RUN_TEST(test_ft_strlcat_empty_src);
	RUN_TEST(test_ft_strlcat_empty_dst);
	RUN_TEST(test_ft_strlcat_zero_size);
	return (UNITY_END());
}
