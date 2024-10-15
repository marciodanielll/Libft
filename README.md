
# Function Documentation

## Menu

- [ft_atoi](#ft_atoi)
- [ft_toupper](#ft_toupper)

---

## ft_atoi

The `ft_atoi` function converts a string representing a number into its corresponding integer value. It processes the string, ignoring leading whitespaces and optional signs, until it encounters non-numeric characters.

### Signature:
```c
int ft_atoi(const char *str);
```

### Business Rules:
run_test
1. **Input Validation:**  
   - The function accepts a string `str` that should contain a sequence of characters representing a number.

2. **Behavior:**  
   - Skips any leading whitespace characters (such as spaces, tabs, or newlines).
   - Recognizes an optional '+' or '-' sign to determine the sign of the number.
   - Converts consecutive numeric characters (`'0'` to `'9'`) to an integer until a non-numeric character is encountered.
   - If the string does not contain valid numeric characters, the result will be `0`.

3. **Output:**  
   - Returns the integer value corresponding to the parsed numeric part of the string.
   - The sign of the number is determined by the presence of a '+' or '-' sign.
   - If the number exceeds the limits of `int`, behavior may vary depending on implementation (e.g., overflow may wrap around).

### Exceptions and Edge Cases:

1. **Non-numeric Characters:**  
   - If the string starts with non-numeric characters without any digits following, the function returns `0`.

2. **Whitespace Handling:**  
   - Any leading whitespaces are ignored until the first non-whitespace character is encountered.

3. **Sign Handling:**  
   - If both '+' and '-' appear before the number, only the first is considered valid.

4. **Overflow and Underflow:**  
   - If the parsed number exceeds the `int` limits (e.g., 2147483647 or -2147483648), the behavior may be undefined, often resulting in wrap-around values.

5. **Empty String:**  
   - If the input string is empty or contains only whitespaces, the function returns `0`.

---

## ft_toupper

The `ft_toupper` function converts a lowercase letter to its corresponding uppercase letter based on ASCII values. If the input is not a lowercase letter, the function returns the character unchanged.

### Signature:
```c
int ft_toupper(int c);
```

### Business Rules:

1. **Input Validation:**  
   - The function accepts an integer `c`, which should represent an ASCII value of a character.

2. **Behavior:**  
   - Converts a lowercase letter (from `'a'` to `'z'`, ASCII 97–122) to its uppercase version (from `'A'` to `'Z'`, ASCII 65–90).
   - If the input is not within the lowercase range, it returns the input as is.

3. **Output:**  
   - If the input is a lowercase letter, the function returns the corresponding uppercase letter's ASCII value.
   - If no conversion is needed, it returns the original input.

### Exceptions and Edge Cases:

1. **Non-alphabetic Characters:**  
   - If the input is a number, symbol, or any non-letter character, the function returns the input unchanged.

2. **Uppercase Letters:**  
   - If the input is already an uppercase letter, it is returned without modification.

3. **Non-ASCII Input:**  
   - If the input value is not within the ASCII range (e.g., extended UTF-8 characters), the behavior is undefined.

4. **Input Limits:**  
   - Negative values or values greater than 127 might cause unexpected behavior, and the caller is responsible for ensuring valid input.