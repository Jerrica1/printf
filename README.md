#Printf.
```` c
int printf ( const char * format, ... );
````
This is the first group project that we have at ALX, which consists of replication the **[printf (3)](http://man7.org/linux/man-pages/man3/printf.3.html)** function of language c, calling it this way **_printf.**

This function is part of the standard library **<cstdio>** and to use it we must specify the header file **<stdio.h>**.

Writes the C string pointed by format to the standard output **(stdout)**. If format includes format specifiers (subsequences beginning with **%**), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.
### Parameters
> **format** -> C string that contains the text to be written to stdout.

Where the specifier character at the end is the most significant component, since it defines the type and the interpretation of its corresponding argument:
Specifier | Output | Example
------------ | ------------ | ------------
c | Character | A
s | String of characters | ALX
% | A % followed by another % character will write a single % to the stream| %
i and d | Signed decimal integer | 98
b | Unsigned binary | 10101
u | Unsigned decimal integer | 98
o | Unsigned octal | 5523
x | Unsigned hexadecimal integer (lowercase) | 36264eb
X | Unsigned hexadecimal integer (uppercase) | 36264EB
r | Reversed string | gnirts |
R | Rot13 string | cevags
##### Return Value.
On **success**, the **total number** of characters written is returned.


