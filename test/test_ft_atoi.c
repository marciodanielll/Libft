#include "../src/libft.h"
#include "../unity/unity.h"
#include <stdlib.h>

void	setUp(void) { }
void	tearDown(void) { }

void	test_ft_ft_atoi_positive_value(void)
{
	char	*positive_numbers[] = {"1", "2", "3", "4", "5", "10", "20", "50", "100", "200"};
	int		result[] = {1, 2, 3, 4, 5, 10, 20, 50, 100, 200};
	int		len_positive_numbers = sizeof(positive_numbers) / sizeof(positive_numbers[0]);
	int		len_result = sizeof(result) / sizeof(result[0]);

	while (len_positive_numbers-- && len_result--)
	{
		/* printf("Testing positive value: \"%s\"\nExpected: %d\nGot: %d\n%s\n\n",
				positive_numbers[len_positive_numbers], result[len_result],
				ft_atoi(positive_numbers[len_positive_numbers]),
				ft_atoi(positive_numbers[len_positive_numbers]) == result[len_result] ? "PASS" : "FAIL"); */
		TEST_ASSERT_EQUAL_INT(result[len_result], ft_atoi(positive_numbers[len_positive_numbers]));
	}
}

void	test_ft_ft_atoi_negative_value(void)
{
	char	*negative_numbers[] = {"-1", "-2", "-3", "-4", "-5", "-10", "-20", "-50", "-100", "-200"};
	int		result[] = {-1, -2, -3, -4, -5, -10, -20, -50, -100, -200};
	int		len_negative_numbers = sizeof(negative_numbers) / sizeof(negative_numbers[0]);
	int		len_result = sizeof(result) / sizeof(result[0]);

	while (len_negative_numbers-- && len_result--)
	{
		/* printf("Testing negative value: \"%s\"\nExpected: %d\nGot: %d\n%s\n\n",
				negative_numbers[len_negative_numbers], result[len_result],
				ft_atoi(negative_numbers[len_negative_numbers]),
				ft_atoi(negative_numbers[len_negative_numbers]) == result[len_result] ? "PASS" : "FAIL"); */
		TEST_ASSERT_EQUAL_INT(result[len_result], ft_atoi(negative_numbers[len_negative_numbers]));
	}
}

void	test_ft_ft_atoi_mixed_signs(void)
{
	char	*mixed_sign_numbers[] = {"--1", "++2", "--++3", "+++4", "-+5", "+-10", "++-20", "--50", "+-100", "-+200"};
	int		expected_result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		len_numbers = sizeof(mixed_sign_numbers) / sizeof(mixed_sign_numbers[0]);
	int		len_result = sizeof(expected_result) / sizeof(expected_result[0]);

	while (len_numbers-- && len_result--)
	{
		/* printf("Testing mixed signs: \"%s\"\nExpected: %d\nGot: %d\n%s\n\n",
				mixed_sign_numbers[len_numbers], expected_result[len_result],
				ft_atoi(mixed_sign_numbers[len_numbers]),
				ft_atoi(mixed_sign_numbers[len_numbers]) == expected_result[len_result] ? "PASS" : "FAIL"); */
		TEST_ASSERT_EQUAL_INT(expected_result[len_result], ft_atoi(mixed_sign_numbers[len_numbers]));
	}
}

void	test_ft_ft_atoi_mixed_signs_with_spaces(void)
{
	char	*mixed_sign_numbers_with_spaces[] = {"   --1", "   ++2", "   --++3", "   +++4", "   -+5", "   +-10", "   ++-20", "   --50", "   +-100", "   -+200"};
	int		expected_result[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		len_numbers = sizeof(mixed_sign_numbers_with_spaces) / sizeof(mixed_sign_numbers_with_spaces[0]);
	int		len_result = sizeof(expected_result) / sizeof(expected_result[0]);

	while (len_numbers-- && len_result--)
	{
		/* printf("Testing mixed signs with spaces: \"%s\"\nExpected: %d\nGot: %d\n%s\n\n",
				mixed_sign_numbers_with_spaces[len_numbers], expected_result[len_result],
				ft_atoi(mixed_sign_numbers_with_spaces[len_numbers]),
				ft_atoi(mixed_sign_numbers_with_spaces[len_numbers]) == expected_result[len_result] ? "PASS" : "FAIL"); */
		TEST_ASSERT_EQUAL_INT(expected_result[len_result], ft_atoi(mixed_sign_numbers_with_spaces[len_numbers]));
	}
}

void	test_ft_ft_atoi_edge_cases(void)
{
	int expected_results[] = {
		2147483647,  // Maior valor de int
		-2147483648, // Menor valor de int
		-2147483648, // Overflow positivo vira negativo
		123,         // Ignora espaços ao redor
		456,         // Sinal positivo é válido
		-789,        // Letras após número são ignoradas
		10,          // Caracteres especiais são ignorados
		123,         // Apenas o prefixo numérico é considerado
		0,           // String vazia retorna 0
		0,           // Apenas espaços retorna 0
		-1,          // Número muito grande retorna overflow
		0            // Número negativo muito grande retorna 0
	};

	char *edge_case_inputs[] = {
		"2147483647",            // Valor máximo de int
		"-2147483648",           // Valor mínimo de int
		"2147483648",            // Overflow positivo
		"   123 ",               // Espaços ao redor
		"   +456   ",            // Sinal positivo com espaços
		"   -789 abc",           // Letras após número
		"   10!@#",              // Caracteres especiais
		"123abc456",             // Letras no meio
		"",                      // String vazia
		"   ",                   // Apenas espaços
		"999999999999999999999", // Muito grande positivo
		"-999999999999999999999" // Muito grande negativo
	};

	int i = 0;
	int len_inputs = sizeof(edge_case_inputs) / sizeof(edge_case_inputs[0]);

	while (i < len_inputs)
	{
		int result = ft_atoi(edge_case_inputs[i]);
		/* printf("Testing edge case: \"%s\"\nExpected: %d\nGot: %d\n%s\n\n",
				edge_case_inputs[i], expected_results[i], result,
				result == expected_results[i] ? "PASS" : "FAIL"); */
		TEST_ASSERT_EQUAL_INT(expected_results[i], result);
		i++;
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_ft_atoi_positive_value);
	RUN_TEST(test_ft_ft_atoi_negative_value);
	RUN_TEST(test_ft_ft_atoi_mixed_signs);
	RUN_TEST(test_ft_ft_atoi_mixed_signs_with_spaces);
	RUN_TEST(test_ft_ft_atoi_edge_cases);
	return (UNITY_END());
}
