
# Function Documentation

## Menu

- [ft_atoi](#ft_atoi)
- [ft_toupper](#ft_toupper)
- [ft_strlcpy](#ft_strlcpy)

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
   - Skips any leadingft_strlcpy whitespace characters (such as spaces, tabs, or newlines).
   - Recognizes an optional '+' or '-' sign to determine the sign of the number.
   - Converts consecutive numeric characters (`'0'` to `'9'`) to an integer until a non-numeric character is encountered.
   - If the string does not contain valid numeric characters, the result will be `0`.

3. **Output:**  
   - Returns the integer value corresponding to the parsed numeric part of the string.
   - The sign of the number is determined by the presence of a '+' or '-' sign.
   - If the number exceeds the limits of `int`, behavior may vary depending on implementation (e.g., overflow may wrap around).

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

# ft_strlcpy

The `ft_strlcpy` function copies a string from the source (`src`) to the destination buffer (`dst`), ensuring that the destination buffer is null-terminated to prevent overflow. It copies at most `size - 1` characters, ensuring space for the null terminator. The function returns the total length of the source string (`src`), regardless of whether truncation occurred.

## Signature:
```c
size_t ft_strlcpy(char *dst, const char *src, size_t size);
```

## Business Rules:

### 1. Input Validation:
   - The function accepts three arguments:
     - `dst`: A pointer to the destination buffer where the string will be copied.
     - `src`: A pointer to the source string to be copied.
     - `size`: The total size of the destination buffer, including space for the null-terminator (`\0`).

### 2. Behavior:
   - Copies up to `size - 1` characters from the source string (`src`) to the destination buffer (`dst`), ensuring that the destination is null-terminated.
   - If `size` is 0, it does not copy any characters but still calculates the length of the source string (`src`).
   - If the source string is longer than `size - 1`, the string will be truncated in the destination buffer, but it will always be null-terminated.
   - The function does not allocate memory; it assumes that the caller has provided a valid destination buffer with the appropriate size.

### 3. Output:
   - The function returns the total length of the source string (`src`), which is the length the function would have tried to copy, regardless of truncation.
   - If the return value is greater than or equal to `size`, it means that truncation occurred.